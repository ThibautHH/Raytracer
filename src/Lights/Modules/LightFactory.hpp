/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LightFactory
*/

#ifndef RAYTRACER_LIGHTS_MODULES_LIGHTFACTORY_HPP_
    #define RAYTRACER_LIGHTS_MODULES_LIGHTFACTORY_HPP_

    #include "../../Modules/IComponentFactory.hpp"

    #include "../ILight.hpp"
    #include "../ILightConfiguration.hpp"

namespace Raytracer::Lights::Modules {
    template<std::derived_from<ILight> T>
    class LightFactory : public Raytracer::Modules::IComponentFactory<ILight, ILightConfiguration> {
        public:
            std::unique_ptr<ILight> create(std::unique_ptr<const ILightConfiguration> configuration) const final
            {
                return std::make_unique<T>(std::move(configuration));
            }
    };
}

#endif /* !RAYTRACER_LIGHTS_MODULES_LIGHTFACTORY_HPP_ */
