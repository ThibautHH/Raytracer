/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** LightInfo
*/

#ifndef RAYTRACER_LIGHTS_MODULES_LIGHTINFO_HPP_
    #define RAYTRACER_LIGHTS_MODULES_LIGHTINFO_HPP_

    #include "../../Modules/ComponentInfo.hpp"

    #include "LightFactory.hpp"

namespace Raytracer::Lights::Modules {
    template<std::derived_from<ILight> T>
    class LightInfo : public Raytracer::Modules::AComponentInfo<T::type, ILight, ILightConfiguration> {
        public:
            std::unique_ptr<Raytracer::Modules::IComponentFactory<ILight, ILightConfiguration>> createFactory() const final
            {
                return std::make_unique<LightFactory<T>>();
            }
    };
}

#endif /* !RAYTRACER_LIGHTS_MODULES_LIGHTINFO_HPP_ */
