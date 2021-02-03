#ifndef MAINMACROS_H
#define MAINMACROS_H

/**
 * Macro permettant d'appeler le destructeur pour un pointeur
 * puis de le réinitialiser avec le pointeur NULL
 */
#define RELEASE(ptr)                              \
         if ((ptr) != NULL && (ptr) != nullptr) { \
            delete (ptr);                         \
            (ptr) = NULL;                         \
         }

#define RELEASE_WITH_VALUE(ptr, newValue)           \
        if ((ptr) != NULL && (ptr) != nullptr) {    \
            delete (ptr);                           \
        }                                           \
        (ptr) = newValue

#define RELEASE_TAB(ptr)                           \
        if ((ptr) != NULL && (ptr) != nullptr) {   \
            delete[] (ptr);                        \
            (ptr) = NULL;                          \
        }

#endif	/* MAINMACROS_H */

