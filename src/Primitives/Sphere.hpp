/*
** EPITECH PROJECT, 2024
** MIRROR-RAYTRACER
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "IPrimitive.hpp"

using namespace Raytracer::Core;

namespace Raytracer::Primitives {
    class Sphere : public IPrimitive {
        public:
            Sphere(const Vector &center, double radius);
            ~Sphere();

        private:
            Vector center;
            double radius;

    };
}
#endif /* !SPHERE_HPP_ */
