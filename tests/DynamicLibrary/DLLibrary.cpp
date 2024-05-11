/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DLLibrary tests
*/

#include <criterion/criterion.h>

#include "../../src/DynamicLibrary/DLLibrary.hpp"

static DynamicLibrary::DLLibraryFactory factory;

Test(DLLibraryFactory, loadEmptyLibrary)
{
    cr_assert_not_null(factory.loadLibrary("tests/data/lib/empty.so"));
}

Test(DLLibraryFactory, loadNonExistentLibrary)
{
    cr_assert_throw(factory.loadLibrary("tests/data/lib/no-library.so"), std::runtime_error);
}

Test(DLLibraryFactory, loadEmptyFile)
{
    cr_assert_throw(factory.loadLibrary("tests/data/empty"), std::runtime_error);
}

Test(DLLibraryFactory, loadNonLibrary)
{
    cr_assert_throw(factory.loadLibrary("tests/data/file"), std::runtime_error);
}

Test(DLLibrary, getNonExistentSymbol)
{
    auto library = factory.loadLibrary("tests/data/lib/empty.so");
    cr_assert_throw(library->getSymbol("non_existent_symbol"), std::runtime_error);
}

Test(DLLibrary, getSymbol)
{
    auto library = factory.loadLibrary("tests/data/lib/string.so");
    void *symbol = nullptr;
    cr_assert_none_throw(symbol = library->getSymbol("string"));
    cr_assert_not_null(symbol);
    cr_assert_str_eq(reinterpret_cast<const char *>(symbol), "Hello, World!");
}
