
/*!
 *
 * \file main.cpp
 * \brief Plik glowny programu
 */



// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h.in"
#include "solid.hh"
#include "cuboid.hh"
#include "drone.hh"
#include "example.h"
#include "vector3D.hh"
#include "matrix3D.hh"
#include "scene.hh"
#include "../inc/lacze_do_gnuplota.hh"

int main() {

    double tab2[3] = {0,0,80},   t[3] = {0,0,-80}, h[3] = {79, 80, 0},  angle, distance;
    Vector3D tr(tab2),  tr2(t), hor(h), obstacleScale, obstacleLocation, tmpDroneLocation;

    int droneNumber = 1, obstacle, obstacleNumber, tmpDroneNumber;

    char option = '0';

    PzG::LaczeDoGNUPlota  Link;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata
    Scene scene(&Link);

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
   
    PzG::InfoPlikuDoRysowania *body1Info = &Link.DodajNazwePliku("../datasets/body1.dat");
    body1Info->ZmienKolor(1);
    body1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor1_1Info = &Link.DodajNazwePliku("../datasets/rotor0_1.dat");
    rotor1_1Info->ZmienKolor(1);
    rotor1_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor2_1Info = &Link.DodajNazwePliku("../datasets/rotor1_1.dat");
    rotor2_1Info->ZmienKolor(1);
    rotor2_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor3_1Info = &Link.DodajNazwePliku("../datasets/rotor2_1.dat");
    rotor3_1Info->ZmienKolor(1);
    rotor3_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor4_1Info = &Link.DodajNazwePliku("../datasets/rotor3_1.dat");
    rotor4_1Info->ZmienKolor(1);
    rotor4_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor1_2Info = &Link.DodajNazwePliku("../datasets/rotor0_2.dat");
    rotor1_2Info->ZmienKolor(1);
    rotor1_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor2_2Info = &Link.DodajNazwePliku("../datasets/rotor1_2.dat");
    rotor2_2Info->ZmienKolor(1);
    rotor2_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor3_2Info = &Link.DodajNazwePliku("../datasets/rotor2_2.dat");
    rotor3_2Info->ZmienKolor(1);
    rotor3_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor4_2Info = &Link.DodajNazwePliku("../datasets/rotor3_2.dat");
    rotor4_2Info->ZmienKolor(1);
    rotor4_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *body2Info = &Link.DodajNazwePliku("../datasets/body2.dat");
    body2Info->ZmienKolor(1);
    body2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *bedInfo = &Link.DodajNazwePliku("../datasets/bed.dat");
    bedInfo->ZmienKolor(2);
    bedInfo->ZmienSzerokosc(1);
    
    
    
   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
    Link.ZmienTrybRys(PzG::TR_3D);

    Link.UstawZakresY(0,300);
    Link.UstawZakresX(0,300);
    Link.UstawZakresZ(0,300);


    scene.UseDrone(0)->SaveDrone(1);
    scene.UseDrone(1)->SaveDrone(2);

    double p1Scale[3] = {20,30,20}, p1Loc[3] = {150,50,0}, p2Scale[3] = {30,40,10}, p2Loc[3] = {100,100,0}, m1Scale[3] = {60,60,70}, m1Loc[3] = {150,150,0};
    double m2Scale[3] = {20,20,50}, m2Loc[3] = {190,190,0}, s1Scale[3] = {20,50,40}, s1Loc[3] = {25,140,0};

    Vector3D P1Scale(p1Scale), P1Loc(p1Loc), P2Scale(p2Scale), P2Loc(p2Loc), M1Scale(m1Scale), M1Loc(m1Loc), M2Loc(m2Loc), M2Scale(m2Scale), S1Scale(s1Scale), S1Loc(s1Loc);

    scene.AddObstacle(1,P1Scale, P1Loc);
    scene.AddObstacle(1,P2Scale, P2Loc);
    scene.AddObstacle(3,M1Scale, M1Loc);
    scene.AddObstacle(3,M2Scale, M2Loc);
    scene.AddObstacle(2,S1Scale, S1Loc);
    
    Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    try {
        while(option != 'k') { // Dopoki nie zostanie podane k

            std::cout << "Aktualna ilosc obiektow typu wektor3D: " << Vector3D::getActualVectorAmount() << std::endl;
            std::cout << "Laczna ilosc obiektow typu wektor3D: " << Vector3D::getAllVectorAmount() << std::endl;

            std::cout << "Nr aktywnego drona: " << droneNumber << " (" << scene.UseDrone(droneNumber-1)->Location()[0] << ", " << scene.UseDrone(droneNumber-1)->Location()[1] <<")" << std::endl;  

            if(option == '0') { 
            
                std::cout << "a - wybierz aktywnego drona" << std::endl;
                std::cout << "p - zadaj parametry przelotu" << std::endl;
                std::cout << "z - wykonaj zwiad" << std::endl;
                std::cout << "d - dodaj element powierzchni" << std::endl;
                std::cout << "u - usun element powierzhcni" << std::endl;
                std::cout << "m - wyswietl menu" << std::endl;
                std::cout << std::endl;
                std::cout << "k - koniec dzialania programu" << std::endl;
                
            }

            std::cout << "Twoj wybor: " << std::endl;
            std::cin >> option;

            switch(option) {
                case 'k':

                    option = 'k'; break;

                case 'p':

                    tmpDroneLocation = scene.UseDrone(droneNumber-1)->Location();
                    std::cout << "Podaj kierunek lotu (kat w stopniach)" << std::endl;
                    std::cin >> angle;
                    if(std::cin.fail()) {

                        std::cerr << "Niepoprawna wartosc kata!!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        break;

                    }
                    std::cout << "Podaj dlugosc lotu" << std::endl;
                    std::cin >> distance;
                    if(std::cin.fail() || distance < 0) {

                        std::cerr << "Niepoprawna dlugosc lotu!!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        break;

                    }

                    Link.DodajNazwePliku("../datasets/path.dat");
                    scene.UseDrone(droneNumber-1)->PlanPath(angle, distance, tmpDroneLocation);
                    std::cout << "Planuje sciezke..." << std::endl;
                    usleep(1000000);
                    Link.Rysuj();
                    
                    std::cout << "Wznoszenie..." << std::endl;
                    scene.UseDrone(droneNumber-1)->VerticalFlight(tr, Link, droneNumber);
                    std::cout << "Lot..." << std::endl;
                    scene.UseDrone(droneNumber-1)->HorizontalFlight(distance, angle, Link, droneNumber);
                    while(scene.CheckCollision(droneNumber-1)) {
                        
                        scene.UseDrone(droneNumber-1)->PlanPath(0, distance += 15, tmpDroneLocation);
                        std::cout << "Planuje sciezke..." << std::endl;
                        usleep(1000000);
                        Link.Rysuj();
                        scene.UseDrone(droneNumber-1)->HorizontalFlight(15, 0, Link, droneNumber);

                    }
                    scene.UseDrone(droneNumber-1)->VerticalFlight(tr2, Link, droneNumber);
                    std::cout << "Dron wyladowal..." << std::endl;

                    Link.UsunNazwePliku("../datasets/path.dat");
                    Link.Rysuj();

                    break;

                case 'm':

                    option = '0';

                    break;
                case 'a':

                    tmpDroneNumber = droneNumber;
                    std::cout << "1: " << " (" << scene.UseDrone(0)->Location()[0] << ", " << scene.UseDrone(0)->Location()[1] <<")" << std::endl;
                    std::cout << "2: " << " (" << scene.UseDrone(1)->Location()[0] << ", " << scene.UseDrone(1)->Location()[1] <<")" << std::endl;
                    std::cout << "Podaj numer drona" << std::endl;
                    std::cin >> droneNumber;
                    if(std::cin.fail()) {

                        droneNumber = tmpDroneNumber;
                        std::cerr << "Niepoprawny numer drona!!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        break;

                    }
                    else if(droneNumber > 2 || droneNumber < 1) {
                        
                        droneNumber = tmpDroneNumber;
                        std::cerr << "Nie ma drona o takim numerze!!!" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        break;

                    }
                    break;

                case 'z':

                    Link.DodajNazwePliku("../datasets/path.dat");
                    scene.UseDrone(droneNumber-1)->Recce(droneNumber, Link);
                    Link.UsunNazwePliku("../datasets/path.dat"); 
                    Link.Rysuj();
                    break;

                case 'd':

                    std::cout << "Podaj rodzaj przeszkody:" << std::endl;
                    std::cout << "1 - Plaskowyz" << std::endl;
                    std::cout << "2 - Zbocze" << std::endl;
                    std::cout << "3 - Gora" << std::endl;
                    std::cin >> obstacle;
                    if(obstacle > 3 || obstacle < 1) {

                        std::cerr << "Nie ma takiej bryly!!!" << std::endl;
                        break;

                    }
                    std::cout << "Podaj skale w osiach X Y Z" << std::endl;
                    std::cin >> obstacleScale;
                    if(obstacleScale[2] > 79) {

                        std::cerr << "Dron nie lata tak wysoko!!!" << std::endl;
                        break;

                    }
                    std::cout << "Podaj wspolrzedne srodka przeszkody X Y: " << std::endl;
                    std::cin >> obstacleLocation[0] >> obstacleLocation[1];
                    scene.AddObstacle(obstacle, obstacleScale, obstacleLocation);
                    Link.Rysuj();
                    break;

                case 'u':

                    try {

                        scene.PrintObstacles();
                        std::cout << "Podaj numer przeszkody" << std::endl;
                        std::cin >> obstacleNumber;
                        scene.DeleteObstacle(obstacleNumber);
                        Link.Rysuj();

                    }
                    catch(std::invalid_argument& a) {

                        std::cerr << "Blad: " << a.what() << "\n";

                    }

                    break;

                default:

                    option = '0';
                    std::cerr << "!!! NIEPOPRAWNA OPCJA !!!" << std::endl; 
                    break;

            }

        }

    }
    catch(std::runtime_error& e) {

        std::cerr << "Blad: " << e.what() << "\n";
        exit(1);

    }

    return 0;

}
