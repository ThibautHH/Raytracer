/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** OutputFormatterInfo
*/

#ifndef RAYTRACER_OUTPUTFORMATTERS_MODULES_OUTPUTFORMATTERINFO_HPP_
    #define RAYTRACER_OUTPUTFORMATTERS_MODULES_OUTPUTFORMATTERINFO_HPP_

    #include "../../Modules/ComponentInfo.hpp"

    #include "OutputFormatterFactory.hpp"

namespace Raytracer::OutputFormatters::Modules {
    template<const char type[], std::derived_from<IOutputFormatter> T>
    class OutputFormatterInfo : public Raytracer::Modules::AComponentInfo<type, IOutputFormatter, IOutputFormatterConfiguration> {
        public:
            std::unique_ptr<Raytracer::Modules::IComponentFactory<IOutputFormatter, IOutputFormatterConfiguration>> createFactory() const final
            {
                return std::make_unique<OutputFormatterFactory<T>>();
            }
    };
}

#endif /* !RAYTRACER_OUTPUTFORMATTERS_MODULES_OUTPUTFORMATTERINFO_HPP_ */
