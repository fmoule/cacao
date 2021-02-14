#ifndef CACAO_OBJECT_H
#define CACAO_OBJECT_H

#include <cstddef>
#include <typeinfo>
#include <type_traits>

#include "MainMacros.h"

using namespace std;

namespace cacao {

    class String;
//    class Class;

    class Object {

    public:
        virtual ~Object();

        ///// Méthodes abstraites :
        virtual bool equals(const Object&) const = 0;
        virtual int hashCode() const = 0;
        virtual String toString() const = 0;
        virtual Object* clone() const = 0;

        ///// Opérateurs :
        virtual bool operator==(const Object&) const;
        bool operator!=(const Object&) const;
    };

    ///// Défintion des fonctions générales :

    /**
     * Méthode permettant de savoir si un objet
     *
     * @param obj
     * @return
     */
    template<typename T, typename U>
    bool instanceOf(const U* obj) {
        if (obj == nullptr) {
            return false;
        }
        return (dynamic_cast<const T*>(obj) != nullptr);
    }

}

#endif
