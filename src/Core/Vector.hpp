/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vector
*/

#ifndef RAYTRACER_CORE_VECTOR_HPP_
    #define RAYTRACER_CORE_VECTOR_HPP_

namespace Raytracer::Core {
    struct Vector {
        Vector(float x, float y, float z);

        const float x, y, z;

        Vector operator+(const Vector &other) const;
        Vector operator-(const Vector &other) const;
        Vector operator*(float scalar) const;
        Vector operator/(float scalar) const;

        Vector cross(const Vector &other) const;
        float dot(const Vector &other) const;
        float angle(const Vector &other) const;

        float length() const;

        Vector normalize() const;

        Vector reflect(const Vector &normal) const;
        Vector refract(const Vector &normal, float eta) const;

        Vector translate(const Vector &translation) const;
        Vector rotate(const Vector &rotation) const;
        Vector scale(const Vector &scale) const;

        Vector transform(const Vector &translation, const Vector &rotation, const Vector &scale) const;
    };
}

#endif /* !RAYTRACER_CORE_VECTOR_HPP_ */
