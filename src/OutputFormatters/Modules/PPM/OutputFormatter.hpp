/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ConfigurationReader
*/

#ifndef RAYTRACER_OUTPUTFORMATTER_MODULES_PPM_OUTPUTFORMATTER_HPP_
    #define RAYTRACER_OUTPUTFORMATTER_MODULES_PPM_OUTPUTFORMATTER_HPP_

    #include <libconfig.h++>

    #include "../../../Utils/container_init.hpp"

    #include "../../../Modules/ModuleInfo.hpp"
    #include "../../IOutputFormatter.hpp"
    #include "../OutputFormatterInfo.hpp"

namespace Raytracer::OutputFormatters::Modules::PPM {
    class OutputFormatter : public IOutputFormatter {
        public:
            static constexpr const char type[] = "ppm";

            OutputFormatter(std::unique_ptr<const IOutputFormatterConfiguration> configuration);

            std::ostream &write(std::ostream &os, const std::vector<std::vector<Core::Color>> &framebuffer) const final;
    };

    extern "C" const Raytracer::Modules::ModuleInfo moduleInfo = Raytracer::Modules::ModuleInfo(
        std::list<std::unique_ptr<const Raytracer::Modules::IConfigurationReaderInfo>>(),
        std::list<std::unique_ptr<const Raytracer::Modules::ILightInfo>>(),
        std::list<std::unique_ptr<const Raytracer::Modules::IPrimitiveInfo>>(),
        std::list<std::unique_ptr<const Raytracer::Modules::IMaterialInfo>>(),
        Utils::container_init<std::list, std::unique_ptr<const Raytracer::Modules::IOutputFormatterInfo>>(
            std::make_unique<OutputFormatterInfo<OutputFormatter>>()
        )
    );
}

#endif /* !RAYTRACER_OUTPUTFORMATTER_PPMOUTPUTFORMATTER_HPP_ */
