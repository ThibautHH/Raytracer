/*
** EPITECH PROJECT, 2024
** MIRROR-RAYTRACER
** File description:
** Sphere
*/

#include "Sphere.hpp"

using namespace Raytracer::Primitives;

Sphere::Sphere(const Vector &center, double radius) : center(center), radius(radius)
{
}

Sphere::~Sphere()
{
}
