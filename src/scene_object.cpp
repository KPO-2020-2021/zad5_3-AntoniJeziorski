#include <scene_object.hh>

/*!
 *
 * \file scene_object.cpp
 * 
 * \brief Plik zawierajacy definicje metod klasy SceneObject
 */

SceneObject::SceneObject() {
    
}

SceneObject::SceneObject(int number, const std::string type) {

    objectNumber = number;

    objectType = type;

}

int SceneObject::GetNumber() const {

    return objectNumber;

}

std::string SceneObject::GetType() const {

    return objectType;
    
}

SceneObject::~SceneObject() {

}
