#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <algorithm>
#include <memory>
#include "vector3D.hh"

/*!
 *
 * \file scene_object.hh
 * 
 * \brief Plik zawierajacy definicje klasy SceneObject
 */

/*!
 *
 * \brief Definicja klasy SceneObject reprezentujaca obiekt na scenie
 */

class SceneObject {

    /*!
     *
     * \brief Pole typu std::string przetrzymujace typ obiektu
     */

    std::string objectType;

    /*!
     *
     * \brief Pole typu int przetrzymujace numer obiektu na scenie
     */

    int objectNumber;

    public:

        /*!
         *
         * \brief Konstruktor bezparametryczny klasy SceneObject
         */

        SceneObject();

        /*!
         *
         * \brief Konstruktor parametryczny klasy Scene object
         * 
         * \param number - numer na liscie obkietkow sceny
         * 
         * \param type - typ tworzonego obiektu
         */

        SceneObject(int number, const std::string type);

        /*!
         *
         * \brief Metoda zwracajaca numer obiektu na liscie
         * 
         * \return Numer obiektu na liscie jako stala
         */

        int GetNumber() const;

        /*!
         *
         * \brief Metoda zwracajaca typ obiektu
         * 
         * \return std::string bedacy typem obiektu jako stala
         */

        std::string GetType() const;

        /*!
         *
         * \brief Destruktor wirtualny klasy SceneObject
         */

        virtual ~SceneObject();

        /*!
         *
         * \brief Metoda wirtualna zwracajaca nazwe pliku obiektu
         * 
         * \return std::string bedacy nazwa pliku obiektu jako stala
         */

        virtual std::string Filename() = 0;

        /*!
         *
         * \brief Metoda wirtualna zwracajaca polozenie obiektu na scenie
         * 
         * \return Wektor reprezentujacy wspolrzedne srodka obiektu jako stala
         */

        virtual Vector3D Location() const = 0;

        /*!
         *
         * \brief Metoda sprawdzajaca kolizje obiektu sceny
         * 
         * \return true - jesli wykryto kolizje\n false - jesli nie wykryto kolizji
         */

        virtual bool Collision(std::shared_ptr<SceneObject> ObjectPtr) = 0;

        /*!
         *
         * \brief Metoda wirtualna zwracajaca skale obiektu sceny
         * 
         * \return Wektor reprezentujacy skale obiektu sceny
         */

        virtual Vector3D Get_Scale() = 0;

};