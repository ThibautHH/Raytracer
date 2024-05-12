/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IMaterial
*/

#ifndef RAYTRACER_MATERIALS_IMATERIAL_HPP_
    #define RAYTRACER_MATERIALS_IMATERIAL_HPP_

    #include "../Core/Common.hpp"

namespace Raytracer::Materials {
    class IMaterial {
        public:
            ~IMaterial() = default;

            virtual void setReflection(float coefficient) = 0;
            virtual float getReflection() const noexcept = 0;

            virtual void setOpacity(float opacity) = 0;
            virtual float getOpacity() const noexcept = 0;

            [[nodiscard]]
            virtual Core::ColorShift getShift(const Core::Intersection &intersection) const noexcept = 0;
    };
}

#endif /* !RAYTRACER_MATERIALS_IMATERIAL_HPP_ */
