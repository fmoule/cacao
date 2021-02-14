#include "string/String.h"
#include "string/Char.h"

#include "numeric/NumUtils.h"

namespace cacao {

    ///// Constructeurs & destructeur

    String::String() {
        this->m_chars = new char[1];
        *(m_chars + 0) = '\000';
    }

    String::String(const int val) {
        bool isNegative = (val < 0);
        int nbDigits = getNbDigits(val);
        int beginIndex, endIndex, theVal;
        if (isNegative) {
            this->m_chars = new char[nbDigits + 2];
            m_chars[0] = '-';
            beginIndex = 1;
            endIndex = nbDigits;
            theVal = -val;
        } else {
            this->m_chars = new char[nbDigits + 1];
            beginIndex = 0;
            endIndex = nbDigits - 1;
            theVal = val;
        }
        for (int i = endIndex; i >= beginIndex; i--) {
            *(m_chars + i) = Char::DIGITS[(theVal % 10)];
            theVal = (theVal - (theVal % 10)) / 10;
        }
        *(m_chars + endIndex + 1) = '\000';
    }

    String::String(const long val) {
        bool isNegative = (val < 0);
        int nbDigits = getNbDigits(val);
        int beginIndex, endIndex;
        long theVal;
        if (isNegative) {
            this->m_chars = new char[nbDigits + 2];
            m_chars[0] = '-';
            beginIndex = 1;
            endIndex = nbDigits;
            theVal = -val;
        } else {
            this->m_chars = new char[nbDigits + 1];
            beginIndex = 0;
            endIndex = nbDigits - 1;
            theVal = val;
        }
        for (int i = endIndex; i >= beginIndex; i--) {
            *(m_chars + i) = Char::DIGITS[(theVal % 10)];
            theVal = (theVal - (theVal % 10)) / 10;
        }
        *(m_chars + endIndex + 1) = '\000';
    }

    String::String(const char* caracters) {
        if (caracters == nullptr) {
            this->m_chars = new char[0];
        }
        const int size = getStringSize(caracters);
        this->m_chars = new char[size + 1];
        for (int i = 0; i < size; i++) {
            this->m_chars[i] = *(caracters + i);
        }
        this->m_chars[size] = '\000';
    }

    String::String(const char caracter) {
        this->m_chars = new char[2];
        *(this->m_chars) = caracter;
        *(this->m_chars + 1) = '\000';
    }

    String::String(const String& str) {
        const int size = str.size();
        this->m_chars = new char[size + 1];
        for (int i = 0; i < size; i++) {
            this->m_chars[i] = str.getCharAt(i);
        }
        this->m_chars[size] = '\000';
    }

    String::~String() noexcept {
        RELEASE_TAB(this->m_chars);
    }

    ///// Définition des opérateurs :

    String& String::operator=(const String& str) {
        int size = str.size();
        char* pNewchars = new char[size + 1];
        for (int i = 0; i < size; i++) {
            pNewchars[i] = str.getCharAt(i);
        }
        pNewchars[size] = '\000';
        RELEASE_TAB(this->m_chars);
        this->m_chars = pNewchars;
        return *this;
    }

    String& String::operator=(const char* chars) {
        this->operator=(String(chars));
        return *this;
    }

    char String::operator[](const int index) const {
        return this->getCharAt(index);
    }

    String& String::operator+(const char* chars) {
        int oldLength = this->size();
        int length = getStringSize(chars);
        char* newChars = new char[oldLength + length + 1];
        for (int i = 0; i < oldLength; i++) {
            *(newChars + i) = *(this->m_chars + i);
        }
        for (int i = oldLength; i < oldLength + length; i++) {
            *(newChars + i) = *(chars + i - oldLength);
        }
        *(newChars + oldLength + length) = '\000';
        RELEASE_TAB(this->m_chars);
        this->m_chars = newChars;
        return *this;
    }

    String& String::operator+(const String& str) {
        char* pChars = str.getCharacters();
        this->operator+(pChars);
        RELEASE_TAB(pChars);
        return *this;
    }

    String& String::operator+(const char caracter) {
        char* pCharTab = new char[2];
        pCharTab[0] = caracter;
        pCharTab[1] = '\000';
        this->operator+(pCharTab);
        RELEASE_TAB(pCharTab);
        return *this;
    }

    ///// Définition des méthodes Object :

    bool String::equals(const Object& object) const {
        if (!instanceOf<String>(&object)) {
            return false;
        }
        const String* pThat = dynamic_cast<const String*>(&object);
        if (this->size() != pThat->size()) {
            return false;
        }
        for (int i = 0; i < this->size(); i++) {
            if (this->getCharAt(i) != pThat->getCharAt(i)) {
                return false;
            }
        }
        return true;
    }

    int String::hashCode() const {
        int code = 0;
        for (int i = 0; i < this->size(); i++) {
            code = (17 * code) + ((int) this->getCharAt(i));
        }
        return code;
    }

    String String::toString() const {
        return *this;
    }

    Object* String::clone() const {
        return new String(*this);
    }

    ///// Méthodes générales :

    int String::size() const {
        return getStringSize(this->m_chars);
    }

    char String::getCharAt(const int index) const {
        return this->m_chars[index];
    }

    ///// Getters & Setters :

    char* String::getCharacters() const noexcept {
        const int length = this->size();
        char* chars = new char[length + 1];
        for (int i = 0; i < length; i++) {
            *(chars + i) = m_chars[i];
        }
        *(chars + length) = '\000';
        return chars;
    }

    ////////////////////////
    ///// Méthodes générales
    ////////////////////////

    int getStringSize(const char* chars) {
        if (chars == nullptr) {
            return 0;
        }
        int i = 0;
        while (*(chars + i) != '\000') {
            i = i + 1;
        }
        return i;
    }
}
