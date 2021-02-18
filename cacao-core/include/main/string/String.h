#ifndef CACAO_STRING_H
#define CACAO_STRING_H

#include "Object.h"

namespace cacao {

    class String : public virtual Object {
    private:
        char* m_chars;

    public:
        String();
        String(const char*);
        String(const char);
        String(const int);
        String(const long);
        String(const String&);
        virtual ~String() noexcept;

    public:
        String& operator=(const String&);
        String& operator=(const char*);
        String& operator+(const char*);
        String& operator+(const char);
        String& operator+(const String&);
        char operator[](const int) const;

    public:
        virtual bool equals(const Object& object) const override;
        virtual int hashCode() const override;
        virtual Object* clone() const override;
        virtual String toString() const override;

    public:
        int size() const;
        char getCharAt(const int) const;

    public:
        char* toChars() const noexcept;
    };

    ///////////////////////////
    ///// Méthodes générales :
    ///////////////////////////

    int getStringSize(const char*);
}

#endif
