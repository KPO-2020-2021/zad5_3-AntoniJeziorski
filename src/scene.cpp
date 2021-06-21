#include "scene.hh"

/*!
 *
 * \file scene.cpp
 * \brief Plik zawierajacy definicje metod klasy Scene
 */

Scene::Scene(PzG::LaczeDoGNUPlota *L) {

    double tab[3] = {10,8,6}, l1[3] = {20,20,3}, l2[3] = {50,20,3}, r[3] = {7,7,2};
    Vector3D v(tab), loc1(l1), loc2(l2), rot(r);
    std::shared_ptr<Drone> DronePtr1 = std::make_shared<Drone>(v,rot, loc1, 0);
    numberOfDrones++;
    listOfDrones.push_back(DronePtr1);
    listOfObjects.push_back(DronePtr1);
    std::shared_ptr<Drone> DronePtr2 = std::make_shared<Drone>(v,rot, loc2, 1);
    listOfDrones.push_back(DronePtr2);
    listOfObjects.push_back(DronePtr2);
    numberOfDrones++;

    numberOfObstacles = 0;

    Link = L;

}

Scene::~Scene() {

    for(std::shared_ptr<SceneObject> Obstacle : listOfObstacles) {

        remove(Obstacle->Filename().c_str());

    }

}

std::shared_ptr<Drone> Scene::UseDrone(int droneNumber) {

    std::list<std::shared_ptr<Drone>>::iterator droneIterator;

    for(droneIterator = listOfDrones.begin(); droneIterator != listOfDrones.end(); ++droneIterator) {

        if(droneNumber == (*droneIterator)->GetNumber()) {

            break;
            
        }

    }

    return *droneIterator;

}

void Scene::AddObstacle(int obstacle, Vector3D scale, Vector3D loc) {

    loc[2] = scale[2]/2;

    if(obstacle == 1) {

        std::shared_ptr<Plateau> ObstaclePtr = std::make_shared<Plateau>(scale, numberOfObstacles++);
        listOfObstacles.push_back(ObstaclePtr);
        listOfObjects.push_back(ObstaclePtr); 
        ObstaclePtr->SavePlateau(loc);
        (*Link).DodajNazwePliku((ObstaclePtr->GetFilename()).c_str());
       
    }

    if(obstacle == 2) {

        std::shared_ptr<Slope> ObstaclePtr = std::make_shared<Slope>(scale, numberOfObstacles++);
        listOfObstacles.push_back(ObstaclePtr);
        listOfObjects.push_back(ObstaclePtr); 
        ObstaclePtr->SaveSlope(loc);
        (*Link).DodajNazwePliku((ObstaclePtr->GetFilename()).c_str());
       
    }

    if(obstacle == 3) {

        std::shared_ptr<Mount> ObstaclePtr = std::make_shared<Mount>(scale, numberOfObstacles++);
        listOfObstacles.push_back(ObstaclePtr);
        listOfObjects.push_back(ObstaclePtr); 
        ObstaclePtr->SaveMount(loc);
        (*Link).DodajNazwePliku((ObstaclePtr->GetFilename()).c_str());
       
    }

}

void Scene::PrintObstacles() const {

    for(std::shared_ptr<SceneObject> Obstacle : listOfObstacles) {

        std::cout << Obstacle->GetNumber() << " - " << Obstacle->GetType() << " (" << Obstacle->Location()[0] << ", " << Obstacle->Location()[1] << ")" << std::endl;

    }

}

void Scene::DeleteObstacle(int number) {

    std::list<std::shared_ptr<SceneObject>>::iterator obstacleIterator;

    for(obstacleIterator = listOfObjects.begin() ; obstacleIterator != listOfObjects.end(); ++obstacleIterator) {

        if((*obstacleIterator)->GetNumber() == number && (*obstacleIterator)->GetType() != "dron") {

            (*Link).UsunNazwePliku((*obstacleIterator)->Filename().c_str());
            remove((*obstacleIterator)->Filename().c_str());
            listOfObstacles.remove((*obstacleIterator));
            listOfObjects.remove((*obstacleIterator));
            break;
            
        }

    }
    if(obstacleIterator == listOfObjects.end()) {

        throw(std::invalid_argument("Nie ma takiego obiektu!!!"));

    }

}

bool Scene::CheckCollision(int droneNumber) {

    std::list<std::shared_ptr<Drone>>::iterator droneIterator;

    for(droneIterator = listOfDrones.begin(); droneIterator != listOfDrones.end(); ++droneIterator) {

        if(droneNumber == (*droneIterator)->GetNumber()) 
            break;

    }

    for (std::shared_ptr<SceneObject> ObjectPtr : listOfObjects) {

        if((*droneIterator)->Collision(ObjectPtr)) {

            return true;

        }

    }
    
    return false;

}
