#include "slope.hh"

/*!
 *
 * \file slope.cpp
 * 
 * \brief Plik zawierajacy definicje metod klasy Slope
 */

Slope::Slope(Vector3D scale,int number) : SceneObject (number, "Zbocze") {

    Scale(scale);

}

Slope::~Slope() {

}

void Slope::SaveSlope(Vector3D loc) {

    (*this)[6] = (*this)[7];
    (*this)[4] = (*this)[5];

    ToGlobal(loc);

    Vector3D X, Y, tmp1 = (*this)(0), tmp2 = (*this)(7), tmp3 = (*this)(2), tmp4 = (*this)(5);

    std::ofstream  FileStream;

    ChangeFilename("slope" + std::to_string(GetNumber()) + ".dat");

    FileStream.open(GetFilename());
    if (!FileStream.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
        return;
    }

    X = (tmp1 + tmp2) / 2;
    Y = (tmp3 + tmp4) / 2;

    FileStream << X << std::endl << (*this)(7) << std::endl << (*this)(5) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(1) << std::endl << (*this)(3) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(0) << std::endl << (*this)(2) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(6) << std::endl << (*this)(4) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(7) << std::endl << (*this)(5) << std::endl << Y << std::endl << '#' << std::endl;

    FileStream.close();

}

std::string Slope::Filename() {

    return GetFilename();

}

Vector3D Slope::Location() const {

    return GetLocation();

}