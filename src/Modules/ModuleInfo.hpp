/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** ModuleInfo
*/

#ifndef RAYTRACCER_MODULES_MODULEINFO_HPP_
    #define RAYTRACCER_MODULES_MODULEINFO_HPP_

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

            const std::list<std::unique_ptr<IConfigurationReaderInfo>> &getConfigurationReaders() const noexcept;

            const std::list<std::unique_ptr<ILightInfo>> &getLights() const noexcept;
            const std::list<std::unique_ptr<IPrimitiveInfo>> &getPrimitives() const noexcept;
            const std::list<std::unique_ptr<IMaterialInfo>> &getMaterials() const noexcept;

        private:
            const std::list<std::unique_ptr<IConfigurationReaderInfo>> _configurationReaders;

            const std::list<std::unique_ptr<ILightInfo>> _lights;
            const std::list<std::unique_ptr<IPrimitiveInfo>> _primitives;
            const std::list<std::unique_ptr<IMaterialInfo>> _materials;
    };
}


#endif /* !RAYTRACCER_MODULES_MODULEINFO_HPP_ */
