#include "string/Char.h"
#include "string/String.h"

namespace cacao {

    ////// Statiques :
    char* Char::DIGITS = new char[10]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    ///// Constructeurs

    Char::Char(char caracter) {
        m_char = caracter;
    }

    Char::Char(const int value) {
        m_char = *(DIGITS + (value % 10));
    }

    Char::Char(const Char& theChar) {
        m_char = theChar.m_char;
    }

    ///// Opérateurs

    Char& Char::operator=(const Char& theChar) {
        m_char = theChar.m_char;
        return *this;
    }

    ///// Méthodes de la classe Object :

    bool Char::equals(const Object& obj) const {
        if (!instanceOf<Char>(&obj)) {
            return false;
        }
        const Char* pThat = dynamic_cast<const Char*>(&obj);
        return (m_char == pThat->m_char);
    }

    int Char::hashCode() const {
        return (int) m_char;
    }

    String Char::toString() const {
        return String(m_char);
    }

    Object* Char::clone() const {
        return new Char(m_char);
    }
}
