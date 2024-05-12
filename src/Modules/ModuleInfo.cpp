/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ModuleInfo
*/

#include "ModuleInfo.hpp"

using namespace Raytracer::Modules;

const std::list<std::unique_ptr<IConfigurationReaderInfo>> &ModuleInfo::getConfigurationReaders() const noexcept
{
    return _configurationReaders;
}

const std::list<std::unique_ptr<ILightInfo>> &ModuleInfo::getLights() const noexcept
{
    return _lights;
}

const std::list<std::unique_ptr<IPrimitiveInfo>> &ModuleInfo::getPrimitives() const noexcept
{
    return _primitives;
}

const std::list<std::unique_ptr<IMaterialInfo>> &ModuleInfo::getMaterials() const noexcept
{
    return _materials;
}
