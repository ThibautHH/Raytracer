/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILight
*/

#ifndef RAYTRACER_LIGHTS_ILIGHT_HPP_
    #define RAYTRACER_LIGHTS_ILIGHT_HPP_

    #include "../Core/Common.hpp"

namespace Raytracer::Lights {
    class ILight {
        public:
            ~ILight() = default;

            virtual Core::ColorShift getShift(const Core::Vector &position, const Core::Vector &normal) const noexcept = 0;
    };
}

#endif /* !RAYTRACER_LIGHTS_ILIGHT_HPP_ */
