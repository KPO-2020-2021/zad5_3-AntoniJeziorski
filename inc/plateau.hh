#include <fstream>
#include "scene_object.hh"
#include "cuboid.hh"

/*!
 *
 * \file plateau.hh
 * 
 * \brief Plik zawierajacy definicje klasy Plateau
 */

/*!
 *
 * \brief Definicja klasy Plateau modelujaca plaskowyz w trojwymiarowym ukladzie wspolrzednych
 */ 

class Plateau : public SceneObject, public Cuboid {

    public:

        /*!
         *
         * \brief Konstruktor parametryczny klasu Plateau
         * 
         * \param scale - skala plaskowyzu
         * 
         * \param number - numer na liscie obiektow sceny
         * 
         */

        Plateau(Vector3D scale, int number);
        
        /*!
         *
         * \brief Destruktor klasu Plateau
         */

        ~Plateau();

        /*!
         *
         * \brief Metoda zapisujaca plaskowyz do pliku
         * 
         * \param loc - polozenie plaskowyzu
         */

        void SavePlateau(Vector3D loc);

        /*!
         *
         * \brief Metoda zwracajaca nazwe pliku plaskowyzu
         * 
         * \return Nazwa pliku jako std::string
         */

        std::string Filename() override final;

        /*!
         *
         * \brief Metoda zwracajaca polozenie plaskowyzu
         * 
         * \return wspolrzedne srodka plaskowyzu jako wektor
         */

        Vector3D Location() const override final;

        bool Collision(std::shared_ptr<SceneObject> ObjectPtr) override final{(void)ObjectPtr; return false;}  

        /*!
         *
         * \brief Metoda zwracajaca skale plaskowyzu
         * 
         * \return wektor reprezentujacy skale plaskowyzu
         */

        Vector3D Get_Scale() override final;

};