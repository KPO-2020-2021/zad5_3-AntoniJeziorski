#include "drone.hh"

/*!
 *
 * \file drone.cpp
 * \brief Plik zawierajace definicje metod klasy Drone
 */

Drone::Drone() {

}

Drone::~Drone() {

}

std::string Drone::Filename() {

    return body.GetFilename();

}

Drone::Drone(Vector3D& bodyScale, Vector3D& rotorScale, Vector3D& loc, int droneNumber) : SceneObject (droneNumber, "dron") {
    
    location = loc;
    body.Scale(bodyScale);
    body.ToGlobal(location);
    for(int i = 0; i < 4; ++i) {

        rotor[i].Scale(rotorScale);

    }
}

bool Drone::SaveBody(int droneNumber) {

    body.ToGlobal(location);

    Vector3D X, Y, tmp1 = body(0), tmp2 = body(7), tmp3 = body(2), tmp4 = body(5);

    std::ofstream  FileStream;

    std::string name =  body.filename + "body" + std::to_string(droneNumber) + ".dat";

    FileStream.open(name);
    if (!FileStream.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
    }

    X = (tmp1 + tmp2) / 2;
    Y = (tmp3 + tmp4) / 2;

    FileStream << X << std::endl << body(7) << std::endl << body(5) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(1) << std::endl << body(3) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(0) << std::endl << body(2) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(6) << std::endl << body(4) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(7) << std::endl << body(5) << std::endl << Y << std::endl << '#' << std::endl;

    FileStream.close();
    return !FileStream.fail();
}

void Drone::RotorToGlobal(int rotorNumber, Vector3D& Translation) {

    rotor[rotorNumber].ToCubeSystem(Translation);

    Matrix3D Rotation = RotationMatrix_Z(body.GetRotationAngle());

    for (int i = 0; i < 12; ++i) {
    
        rotor[rotorNumber][i] = Rotation * rotor[rotorNumber](i) + location;
    }

}

bool Drone::SaveRotor(int droneNumber, int rotorNumber, Vector3D& Translation) {

    RotorToGlobal(rotorNumber, Translation);

    Vector3D X, Y, tmp1 = rotor[rotorNumber][0], tmp2 = rotor[rotorNumber][7], tmp3 = rotor[rotorNumber][2], tmp4 = rotor[rotorNumber][8];

    std::ofstream  FileStream;

    std::string name = rotor[rotorNumber].filename + "rotor" + std::to_string(rotorNumber) + "_" + std::to_string(droneNumber) + ".dat";

    FileStream.open(name);
    if (!FileStream.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
    }

    X = (tmp1 + tmp2) / 2;
    Y = (tmp3 + tmp4) / 2;

    FileStream << X << std::endl << rotor[rotorNumber][0] << std::endl << rotor[rotorNumber][1] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << rotor[rotorNumber][2] << std::endl << rotor[rotorNumber][3] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << rotor[rotorNumber][4] << std::endl << rotor[rotorNumber][5] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << rotor[rotorNumber][6] << std::endl << rotor[rotorNumber][7] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << rotor[rotorNumber][8] << std::endl << rotor[rotorNumber][9] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << rotor[rotorNumber][10] << std::endl << rotor[rotorNumber][11] << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << rotor[rotorNumber][0] << std::endl << rotor[rotorNumber][1] << std::endl << Y << std::endl << '#' << std::endl;

    FileStream.close();
    return !FileStream.fail();
}

void Drone::SaveDrone(int droneNumber) {

    double v1[3] = {5,4,4}, v2[3] = {-5,4,4}, v3[3] = {-5,-4,4}, v4[3] = {5,-4,4};

    Vector3D vec1(v1), vec2(v2), vec3(v3), vec4(v4);

    SaveBody(droneNumber);

    SaveRotor(droneNumber, 0, vec1);

    SaveRotor(droneNumber, 1, vec2);

    SaveRotor(droneNumber, 2, vec3);

    SaveRotor(droneNumber, 3, vec4);
    
}

void Drone::VerticalFlight(Vector3D& translation, PzG::LaczeDoGNUPlota& Link, int droneNumber) {

    for (int i = 0; i < FLOPS; i++) {
    
        location = location + translation/FLOPS;
        if(translation[2] > 0) {
            rotor[0].Rotate(-5);
            rotor[1].Rotate(5);
            rotor[2].Rotate(-5);
            rotor[3].Rotate(5); 
        }
        else {
            rotor[0].Rotate(-1);
            rotor[1].Rotate(1);
            rotor[2].Rotate(-1);
            rotor[3].Rotate(1);
        }
        SaveDrone(droneNumber);
        
        Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(10000);

    }

}

void Drone::HorizontalFlight(double distance, double angle, PzG::LaczeDoGNUPlota& Link, int droneNumber) {

    Vector3D BodyCenter, tmp, end;

    end[0] = distance;

    BodyCenter = location;

    end = RotationMatrix_Z(rotationAngle) * end + BodyCenter;

    tmp = end - BodyCenter;
    tmp[2] = 0;

    for (int i = 0; i < FLOPS; ++i) {
        
        if(angle > 0) {
            rotor[0].Rotate(-4);
            rotor[1].Rotate(2.5);
            rotor[2].Rotate(-4);
            rotor[3].Rotate(2.5); 
        }
        else {
            rotor[0].Rotate(-2.5);
            rotor[1].Rotate(4);
            rotor[2].Rotate(-2.5);
            rotor[3].Rotate(4);
        }
        body.Rotate(angle/FLOPS);
        SaveDrone(droneNumber);
        Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(10000);

    }

    for (int i = 0; i < FLOPS; ++i) {

        location = location + tmp/FLOPS;
        rotor[0].Rotate(-4);
        rotor[1].Rotate(4);
        rotor[2].Rotate(-2.5);
        rotor[3].Rotate(2.5); 
        SaveDrone(droneNumber);
        Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(10000);

    }
} 

void Drone::PlanPath(double angle, double distance) {

    rotationAngle = rotationAngle + angle;

    std::ofstream FileStream;    
    FileStream.open("../datasets/path.dat");

    Vector3D tmp, BodyCenter;
    tmp[0] = distance;

    BodyCenter = location;

    FileStream << BodyCenter << std::endl;

    BodyCenter[2] += 80;

    FileStream << BodyCenter << std::endl;

    tmp = RotationMatrix_Z(rotationAngle) * tmp + BodyCenter;

    FileStream << tmp << std::endl;

    tmp[2] = tmp[2] - 80;

    FileStream << tmp << std::endl;

    FileStream.close();

}

void Drone::Recce(int droneNumber, PzG::LaczeDoGNUPlota& Link) {

    double k = sqrt((sqrt(2) + 2 )/ 2), u[3] = {0,0,80}, d[3] = {0,0,-80}, distance = 20 / k, tab[3] = {distance,0,0}, angle = 112.5;

    std::ofstream FileStream;    
    FileStream.open("../datasets/path.dat");

    Vector3D tmp, BodyCenter, tmp2(tab), up(u), down(d), tmp3;
    tmp[0] = 20;

    BodyCenter = location;
    FileStream << BodyCenter << std::endl;
    BodyCenter[2] += 80;
    FileStream << BodyCenter << std::endl;
    BodyCenter = RotationMatrix_Z(rotationAngle) * tmp + BodyCenter;
    FileStream << BodyCenter << std::endl;
    tmp3 = RotationMatrix_Z(angle + rotationAngle) * tmp2 + BodyCenter;
    FileStream << tmp3 << std::endl; 
    angle += 45;
    
    for(int i = 0; i < 7; ++i) {

        tmp3 = RotationMatrix_Z(angle + rotationAngle) * tmp2 + tmp3;
        FileStream << tmp3 << std::endl; 
        angle += 45;

    }

    FileStream.close();

    VerticalFlight(up, Link, droneNumber);
    HorizontalFlight(20, 0, Link, droneNumber);
    rotationAngle = rotationAngle + 112.5;
    HorizontalFlight(distance, 112.5, Link, droneNumber);
    for(int i = 0; i < 7; ++i) {

        rotationAngle = rotationAngle + 45;
        HorizontalFlight(distance, 45, Link, droneNumber);
        
    }
    rotationAngle = rotationAngle + 112.5;
    HorizontalFlight(20, 112.5, Link, droneNumber);
    VerticalFlight(down, Link, droneNumber);

}

HexPrism &Drone::operator [] (int index) {

    if (index < 0 || index >= 4) {
        throw std::runtime_error("Error:  Blad ilosci rotorow!");
    }
    return rotor[index];
}

Vector3D Drone::Location() const {

    return location;

}

double Drone::Radius() {

    Vector3D tmp = location;
    tmp[2] = 0;

    double r = sqrt(pow((body(0)[0] - tmp[0]),2)+pow((body(0)[1] - tmp[1]),2)+pow((body(0)[2] - tmp[2]),2)) + sqrt(1 + sqrt(2)*sqrt(pow(rotor[0][0][0] - rotor[0][3][0],2) + pow(rotor[0][0][1] - rotor[0][3][1],2) + pow(rotor[0][0][2] - rotor[0][3][2],2)) / 2);

    return r;

}

/* bool Drone::Collision(std::shared_ptr<SceneObject> ObjectPtr) const {

    if(ObjectPtr.get() == this) {
        return false;
    }


}  */
