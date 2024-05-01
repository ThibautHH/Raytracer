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

using namespace Raytracer::Core;

namespace Raytracer::Core {
    class Ray {
        public:
            Ray(Vector o, Vector d)
                : orig(o), dir(d) {}

            const Vector &origin() const { return orig; }
            const Vector &direction() const { return dir; }

            Vector at(double t) const { return orig + dir * t; }

        private:
            Vector orig, dir;
    };

    struct Intersection {
        Intersection(double d, Vector p, Vector n, Vector refl, Vector refr)
            : distance(d), position(p), normal(n), reflection(refl), refraction(refr)
        {}

        const double distance;
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
            ColorShift(double red, double green, double blue, double alpha = 1.0f)
                : r(red), g(green), b(blue), a(alpha)
            {}

            const double r, g, b, a;
    };
}

#endif /* !RAYTRACER_CORE_COMMON_HPP_ */
