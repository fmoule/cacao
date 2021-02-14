#ifndef CACAO_ARRAYLIST_H
#define CACAO_ARRAYLIST_H

#include "collection/list/List.h"

#include "string/String.h"

using namespace std;

namespace cacao {

    /////////////////////////
    ///// Définition générale
    /////////////////////////

    template<typename T>
    class ArrayList : public virtual List<T> {
    private:
        T* pElements;
        int length;

    public:
        ArrayList();
        ArrayList(const std::initializer_list<T>);
        virtual ~ArrayList();

    public:
        virtual void add(const T elt) noexcept;

    public:
        bool equals(const Object& object) const override;
        int hashCode() const override;
        String toString() const override;
        Object* clone() const override;

    public:
        int size() const noexcept override;
        bool contains(const T& elt) const noexcept override;
        T get(const int index) const override;

    };

    ///// Implémentations /////

    template<typename T>
    ArrayList<T>::ArrayList() {
        this->pElements = new T[0];
        this->length = 0;
    }

    template<typename T>
    ArrayList<T>::~ArrayList() {
        RELEASE_TAB(this->pElements);
    }

    template<typename T>
    ArrayList<T>::ArrayList(const initializer_list<T> initList) {
        length = initList.size();
        pElements = new T[this->length];
        const T* pElts = initList.begin();
        for (int i = 0; i < length; i++) {
            *(pElements + i) = *(pElts + i);
        }
    }

    ///// Méthodes de la classe Object

    template<typename T>
    bool ArrayList<T>::equals(const Object& object) const {
        if (!(instanceOf<ArrayList<T>>(&object))) {
            return false;
        }
        const ArrayList<T>* pThat = dynamic_cast<const ArrayList<T>*>(&object);
        bool areEquals = (this->size()) == (pThat->size());
        if (!areEquals) {
            return false;
        }
        for (int i = 0; i < this->size(); i++) {
            areEquals = areEquals && (*(pElements + i) == (pThat->get(i)));
        }
        return areEquals;
    }

    template<typename T>
    int ArrayList<T>::hashCode() const {
        int hashCode = 0;
        for (int i = 0; i < this->length; i++) {
            hashCode = (17 * hashCode) + ((long) (this->pElements + i));
        }
        return hashCode;
    }

    template<typename T>
    String ArrayList<T>::toString() const {
        return String("");
    }

    template<typename T>
    Object* ArrayList<T>::clone() const {
        ArrayList<T>* pCopie = new ArrayList<T>();
        for (int i = 0; i < this->size(); i++) {
            pCopie->add(this->get(i));
        }
        return pCopie;
    }

    ///// Méthodes de l'interface List

    template<typename T>
    int ArrayList<T>::size() const noexcept {
        return this->length;
    }

    template<typename T>
    bool ArrayList<T>::contains(const T& elt) const noexcept {
        for (int i = 0; i < this->size(); i++) {
            if (elt == *(pElements + i)) {
                return true;
            }
        }
        return false;
    }

    template<typename T>
    T ArrayList<T>::get(const int index) const {
        return *(this->pElements + index);
    }

    //// Fonctions générales :

    template<typename T>
    void ArrayList<T>::add(const T elt) noexcept {
        T* pNewElements = new T[length + 1];
        for (int i = 0; i < length; i++) {
            *(pNewElements + i) = *(this->pElements + i);
        }
        *(pNewElements + length) = elt;
        RELEASE_TAB(this->pElements);
        this->pElements = pNewElements;
        length = length + 1;
    }

    ////////////////////////////////
    ////// Définition pour pointeurs
    ////////////////////////////////

    template<typename T>
    class ArrayList<T*> : public virtual List<T*> {
    private:
        T** pElts;
        int capacity;
        int length;

    public:
        ArrayList();
        ArrayList(const std::initializer_list<T*>);
        virtual ~ArrayList();

    private:
        void resize() noexcept;

    public:
        void add(T* const) noexcept override;

    public:
        bool equals(const Object& object) const override;
        int hashCode() const override;
        String toString() const override;
        Object* clone() const override;

    public:
        int size() const noexcept override;
        bool contains(T* const& t) const noexcept override;
        T* get(const int index) const override;
    };

    ///// constructeurs et destructeur :

    template<typename T>
    ArrayList<T*>::ArrayList() {
        capacity = 10;
        length = 0;
        pElts = new T* [10];
        for (int i = 0; i < 10; i++) {
            *pElts = nullptr;
        }
    }

    template<typename T>
    ArrayList<T*>::~ArrayList() {
        for (int i = 0; i < this->length; i++) {
            RELEASE(*(this->pElts + i));
        }
        RELEASE_TAB(this->pElts);
    }

    ////// Méthodes privées :

    template<typename T>
    void ArrayList<T*>::resize() noexcept {
        T** pNewElts = new T* [2 * capacity];
        for (int i = 0; i < this->size(); i++) {
            *(pNewElts + i) = *(pElts + i);
        }
        RELEASE_TAB(this->pElts);
        pElts = pNewElts;
        capacity = 2 * capacity;
    }

    ///// Méthodes de la classe Object

    template<typename T>
    bool ArrayList<T*>::equals(const Object& object) const {
        if (!instanceOf<ArrayList<T*>>(&object)) {
            return false;
        }
        const ArrayList<T*>* pThat = dynamic_cast<const ArrayList<T*>*>(&object);
        if (this->size() != pThat->size()) {
            return false;
        }
        T* pT;
        T* pOriginT;
        for (int i = 0; i < this->size(); i++) {
            pOriginT = this->get(i);
            pT = pThat->get(i);
            if (pT == nullptr && pOriginT == nullptr) {
                continue;
            } else if (pT == nullptr || pOriginT == nullptr) {
                return false;
            } else if (*pT != *pOriginT) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    int ArrayList<T*>::hashCode() const {
        int code = 0;
        T* pT;
        for (int i = 0; i < this->size(); i++) {
            pT = this->get(i);
            code = (17 * code) + (pT == nullptr ? 0 : (long) pT);
        }
        return code;
    }

    template<typename T>
    String ArrayList<T*>::toString() const {
        return String("");
    }

    template<typename T>
    Object* ArrayList<T*>::clone() const {
        ArrayList<T*>* newList = new ArrayList<T*>();
        T* pElt;
        for (int i = 0; i < this->size(); i++) {
            pElt = this->get(i);
            if (pElt == nullptr) {
                newList->add(nullptr);
            } else {
                newList->add(new T(*pElt));
            }
        }
        return newList;
    }

    ///// Méthodes générales :

    template<typename T>
    T* ArrayList<T*>::get(const int index) const {
        return *(this->pElts + index);
    }

    template<typename T>
    bool ArrayList<T*>::contains(T* const& pElt) const noexcept {
        T* pT;
        for (int i = 0; this->size(); i++) {
            pT = *(pElts + i);
            if (pElt == nullptr && pT == nullptr) {
                return true;
            } else if (pElt == nullptr || pT == nullptr) {
                continue;
            } else if (*pElt == *pT) {
                return true;
            }
        }
        return false;
    }

    template<typename T>
    void ArrayList<T*>::add(T* const elt) noexcept {
        if ((length / capacity) > (2 / 3)) {
            this->resize();
        }
        *(this->pElts + length) = new T(*elt);
        length = length + 1;
    }

    template<typename T>
    int ArrayList<T*>::size() const noexcept {
        return this->length;
    }

}

#endif //CACAO_ARRAYLIST_H
