/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ModuleInfo
*/

#ifndef RAYTRACCER_MODULES_MODULEINFO_HPP_
    #define RAYTRACCER_MODULES_MODULEINFO_HPP_

    #include <algorithm>
    #include <functional>
    #include <list>
    #include <memory>

    #include "ComponentInfo.hpp"

namespace Raytracer::Modules {
    /**
     * @brief Compound class that holds all the information about a module
     *
     * @remark This class is intended to be the exposed global variable symbol
     * with the name "moduleIinfo" in a module's shared library
     */
    class ModuleInfo {
        public:
            template<std::same_as<std::list<std::unique_ptr<const IConfigurationReaderInfo>>> ConfigurationReaderInfos,
                std::same_as<std::list<std::unique_ptr<const ILightInfo>>> LightInfos,
                std::same_as<std::list<std::unique_ptr<const IPrimitiveInfo>>> PrimitiveInfos,
                std::same_as<std::list<std::unique_ptr<const IMaterialInfo>>> MaterialInfos,
                std::same_as<std::list<std::unique_ptr<const IOutputFormatterInfo>>> OutputFormatterInfos>
            ModuleInfo(ConfigurationReaderInfos &&configurationReaders,
                LightInfos &&lights, PrimitiveInfos &&primitives, MaterialInfos &&materials,
                OutputFormatterInfos &&outputFormatters)
                : _configurationReaders(std::forward<ConfigurationReaderInfos>(configurationReaders)),
                _lights(std::forward<LightInfos>(lights)),
                _primitives(std::forward<PrimitiveInfos>(primitives)),
                _materials(std::forward<MaterialInfos>(materials)),
                _outputFormatters(std::forward<OutputFormatterInfos>(outputFormatters))
            {}

            template<typename ComponentInfo>
            std::optional<std::reference_wrapper<const ComponentInfo>> tryGetComponentInfo(std::string_view componentType) const
            {
                const auto &list = getComponentInfos<ComponentInfo>();
                auto it = std::find_if(list.cbegin(), list.cend(), [componentType](const auto &info) {
                    return info->getName() == componentType;
                });
                return it != list.cend()
                    ? std::optional<std::reference_wrapper<const ComponentInfo>>(std::ref(**it))
                    : std::nullopt;
            }

        private:
            template<std::same_as<IConfigurationReaderInfo> ComponentInfo>
            constexpr const std::list<std::unique_ptr<const ComponentInfo>> &getComponentInfos() const noexcept
            { return _configurationReaders; }
            const std::list<std::unique_ptr<const IConfigurationReaderInfo>> _configurationReaders;

            template<std::same_as<ILightInfo> ComponentInfo>
            constexpr const std::list<std::unique_ptr<const ComponentInfo>> &getComponentInfos() const noexcept
            { return _lights; }
            const std::list<std::unique_ptr<const ILightInfo>> _lights;
            template<std::same_as<IPrimitiveInfo> ComponentInfo>
            constexpr const std::list<std::unique_ptr<const ComponentInfo>> &getComponentInfos() const noexcept
            { return _primitives; }
            const std::list<std::unique_ptr<const IPrimitiveInfo>> _primitives;
            template<std::same_as<IMaterialInfo> ComponentInfo>
            constexpr const std::list<std::unique_ptr<const ComponentInfo>> &getComponentInfos() const noexcept
            { return _materials; }
            const std::list<std::unique_ptr<const IMaterialInfo>> _materials;

            template<std::same_as<IOutputFormatterInfo> ComponentInfo>
            constexpr const std::list<std::unique_ptr<const ComponentInfo>> &getComponentInfos() const noexcept
            { return _outputFormatters; }
            const std::list<std::unique_ptr<const IOutputFormatterInfo>> _outputFormatters;
    };
}


#endif /* !RAYTRACCER_MODULES_MODULEINFO_HPP_ */
