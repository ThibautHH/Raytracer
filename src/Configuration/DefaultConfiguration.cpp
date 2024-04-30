/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DefaultConfiguration
*/

#include "DefaultConfiguration.hpp"

using namespace Raytracer;
using namespace Raytracer::Configuration;

template<typename T, typename ... Types>
std::list<std::unique_ptr<T>> DefaultConfiguration::init(Types&& ... values)
{
    std::list<std::unique_ptr<T>> container;
    (container.emplace_back(std::forward<Types>(values)), ...);
    return container;
}

const Core::ColorShift &DefaultConfiguration::getBackground() const noexcept
{
    return _background;
}
const Core::Camera &DefaultConfiguration::getCamera() const noexcept
{
    return _camera;
}

const std::list<std::unique_ptr<Lights::ILight>> &DefaultConfiguration::getLights() const noexcept
{
    return _lights;
}

const std::list<std::unique_ptr<Primitives::IPrimitive>> &DefaultConfiguration::getPrimitives() const noexcept
{
    return _primitives;
}
