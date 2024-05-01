/*
** EPITECH PROJECT, 2024
** MIRROR-RAYTRACER
** File description:
** Sphere
*/

#include "Sphere.hpp"

#include <cmath>

using namespace Raytracer::Primitives;

Sphere::Sphere(const Vector &center, float radius) : center(center), radius(radius)
{
}

Sphere::~Sphere()
{
}

bool Sphere::hit(const Ray &ray, float t_min, float t_max, hit_record &hitrecord)
{
    Vector oc = ray.origin() - center;
    float a = ray.direction().length_squared();;
    float b = oc.dot(ray.direction());
    float c = oc.length_squared() - radius * radius;
    float discriminant = b*b - a*c;

    if (discriminant < 0)
        return false;

    float sqrtd = std::sqrt(discriminant);

    float root = (b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (b + sqrtd) / a;
        if (root < t_min || t_max < root)
            return false;
    }

    hitrecord.t = root;
    hitrecord.p = ray.at(hitrecord.t);
    hitrecord.normal = (hitrecord.p - center) / radius;

    return true;
}