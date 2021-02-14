#include "System.h"

using namespace std;

namespace cacao {

    /// Variables statiques ///
    System* System::instance = new System();

    /// Constructeur & Destructeur ///
    System::System() = default;
    System::~System() = default;

    /// Méthodes de la classe Object ///

    String System::toString() const {
        return "system";
    }

    int System::hashCode() const {
        return 0;
    }

    bool System::equals(const Object& obj) const {
        return (this == &obj);
    }

    Object* System::clone() const {
        return nullptr;
    }

    /// Méthodes statiques : ///

    System* System::getInstance() noexcept {
        return instance;
    }

}
