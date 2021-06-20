#include "../tests/doctest/doctest.h"
#include "solid.hh"

TEST_CASE("test konstruktora klasy solid") {

    Solid test;

    CHECK((test.scaleVector[0] == 1 && test.scaleVector[1] == 1 && test.scaleVector[2] == 1 && test.filename == "../datasets/"));

}

TEST_CASE("test metody Scale") {

    double tab[3] = {2,3,4};
    Vector3D v(tab);
    Solid test;
    test.Scale(v);

    CHECK((test.scaleVector[0] == 2 && test.scaleVector[1] == 3 && test.scaleVector[2] == 4));

}

TEST_CASE("test metody GetFilename") {

    Solid test;

    CHECK((test.GetFilename() == "../datasets/"));

}

TEST_CASE("test metody ChangeFilename") {

    Solid test;
    std::string name = "123";
    test.ChangeFilename(name);

    CHECK((test.GetFilename() == "../datasets/123"));

}
