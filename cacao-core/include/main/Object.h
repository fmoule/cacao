#ifndef CACAO_OBJECT_H
#define CACAO_OBJECT_H

#include <cstddef>
#include <typeinfo>
#include <type_traits>

#include "MainMacros.h"

using namespace std;

namespace cacao {

//    class String;
//    class Class;

    class Object {

    public:
        virtual ~Object();

        ///// Méthodes abstraites :
        virtual bool equals(const Object&) const = 0;
        virtual int hashCode() const = 0;
//        virtual String toString() const = 0;
        virtual Object* clone() const = 0;

        ///// Opérateurs :
        virtual bool operator == (const Object&) const;
        bool operator != (const Object&) const;

        ///// Méthodes générales :
//        Class getClass() const;
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
        bool isInstanceOf = std::is_base_of<T, U>::value;
        isInstanceOf = isInstanceOf || std::is_same<T, U>::value;
        return isInstanceOf;
    }

    /**
     * <p>
     * Méthode permettant de calculer pour tout pointeur
     * une clé de hachage.
     * </p>
     * @tparam U
     * @param obj
     * @return
     */
    template<typename U>
    int computeHashCode(const U* obj) {
        long code;
        if (obj == nullptr) {
            code = 0;
        } else if (instanceOf<Object>(obj)) {
            code = ((Object *) obj)->hashCode();
        } else {
            code = (long) obj;
        }
        return (int) code;
    }

    /**
     * Fonction utilitaire permettant de construire
     * un clone d'un objet.
     * @tparam T
     * @param obj
     * @return
     */
    template<typename T>
    T* buildClone(const T* obj) {
        return (obj == nullptr ? nullptr : new T(*obj));
    }

    template<typename T>
    T* buildCloneFromValue(const T val) {
        return new T(val);
    }

}

#endif
