/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DefaultConfiguration
*/

#ifndef RAYTRACER_CONFIGURATION_DEFAULTCONFIGURATION_HPP_
    #define RAYTRACER_CONFIGURATION_DEFAULTCONFIGURATION_HPP_

    #include <list>
    #include <memory>

    #include "../Core/Common.hpp"
    #include "../Core/Camera.hpp"

    #include "../Lights/AmbientLight.hpp"
    #include "../Primitives/IPrimitive.hpp"

    #include "IConfiguration.hpp"

namespace Raytracer::Configuration {
    class DefaultConfiguration : public IConfiguration {
        public:
            const Core::ColorShift &getBackground() const noexcept final;

            const Core::Camera &getCamera() const noexcept final;

            const std::list<std::unique_ptr<Primitives::IPrimitive>> &getPrimitives() const noexcept final;

            const std::list<std::unique_ptr<Lights::ILight>> &getLights() const noexcept final;

        private:
            const Core::ColorShift _background = Core::ColorShift(0.f, 0.f, 0.f);
            const Core::Camera _camera = Core::Camera(Core::Vector(0.f, 0.f, 10.f), Core::Vector(0.f, -0.5f, 0.f));
            const std::list<std::unique_ptr<Primitives::IPrimitive>> _primitives;
            const std::list<std::unique_ptr<Lights::ILight>> _lights = {
                std::make_unique<Lights::AmbientLight>(Core::Color(1.f, 1.f, 1.f), 0.5f)
            };
    };
}

#endif /* !RAYTRACER_CONFIGURATION_DEFAULTCONFIGURATION_HPP_ */
