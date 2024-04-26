/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Common
*/

#ifndef RAYTRACER_CORE_COMMON_HPP_
    #define RAYTRACER_CORE_COMMON_HPP_

    #include <cstdint>

    #include "Vector.hpp"

namespace Raytracer::Core {
    struct Intersection {
        Intersection(float d, Vector p, Vector n, Vector refl, Vector refr)
            : distance(d), position(p), normal(n), reflection(refl), refraction(refr)
        {}

        const float distance;
        const Vector position, normal, reflection, refraction;
    };

    class Color {
        public:
            Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
                : r(red), g(green), b(blue)
            {}

            const std::uint8_t r, g, b;
    };

    class ColorShift {
        public:
            ColorShift(float red, float green, float blue, float alpha = 1.0f)
                : r(red), g(green), b(blue), a(alpha)
            {}

            ColorShift(const Color &color, float alpha = 1.0f)
                : r(color.r / 255.0f), g(color.g / 255.0f), b(color.b / 255.0f), a(alpha)
            {}

            const float r, g, b, a;
    };
}

#endif /* !RAYTRACER_CORE_COMMON_HPP_ */
