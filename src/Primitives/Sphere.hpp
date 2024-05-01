/*
** EPITECH PROJECT, 2024
** MIRROR-RAYTRACER
** File description:
** Sphere
*/

#ifndef RAYTRACER_PRIMITIVES_SPHERE_HPP_
    #define RAYTRACER_PRIMITIVES_SPHERE_HPP_

    #include "IPrimitive.hpp"

using namespace Raytracer::Core;

namespace Raytracer::Primitives {
    class hit_record {
        public:
            Vector p;
            Vector normal;
            float t;
    };

    class Sphere : public IPrimitive {
        public:
            Sphere(const Vector &center, float radius);
            ~Sphere();

            bool hit(const Ray &ray, float t_min, float t_max, hit_record &hitrecord);

        private:
            Vector center;
            float radius;

    };
}
#endif /* !RAYTRACER_PRIMITIVES_SPHERE_HPP_ */
