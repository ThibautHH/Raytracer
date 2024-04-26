/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AmbientLight
*/

#include "AmbientLight.hpp"

using namespace Raytracer;
using namespace Raytracer::Lights;

AmbientLight::AmbientLight(const Core::Color &color, float intensity)
    : _shift(color, intensity)
{
}

Core::ColorShift AmbientLight::getShift(const Core::Vector &, const Core::Vector &) const noexcept
{
    return _shift;
}
