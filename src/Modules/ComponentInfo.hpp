/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ComponentInfo
*/

#ifndef RAYTRACCER_MODULES_COMPONENTINFO_HPP_
    #define RAYTRACCER_MODULES_COMPONENTINFO_HPP_

    #include <memory>
    #include <string_view>

    #include "IComponentFactory.hpp"

    #include "../Configuration/IConfigurationReader.hpp"
    #include "../Lights/ILight.hpp"
    #include "../Lights/ILightConfiguration.hpp"
    #include "../Primitives/IPrimitive.hpp"
    #include "../Primitives/IPrimitiveConfiguration.hpp"
    #include "../Materials/IMaterial.hpp"
    #include "../Materials/IMaterialConfiguration.hpp"
    #include "../OutputFormatters/IOutputFormatter.hpp"
    #include "../OutputFormatters/IOutputFormatterConfiguration.hpp"

namespace Raytracer::Modules {
    template<typename Component, typename Configuration>
    class IComponentInfo {
        public:
            typedef std::unique_ptr<IComponentFactory<Component, Configuration>> factory_ptr;

            virtual ~IComponentInfo() = default;

            virtual constexpr std::string_view getName() const noexcept = 0;
            virtual factory_ptr createFactory() const = 0;
    };

    template<const char type[], typename Component, typename Configuration>
    class AComponentInfo : public IComponentInfo<Component, Configuration> {
        public:
            constexpr std::string_view getName() const noexcept final { return type; }

        protected:
            AComponentInfo() = default;
    };

    typedef IComponentInfo<Configuration::IConfigurationReader, Configuration::IComponentConfiguration> IConfigurationReaderInfo;

    typedef IComponentInfo<Lights::ILight, Lights::ILightConfiguration> ILightInfo;
    typedef IComponentInfo<Primitives::IPrimitive, Primitives::IPrimitiveConfiguration> IPrimitiveInfo;
    typedef IComponentInfo<Materials::IMaterial, Materials::IMaterialConfiguration> IMaterialInfo;

    typedef IComponentInfo<OutputFormatters::IOutputFormatter, OutputFormatters::IOutputFormatterConfiguration> IOutputFormatterInfo;
}


#endif /* !RAYTRACCER_MODULES_COMPONENTINFO_HPP_ */
