#ifndef SYSTEM_H
#define SYSTEM_H

#include "Object.h"

#include "string/String.h"

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
        int hashCode() const override;
        bool equals(const Object&) const override;
        Object* clone() const override;
        String toString() const override;

    public:
        static System* getInstance() noexcept;
    };


}

#endif
