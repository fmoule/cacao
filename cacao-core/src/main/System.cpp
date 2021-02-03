#include "System.h"

#include <cstddef>

using namespace std;

namespace cacao {

    /// Variables statiques ///

    System* System::instance = new System();   // Instance du singleton

    /// Constructeur & Destructeur ///

    System::System() {
        // EMPTY
    }

    System::~System() {
        // DO NOTHING !!
    }

    /// Méthodes de la classe Object ///

//    String System::toString() const {
//        return "system";
//    }

    int System::hashCode() const {
        return 0;
    }

    bool System::equals(const Object& obj) const {
        return (this == &obj);
    }

    Object* System::clone() const {
        return NULL;
    }


    /// Méthodes statiques : ///

    System* System::getInstance() throw() {
        return instance;
    }


    void System::killInstance() throw() {
        if (instance != NULL) {
            delete instance;
            instance = NULL;
        }
    }

}
