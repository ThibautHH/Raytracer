/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DynamicLibrary
*/

#ifndef DYNAMICLIBRARY_ILIBRARY_HPP_
    #define DYNAMICLIBRARY_ILIBRARY_HPP_

    #include <memory>

namespace DynamicLibrary {
    /**
     * @brief An interface for dynamic libraries
     */
    class ILibrary {
        public:
            /**
             * @brief Obtain a pointer to a symbol in the library
             *
             * @param name The name of the symbol to obtain
             * @return A pointer to the symbol
             */
            virtual void *getSymbol(const char *name) const = 0;
    };

    /**
     * @brief An interface for dynamic library factories
     */
    class ILibraryFactory {
        public:
            virtual ~ILibraryFactory() = default;

            /**
             * @brief Load a dynamic library
             *
             * @param path The path to the library to load
             * @return A pointer to the loaded library
             */
            virtual std::unique_ptr<ILibrary> loadLibrary(const char *path) const = 0;
    };
}

#endif /* !DYNAMICLIBRARY_ILIBRARY_HPP_ */
