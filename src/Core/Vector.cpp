/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Vector
*/

#include <cmath>

#include "Vector.hpp"

using namespace Raytracer::Core;

Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{}

Vector Vector::operator+(const Vector &other) const
{
    return Vector(x + other.x, y + other.y, z + other.z);
}

Vector Vector::operator-(const Vector &other) const
{
    return Vector(x - other.x, y - other.y, z - other.z);
}

Vector Vector::operator*(float scalar) const
{
    return Vector(x * scalar, y * scalar, z * scalar);
}

Vector Vector::operator/(float scalar) const
{
    return Vector(x / scalar, y / scalar, z / scalar);
}

Vector Vector::cross(const Vector &other) const
{
    return Vector(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

float Vector::dot(const Vector &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

float Vector::angle(const Vector &other) const
{
    return std::acos(dot(other) / (length() * other.length()));
}

float Vector::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Vector Vector::normalize() const
{
    return *this / length();
}

Vector Vector::reflect(const Vector &normal) const
{
    return *this - normal * 2.0f * dot(normal);
}

Vector Vector::refract(const Vector &normal, float eta) const
{
    float cosI = -dot(normal);
    float k = 1.0f - eta * eta * (1.0f - cosI * cosI);
    if (k < 0.0f) {
        return Vector(0.0f, 0.0f, 0.0f);
    }
    return *this * eta + normal * (eta * cosI - std::sqrt(k));
}

Vector Vector::translate(const Vector &translation) const
{
    return *this + translation;
}

Vector Vector::rotate(const Vector &rotation) const
{
    float xRad = rotation.x * M_PIf / 180.0f;
    float yRad = rotation.y * M_PIf / 180.0f;
    float zRad = rotation.z * M_PIf / 180.0f;

    float sinX = std::sin(xRad);
    float cosX = std::cos(xRad);
    float sinY = std::sin(yRad);
    float cosY = std::cos(yRad);
    float sinZ = std::sin(zRad);
    float cosZ = std::cos(zRad);

    float xNew = x * (cosY * cosZ) + y * (cosY * sinZ) - z * sinY;
    float yNew = x * (sinX * sinY * cosZ - cosX * sinZ) + y * (sinX * sinY * sinZ + cosX * cosZ) + z * sinX * cosY;
    float zNew = x * (cosX * sinY * cosZ + sinX * sinZ) + y * (cosX * sinY * sinZ - sinX * cosZ) + z * cosX * cosY;

    return Vector(xNew, yNew, zNew);
}

Vector Vector::scale(const Vector &scale) const
{
    return Vector(x * scale.x, y * scale.y, z * scale.z);
}

Vector Vector::transform(const Vector &translation, const Vector &rotation, const Vector &scale) const
{
    return this->translate(translation).rotate(rotation).scale(scale);
}
