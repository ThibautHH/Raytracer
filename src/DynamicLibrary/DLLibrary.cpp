/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DLLibrary
*/

#include "DLLibrary.hpp"
#include <dlfcn.h>

using namespace DynamicLibrary;

template<typename T, typename ...Args>
T DLLibrary::dlexec(T (*f)(Args...), Args ...args)
{
    dlerror();
    T result = f(args...);
    const char * const error = dlerror();
    if (error)
        throw std::runtime_error(error);
    return result;
}

std::unique_ptr<ILibrary> DLLibraryFactory::loadLibrary(const char *path) const
{
    return std::make_unique<DLLibrary>(DLLibrary::handle_ptr(DLLibrary::dlexec(dlopen, path, RTLD_LAZY), dlclose));
}

DLLibrary::DLLibrary(handle_ptr handle)
    : _handle(std::move(handle))
{
}

void *DLLibrary::getSymbol(const char *name) const
{
    return dlexec(dlsym, _handle.get(), name);
}
