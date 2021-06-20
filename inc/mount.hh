#include <fstream>
#include "cuboid.hh"
#include "scene_object.hh"

/*!
 *
 * \file mount.hh
 * 
 * \brief Plik zawierajacy definicje klasy Mount
 */

/*!
 *
 * \brief Definicja klasy Mount modelujaca gore w trojwymiarowym ukladzie wspolrzednych
 */ 

class Mount : public SceneObject, public Cuboid {

    public:

        /*!
         *
         * \brief Konstruktor parametryczny klasu Mount
         * 
         * \param scale - skala gory
         * 
         * \param number - numer na liscie obiektow sceny
         * 
         */

        Mount(Vector3D scale, int number);
        
        /*!
         *
         * \brief Destruktor klasu Mount
         */

        ~Mount();

        /*!
         *
         * \brief Metoda zapisujaca gore do pliku
         * 
         * \param loc - polozenie gory
         */

        void SaveMount(Vector3D loc);

        /*!
         *
         * \brief Metoda zwracajaca nazwe pliku gory
         * 
         * \return Nazwa pliku jako std::string
         */

        std::string Filename() override final;

        /*!
         *
         * \brief Metoda zwracajaca polozenie gory
         * 
         * \return wspolrzedne srodka gory jako wektor
         */

        Vector3D Location() const override final;

        bool Collision(std::shared_ptr<SceneObject> ObjectPtr) override final{(void)ObjectPtr; return false;} 

        /*!
         *
         * \brief Metoda zwracajaca skale gory
         * 
         * \return wektor reprezentujacy skale gory
         */

        Vector3D Get_Scale() override final;

};