/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Module
*/

#include "Module.hpp"

using namespace Raytracer::Modules;

Module::Module(std::unique_ptr<const DynamicLibrary::ILibrary> library)
    : _library(std::move(library)),
    _moduleInfo(*static_cast<const ModuleInfo *>(_library->getSymbol(InfoSymbol)))
{
}
