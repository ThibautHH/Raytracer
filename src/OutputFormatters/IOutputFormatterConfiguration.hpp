/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IOutputFormatterConfiguration
*/

#ifndef RAYTRACER_OUTPUTFORMATTERS_IOUTPUTFORMATTERCONFIGURATION_HPP_
    #define RAYTRACER_OUTPUTFORMATTERS_IOUTPUTFORMATTERCONFIGURATION_HPP_

    #include "../Configuration/IComponentConfiguration.hpp"

namespace Raytracer::OutputFormatters {
    class IOutputFormatterConfiguration : Configuration::IComponentConfiguration {
        public:
            virtual ~IOutputFormatterConfiguration() = default;
    };
}

#endif /* !RAYTRACER_OUTPUTFORMATTERS_IOUTPUTFORMATTERCONFIGURATION_HPP_ */
