/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IMaterialConfiguration
*/

#ifndef RAYTRACER_MATERIALS_IMATERIALCONFIGURATION_HPP_
    #define RAYTRACER_MATERIALS_IMATERIALCONFIGURATION_HPP_

    #include "../Configuration/IComponentConfiguration.hpp"

namespace Raytracer::Materials {
    class IMaterialConfiguration : Configuration::IComponentConfiguration {
        public:
            virtual ~IMaterialConfiguration() = default;
    };
}

#endif /* !RAYTRACER_MATERIALS_IMATERIALCONFIGURATION_HPP_ */
