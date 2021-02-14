#ifndef CACAO_CHAR_H
#define CACAO_CHAR_H

#include "Object.h"

namespace cacao {

    class Char : public virtual Object {
    private:
        char m_char;

    public:
        static char* DIGITS;

    public:
        Char(const char);
        Char(const int);
        Char(const Char&);
        ~Char() = default;

    public:
        Char& operator=(const Char&);

    public:
        virtual bool equals(const Object&) const;
        virtual int hashCode() const;
        virtual String toString() const;
        virtual Object* clone() const;
    };

}

#endif //CACAO_CHAR_H
