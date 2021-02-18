#ifndef CACAO_ITERATOR_H
#define CACAO_ITERATOR_H

#include "Object.h"

#include "string/String.h"

namespace cacao {

    template<typename T>
    class Iterator : public virtual Object {
    private:
        int index;
        const List<T>* pList;

    public:

        /// Constructeurs & Destructeur :
        Iterator(const List<T>*);
        Iterator(int, const List<T>*);
        Iterator(const Iterator<T>&);
        virtual ~Iterator() = default;

        /// operateur(s):
        virtual Iterator<T>& operator=(const Iterator<T>&);

        /// Méthode de la classe Object :
        bool equals(const Object& object) const override;
        int hashCode() const override;
        String toString() const override;
        Object* clone() const override;

        /// Méthode de l'interface Iterator :
        T operator*();
        Iterator<T>& operator++(int);
        Iterator<T>& operator++();
    };

    template<typename T>
    Iterator<T>::Iterator(const List<T>* pList) {
        this->pList = pList;
        this->index = 0;
    }

    template<typename T>
    Iterator<T>::Iterator(int index, const List<T>* pList) {
        this->pList = pList;
        this->index = index;
    }

    template<typename T>
    Iterator<T>::Iterator(const Iterator<T> &iterator) {
        this->pList = iterator.pList;
        this->index = iterator.index;
    }

    template<typename T>
    bool Iterator<T>::equals(const Object& object) const {
        if (!instanceOf<Iterator<T>>(&object)) {
            return false;
        }
        const Iterator<T>* pThat = dynamic_cast<const Iterator<T>*>(&object);
        bool areEquals = (this->index == pThat->index);
        areEquals = areEquals && (this->pList == pThat->pList);
        return areEquals;
    }

    template<typename T>
    int Iterator<T>::hashCode() const {
        int hashCode = this->index;
        hashCode = (17 * hashCode) + ((long) this->pList);
        return hashCode;
    }

    template<typename T>
    String Iterator<T>::toString() const {
        return String();
    }

    template<typename T>
    Object* Iterator<T>::clone() const {
        return new Iterator<T>(*this);
    }

    template<typename T>
    Iterator<T>& Iterator<T>::operator=(const Iterator<T>& iterator) {
        pList = iterator.pList;
        index = iterator.index;
        return *this;
    }

    template<typename T>
    T Iterator<T>::operator*() {
        return pList->get(index);
    }

    template<typename T>
    Iterator<T>& Iterator<T>::operator++(int i) {
        index = index + i;
        return *this;
    }

    template<typename T>
    Iterator<T>& Iterator<T>::operator++() {
        index++;
        return *this;
    }

}


#endif //CACAO_ITERATOR_H
