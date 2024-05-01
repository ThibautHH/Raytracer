/*
** EPITECH PROJECT, 2024
** MIRROR-RAYTRACER
** File description:
** Sphere
*/

#include "Sphere.hpp"

using namespace Raytracer::Primitives;

Sphere::Sphere(const Vector &center, float radius) : _center(center), _radius(radius) {}

Sphere::~Sphere() {}

bool Sphere::hit_sphere(const Vector &center, float radius, const Raytracer::Core::Ray &ray) {
    Vector oc = ray.origin() - center;
    float a = ray.direction().dot(ray.direction());
    float b = 2 * oc.dot(ray.direction());
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}

Vector Sphere::ray_color(const Ray &ray) {
    if (hit_sphere(Vector(0,0,-1), 0.5, ray))
        return Vector(1, 0, 0);
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