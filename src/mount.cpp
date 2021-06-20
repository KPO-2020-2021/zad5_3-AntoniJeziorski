#include "mount.hh"

/*!
 *
 * \file mount.cpp
 * 
 * \brief Plik zawierajacy definicje metod klasy Mount
 */

Mount::Mount(Vector3D scale,int number) : SceneObject (number, "Gora") {

    Scale(scale);

}

Mount::~Mount() {

}

void Mount::SaveMount(Vector3D loc) {

    Vector3D tmp;

    tmp = ((*this)[6] + (*this)[5]) / 2;

    (*this)[4] = tmp;
    (*this)[5] = tmp;
    (*this)[6] = tmp;
    (*this)[7] = tmp;

    ToGlobal(loc);

    Vector3D X, Y, tmp1 = (*this)(0), tmp2 = (*this)(7), tmp3 = (*this)(2), tmp4 = (*this)(5), tmp5, tmp6;

    std::ofstream  FileStream;

    ChangeFilename("mount" + std::to_string(GetNumber()) + ".dat");

    FileStream.open(GetFilename());
    if (!FileStream.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
    }

    tmp5 = ((*this)(0) + (*this)(1)) / 2;
    tmp6 = ((*this)(2) + (*this)(3)) / 2;

    X = (tmp5 + (*this)(6)) / 2;
    Y = (tmp6 + (*this)(6)) / 2;

    FileStream << X << std::endl << (*this)(7) << std::endl << (*this)(5) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(1) << std::endl << (*this)(3) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(0) << std::endl << (*this)(2) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(6) << std::endl << (*this)(4) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << (*this)(7) << std::endl << (*this)(5) << std::endl << Y << std::endl << '#' << std::endl;

    FileStream.close();

}

std::string Mount::Filename() {

    return GetFilename();

}

Vector3D Mount::Location() const {

    return GetLocation();

}