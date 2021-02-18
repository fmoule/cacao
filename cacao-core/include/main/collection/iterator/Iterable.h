#ifndef CACAO_ITERABLE_H
#define CACAO_ITERABLE_H

#include "Object.h"

#include "collection/iterator/Iterator.h"

namespace cacao {

    template<typename T>
    class Iterable : public virtual Object {

    public:
        virtual Iterator<T> begin() const = 0;
        virtual Iterator<T> end() const = 0;
    };

}
#endif //CACAO_ITERABLE_H
