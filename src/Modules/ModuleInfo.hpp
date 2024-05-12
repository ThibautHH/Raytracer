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
            template<std::same_as<std::list<std::unique_ptr<IConfigurationReaderInfo>>> ConfigurationReaderInfos,
                std::same_as<std::list<std::unique_ptr<ILightInfo>>> LightInfos,
                std::same_as<std::list<std::unique_ptr<IPrimitiveInfo>>> PrimitiveInfos,
                std::same_as<std::list<std::unique_ptr<IMaterialInfo>>> MaterialInfos>
            ModuleInfo(ConfigurationReaderInfos &&configurationReaders,
                LightInfos &&lights, PrimitiveInfos &&primitives, MaterialInfos &&materials)
                : _configurationReaders(std::forward<ConfigurationReaderInfos>(configurationReaders)),
                _lights(std::forward<LightInfos>(lights)),
                _primitives(std::forward<PrimitiveInfos>(primitives)),
                _materials(std::forward<MaterialInfos>(materials))
            {}

            template<typename ComponentInfo>
            std::optional<std::reference_wrapper<const ComponentInfo>> tryGetComponentInfo(std::string_view componentType) const
            {
                auto it = std::find_if(_configurationReaders.cbegin(), _configurationReaders.cend(), [componentType](const auto &info) {
                    return info->getName() == componentType;
                });
                return it != _configurationReaders.cend()
                    ? std::optional<std::reference_wrapper<const ComponentInfo>>(std::ref(**it))
                    : std::nullopt;
            }

        private:
            const std::list<std::unique_ptr<IConfigurationReaderInfo>> _configurationReaders;

            const std::list<std::unique_ptr<ILightInfo>> _lights;
            const std::list<std::unique_ptr<IPrimitiveInfo>> _primitives;
            const std::list<std::unique_ptr<IMaterialInfo>> _materials;
    };
}


#endif /* !RAYTRACCER_MODULES_MODULEINFO_HPP_ */
