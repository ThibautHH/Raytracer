/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ILightConfiguration
*/

#ifndef RAYTRACER_LIGHTS_ILIGHTCONFIGURATION_HPP_
    #define RAYTRACER_LIGHTS_ILIGHTCONFIGURATION_HPP_

    #include "../Configuration/IComponentConfiguration.hpp"
    #include "../Core/Common.hpp"

namespace Raytracer::Lights {
    class ILightConfiguration : Configuration::IComponentConfiguration {
        public:
            virtual ~ILightConfiguration() = default;

            virtual Core::ColorShift getColor() const noexcept = 0;
    };
}

#endif /* !RAYTRACER_LIGHTS_ILIGHTCONFIGURATION_HPP_ */
