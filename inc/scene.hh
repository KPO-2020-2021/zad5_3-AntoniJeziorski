#include "drone.hh"
#include "plateau.hh"
#include "slope.hh"
#include "mount.hh"
#include "scene_object.hh"

/*!
 *
 * \file scene.hh
 * 
 * \brief Plik zawierajacy definicje klasy Scene
 */

/*!
 *
 * \brief Definicja klasy Scene reprezentujacej scene z dronami i przeszkodami
 */

class Scene {

    /*!
     *
     * \brief Pole typu std::list bedace lista wskaznikow na drony znajdujace sie na scenie
     */

    std::list<std::shared_ptr<Drone>> listOfDrones;

    /*!
     *
     * \brief Pole typu std::list bedace lista wskaznikow na wszystkie obiekty znajdujace sie na scenie
     */

    std::list<std::shared_ptr<SceneObject>> listOfObjects;

    /*!
     *
     * \brief Pole typu std::list bedace lista wskaznikow na przeszkody znajdujace sie na scenie
     */

    std::list<std::shared_ptr<SceneObject>> listOfObstacles;

    /*!
     *
     * \brief Pole typu *PzG::LaczeDOGNUPlota bedace wskanzikiem na lacze
     */

    PzG::LaczeDoGNUPlota *Link;

    /*!
     *
     * \brief Pole typu int przetrzymujace ilosc dronow na scenie
     */

    int numberOfDrones;

    /*!
     *
     * \brief Pole typu int przetrzymujace ilosc przeszkod na scenie
     */

    int numberOfObstacles;

    public:

        /*!
         *
         * \brief Konstruktor parametryczny klasy scena
         * 
         * \param L - wskaznik na uzywane w programie lacze
         */

        Scene(PzG::LaczeDoGNUPlota *L);

        /*!
         *
         * \brief Destruktor klasy scena\n Po zakonczeniu pracy programu usuwa pliki zawierajace wspolrzedne przeszkod
         */
        ~Scene();

        /*!
         *
         * \brief Metoda zwracajaca wskaznik na drona, ktorego chcemy uzyc
         * 
         * \param droneNumber - numer drona
         * 
         * \return Wskaznik na drona o zadanym numerze
         */

        std::shared_ptr<Drone> UseDrone(int droneNumber);

        /*!
         *
         * \brief Metoda sluzaca do dodawania przeszkody na scene o zadanej wielkosci w danym miejscu
         * 
         * \param obstacle - typ przeszkody jako numer
         * 
         * \param scale - zadana skala przeszkody
         * 
         * \param loc - zadane polozenie przeszkody
         */

        void AddObstacle(int obstacle, Vector3D scale, Vector3D loc);

        /*!
         *
         * \brief Metoda sluzaca do usuwania przeszkod ze sceny
         * 
         * \param number - numer przeszkody na liscie przeszkod
         */

        void DeleteObstacle(int number);

        /*!
         *
         * \brief Metoda sluzaca do wypisywania przeszkod na scenie
         */

        void PrintObstacles() const;

};


