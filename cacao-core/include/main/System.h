#ifndef SYSTEM_H
#define SYSTEM_H

#include "Object.h"

//#include "string/String.h"

namespace cacao {

/**
 * Classe représentant le système.
 */
    class System : public Object {

    private:
        static System* instance;

    private:
        System();
        ~System() override;

        /// Méthodes de la classe Object ///

    public:
        int hashCode() const;
        bool equals(const Object&) const;
        Object* clone() const;
//        String toString() const;

    public:
        static System* getInstance() throw();
        static void killInstance() throw();
    };


}

#endif
