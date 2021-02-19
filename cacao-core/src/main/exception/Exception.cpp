#include "exception/Exception.h"

#include "string/String.h"

namespace cacao {

    //////////////////////////
    ///// Classe FinallyClause
    //////////////////////////

    FinallyClause::FinallyClause(const function<void()> fct) noexcept {
        this->m_clause = fct;
    }

    FinallyClause::~FinallyClause() noexcept {
        m_clause();
    }

    FinallyClause::FinallyClause(const FinallyClause& clause) noexcept {
        this->m_clause = clause.m_clause;
    }

    ///// Opérateurs :

    void FinallyClause::operator=(const FinallyClause& finallyClause) noexcept {
        this->m_clause = finallyClause.m_clause;
    }

    ///// Méthodes de la classe Object :

    bool FinallyClause::equals(const Object& object) const {
        return false;
    }

    int FinallyClause::hashCode() const {
        return ((long) &m_clause);
    }

    String FinallyClause::toString() const {
        return String();
    }

    Object* FinallyClause::clone() const {
        return new FinallyClause(this->m_clause);
    }

    //////////////////////
    ///// Classe Exception
    //////////////////////

    Exception::Exception() noexcept {
        this->m_message = "";
    }

    Exception::Exception(const String& str) noexcept {
        this->m_message = str;
    }

    Exception::Exception(const Exception& excpt) noexcept {
        this->m_message = excpt.m_message;
    }

    ///// Définition des opérateurs :

    void Exception::operator=(const Exception& excpt) noexcept {
        this->m_message = excpt.m_message;
    }

    bool Exception::equals(const Object& object) const {
        if(!instanceOf<Exception>(&object)) {
            return false;
        }
        const Exception* pThat = dynamic_cast<const Exception*>(&object);
        return (m_message == pThat->m_message);
    }

    int Exception::hashCode() const {
        return m_message.hashCode();
    }

    String Exception::toString() const {
        return m_message;
    }

    Object* Exception::clone() const {
        return new Exception(m_message);
    }

    ///// Getters & Setters :

    String Exception::getMessage() {
        return m_message;
    }
}