/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DLLibrary
*/

#ifndef DYNAMICLIBRARY_DLLIBRARY_HPP_
    #define DYNAMICLIBRARY_DLLIBRARY_HPP_

    #include <dlfcn.h>
    #include <memory>

    #include "ILibrary.hpp"

namespace DynamicLibrary {
    /**
     * @brief A dynamic library loaded using libdl
     */
    class DLLibrary : public ILibrary {
        public:
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wignored-attributes"
            /**
             * @brief libdl handle to the loaded shared library
             *
             * @remark This pointer type automatically calls @ref dlclose "dlclose(void *)"
             * on the handle when the library object is destroyed
             */
            typedef std::unique_ptr<void, decltype(dlclose) *> handle_ptr;
#pragma GCC diagnostic pop

            /**
             * @brief Execute a libdl function and check for errors
             *
             * @tparam T The return type of the libdl function
             * @tparam Args The argument types of the libdl function
             * @param f The libdl function to execute
             * @param args The arguments to pass to the function
             * @return The result of the function call
             * @throw @ref std::runtime_error "std::runtime_error"
             * if the function call fails
             */
            template<typename T, typename ...Args>
            static T dlexec(T (*f)(Args...), Args... args);

            /**
             * @brief Construct a new DLLibrary object
             *
             * @param handle The libdl handle to the loaded shared library
             */
            DLLibrary(handle_ptr handle);

            void *getSymbol(const char *name) const final;

        private:
            const handle_ptr _handle;
    };

    /**
     * @brief A factory for creating @ref DLLibrary "DLLibrary" objects
     */
    class DLLibraryFactory : public ILibraryFactory {
        public:
            std::unique_ptr<ILibrary> loadLibrary(const char *path) const final;
    };
}

#endif /* !DYNAMICLIBRARY_DLLIBRARY_HPP_ */
