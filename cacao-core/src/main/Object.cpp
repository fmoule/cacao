#include "Object.h"

//#include "Class.h"

using namespace std;

namespace cacao {

    Object::~Object() {
        // EMPTY
    }

    ///// Définition des opérateurs : /////

    bool Object::operator==(const Object& obj) const {
        return this->equals(obj);
    }

    bool Object::operator!=(const Object& obj) const {
        return !(this->equals(obj));
    }

    ///// Méthodes de la classe Object : /////

//    Class Object::getClass() const {
//        const Object* pCopy = this->clone();
//        const Class theClass(pCopy);
//        RELEASE(pCopy);
//        return theClass;
//    }

}