/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** OutputFormatterFactory
*/

#ifndef RAYTRACER_OUTPUTFORMATTERS_MODULES_OUTPUTFORMATTERFACTORY_HPP_
    #define RAYTRACER_OUTPUTFORMATTERS_MODULES_OUTPUTFORMATTERFACTORY_HPP_

    #include "../../Modules/IComponentFactory.hpp"

    #include "../IOutputFormatter.hpp"
    #include "../IOutputFormatterConfiguration.hpp"

namespace Raytracer::OutputFormatters::Modules {
    template<std::derived_from<IOutputFormatter> T>
    class OutputFormatterFactory : public Raytracer::Modules::IComponentFactory<IOutputFormatter, IOutputFormatterConfiguration> {
        public:
            std::unique_ptr<IOutputFormatter> create(std::unique_ptr<const IOutputFormatterConfiguration> configuration) const final
            {
                return std::make_unique<T>(std::move(configuration));
            }
    };
}

#endif /* !RAYTRACER_OUTPUTFORMATTERS_MODULES_OUTPUTFORMATTERFACTORY_HPP_ */
