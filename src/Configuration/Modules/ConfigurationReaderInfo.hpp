/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ConfigurationReaderInfo
*/

#ifndef RAYTRACER_CONFIGURATION_MODULES_CONFIGURATIONREADERINFO_HPP_
    #define RAYTRACER_CONFIGURATION_MODULES_CONFIGURATIONREADERINFO_HPP_

    #include "../../Modules/ComponentInfo.hpp"

    #include "ConfigurationReaderFactory.hpp"

namespace Raytracer::Configuration::Modules {
    template<const char type[], std::derived_from<IConfigurationReader> T>
    class ConfigurationReaderInfo : public Raytracer::Modules::AComponentInfo<type, IConfigurationReader, IComponentConfiguration> {
        public:
            std::unique_ptr<Raytracer::Modules::IComponentFactory<IConfigurationReader, IComponentConfiguration>> createFactory() const final
            {
                return std::make_unique<ConfigurationReaderFactory<T>>();
            }
    };
}

#endif /* !RAYTRACER_CONFIGURATION_MODULES_CONFIGURATIONREADERINFO_HPP_ */
