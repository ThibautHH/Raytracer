/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ConfigurationReaderFactory
*/

#ifndef RAYTRACER_CONFIGURATION_MODULES_CONFIGURATIONREADERFACTORY_HPP_
    #define RAYTRACER_CONFIGURATION_MODULES_CONFIGURATIONREADERFACTORY_HPP_

    #include "../../Modules/IComponentFactory.hpp"
    #include "../IConfigurationReader.hpp"

namespace Raytracer::Configuration::Modules {
    template<std::derived_from<IConfigurationReader> T>
    class ConfigurationReaderFactory : public Raytracer::Modules::IComponentFactory<IConfigurationReader, IComponentConfiguration> {
        public:
            std::unique_ptr<IConfigurationReader> create(std::unique_ptr<const IComponentConfiguration> configuration) const final
            {
                return std::make_unique<T>(std::move(configuration));
            }
    };
}

#endif /* !RAYTRACER_CONFIGURATION_MODULES_CONFIGURATIONREADERFACTORY_HPP_ */
