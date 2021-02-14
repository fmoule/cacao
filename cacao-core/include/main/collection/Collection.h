#ifndef CACAO_COLLECTION_H
#define CACAO_COLLECTION_H

#include "Object.h"

namespace cacao {

    template<typename T>
    class Collection : public virtual Object {

    public:
        virtual int size() const noexcept = 0;
        virtual bool contains(const T&) const noexcept = 0;

    };
}

#endif //CACAO_COLLECTION_H
