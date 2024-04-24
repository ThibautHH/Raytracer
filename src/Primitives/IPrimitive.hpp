/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IPrimitive
*/

#ifndef RAYTRACER_PRIMITIVES_IPRIMITIVE_HPP_
    #define RAYTRACER_PRIMITIVES_IPRIMITIVE_HPP_

    #include <memory>
    #include <optional>

    #include "../Core/Common.hpp"
    #include "../Materials/IMaterial.hpp"

namespace Raytracer::Primitives {
    class IPrimitive {
        public:
            ~IPrimitive() = default;

            virtual void setPosition(Core::Vector vector) = 0;
            virtual const Core::Vector &getPosition() const noexcept = 0;

            virtual void setRotation(Core::Vector rotation) = 0;
            virtual const Core::Vector &getRotation() const noexcept = 0;

            virtual void setScale(Core::Vector scale) = 0;
            virtual const Core::Vector &getScale() const noexcept = 0;

            virtual void setMaterial(std::unique_ptr<Materials::IMaterial> material) = 0;
            virtual std::optional<const Materials::IMaterial &> getMaterial() const noexcept = 0;

            [[nodiscard]]
            virtual std::optional<std::pair<Core::Intersection, Core::ColorShift>> intersect(const Core::Vector &rayOrigin, const Core::Vector &rayDirection) const noexcept = 0;
    };
}

#endif /* !RAYTRACER_PRIMITIVES_IPRIMITIVE_HPP_ */
