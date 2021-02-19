#include <functional>

#include "Object.h"

#include "string/String.h"

using namespace std;

namespace cacao {

    class FinallyClause : public virtual Object {
    private:
        function<void()> m_clause;

    public:

        /// Constructeurs :
        FinallyClause(const function<void()>) noexcept;
        FinallyClause(const FinallyClause&) noexcept;
        virtual ~FinallyClause() noexcept;

        /// Opérateurs :
        void operator=(const FinallyClause&) noexcept;

        /// Méthodes de la classe Object :
        bool equals(const Object& object) const override;
        int hashCode() const override;
        String toString() const override;
        Object* clone() const override;
    };


    class Exception : public virtual Object {
    private:
        String m_message;

    public:
        Exception() noexcept;
        Exception(const String&) noexcept;
        Exception(const Exception&) noexcept;
        virtual ~Exception() noexcept = default;

    public:
        void operator=(const Exception&) noexcept;
        bool equals(const Object& object) const override;
        int hashCode() const override;
        String toString() const override;
        Object* clone() const override;

        //// Getters & Setters :
    public:
        String getMessage();
    };

}

///// Définition des macros :
#define FINALLY(fct) FinallyClause finallyClause((fct))
