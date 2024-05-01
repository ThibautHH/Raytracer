/*
** EPITECH PROJECT, 2024
** MIRROR-RAYTRACER
** File description:
** Sphere
*/

#ifndef RAYTRACER_PRIMITIVES_SPHERE_HPP_
    #define RAYTRACER_PRIMITIVES_SPHERE_HPP_

    #include "IPrimitive.hpp"

    #include <functional>

using namespace Raytracer::Core;

namespace Raytracer::Primitives {
    class Sphere : public IPrimitive {
        public:
            Sphere(const Vector &center, float radius);
            ~Sphere();

            Vector ray_color(const Ray &ray) override;

            float hit_sphere(const Vector &center, float radius, const Ray &ray);

            void setPosition(Vector vector) override;
            const Vector &getPosition() const noexcept override;

            void setRotation(Vector rotation) override;
            const Vector &getRotation() const noexcept override;

            void setScale(Vector scale) override;
            const Vector &getScale() const noexcept override;

            void setMaterial(std::unique_ptr<Materials::IMaterial> material) override;
            // std::optional<const Materials::IMaterial &> getMaterial() const noexcept override;

            // std::optional<std::pair<Core::Intersection, Core::ColorShift>> intersect(const Core::Vector &rayOrigin, const Core::Vector &rayDirection) const noexcept override;

        private:
            Vector _center;
            float _radius;

    };
}
#endif /* !RAYTRACER_PRIMITIVES_SPHERE_HPP_ */
