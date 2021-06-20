#include <fstream>
#include "scene_object.hh"
#include "cuboid.hh"

/*!
 *
 * \file slope.hh
 * 
 * \brief Plik zawierajacy definicje klasy Slope
 */

/*!
 *
 * \brief Definicja klasy Slope modelujaca zbocze w trojwymiarowym ukladzie wspolrzednych
 */ 

class Slope : public SceneObject, public Cuboid {

    public:

        /*!
         *
         * \brief Konstruktor parametryczny klasu Slope
         * 
         * \param scale - skala zbocza
         * 
         * \param number - numer na liscie obiektow sceny
         * 
         */

        Slope(Vector3D scale, int number);
        
        /*!
         *
         * \brief Destruktor klasu Slope
         */

        ~Slope();

        /*!
         *
         * \brief Metoda zapisujaca zbocze do pliku
         * 
         * \param loc - polozenie zbocza
         */

        void SaveSlope(Vector3D loc);

        /*!
         *
         * \brief Metoda zwracajaca nazwe pliku zbocza
         * 
         * \return Nazwa pliku jako std::string
         */

        std::string Filename() override final;

        /*!
         *
         * \brief Metoda zwracajaca polozenie zbocza
         * 
         * \return wspolrzedne srodka ostroslupa jako wektor
         */

        Vector3D Location() const override final;

        bool Collision(std::shared_ptr<SceneObject> ObjectPtr) override final{(void)ObjectPtr; return false;} 

        /*!
         *
         * \brief Metoda zwracajaca skale zbocza
         * 
         * \return wektor reprezentujacy skale zbocza
         */

        Vector3D Get_Scale() override final;

};