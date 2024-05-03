/*
** EPITECH PROJECT, 2024
** MIRROR-RAYTRACER
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "../Core/Vector.hpp"

#include <cmath>

using namespace Raytracer::Primitives;

Sphere::Sphere(const Vector &center, float radius) : _center(center), _radius(radius) {}

Sphere::~Sphere() {}

float Sphere::hit_sphere(const Vector &center, float radius, const Raytracer::Core::Ray &ray) {
    Vector oc = ray.origin() - center;
    float a = ray.direction().length_squared();
    float b = oc.dot(ray.direction());
    float c = oc.length_squared() - radius * radius;
    float discriminant = b*b - a*c;

    if (discriminant < 0)
        return -1;
    else
        return (b - std::sqrt(discriminant)) / a;
}

Vector Sphere::ray_color(const Ray &ray) {
    float t = hit_sphere(Vector(0,0,-1), 0.5, ray);
    if (t > 0) {
        Vector N = N.unit_vector((ray.at(t) - Vector(0, 0, -1)));
        return Vector(N._x() + 1, N._y() + 1, N._z() + 1) * 0.5;
    }
    
    return Vector(1.0, 1.0, 1.0);
}

void Sphere::setPosition(Vector vector) {
    _center = vector;
}

const Vector &Sphere::getPosition() const noexcept {
    return _center;
}

void Sphere::setRotation(Vector rotation) {
    (void)rotation;
}

const Vector &Sphere::getRotation() const noexcept {
    return _center;
}

void Sphere::setScale(Vector scale) {
    (void)scale;
}

const Vector &Sphere::getScale() const noexcept {
    return _center;
}

void Sphere::setMaterial(std::unique_ptr<Materials::IMaterial> material) {
    (void)material;
}

// std::optional<std::reference_wrapper<const Raytracer::Materials::IMaterial>> Sphere::getMaterial() const noexcept {
//     return std::optional<std::reference_wrapper<const Raytracer::Materials::IMaterial>>();
// }



// std::optional<std::pair<Raytracer::Core::Intersection, Raytracer::Core::ColorShift>> Sphere::intersect(const Raytracer::Core::Vector &rayOrigin, const Raytracer::Core::Vector &rayDirection) noexcept {
//     (void)rayOrigin;
//     (void)rayDirection;
//     return std::optional<std::pair<Raytracer::Core::Intersection, Raytracer::Core::ColorShift>>();
// }