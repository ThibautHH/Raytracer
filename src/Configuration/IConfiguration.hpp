/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IConfiguration
*/

#ifndef RAYTRACER_CONFIGURATION_ICONFIGURATION_HPP_
    #define RAYTRACER_CONFIGURATION_ICONFIGURATION_HPP_

    #include <list>
    #include <memory>

    #include "../Core/Common.hpp"
    #include "../Core/Camera.hpp"

    #include "../Lights/ILightConfiguration.hpp"
    #include "../Primitives/IPrimitiveConfiguration.hpp"

namespace Raytracer::Configuration {
    class IConfiguration {
        public:
            virtual ~IConfiguration() = default;

            virtual const Core::ColorShift &getBackground() const noexcept = 0;

            virtual const Core::Camera &getCamera() const noexcept = 0;

            virtual const std::list<std::unique_ptr<Primitives::IPrimitiveConfiguration>> &getPrimitives() const noexcept = 0;

            virtual const std::list<std::unique_ptr<Lights::ILightConfiguration>> &getLights() const noexcept = 0;
    };
}

#endif /* !RAYTRACER_CONFIGURATION_ICONFIGURATION_HPP_ */
