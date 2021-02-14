#ifndef CACAO_LIST_H
#define CACAO_LIST_H

#include "collection/Collection.h"

namespace cacao {

    template<typename T>
    class List : public virtual Collection<T> {

    public:
        virtual T get(const int) const = 0;
        virtual void add(const T) noexcept = 0;
    };

}
#endif //CACAO_LIST_H
