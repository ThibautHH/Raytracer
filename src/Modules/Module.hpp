/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Module
*/

#ifndef RAYTRACER_MODULES_MODULE_HPP_
    #define RAYTRACER_MODULES_MODULE_HPP_

    #include <functional>
    #include <optional>
    #include <string_view>

    #include "../DynamicLibrary/ILibrary.hpp"
    #include "ModuleInfo.hpp"

namespace Raytracer::Modules {
    class Module {
        public:
            static constexpr const char InfoSymbol[] = "moduleInfo";

            Module(std::unique_ptr<const DynamicLibrary::ILibrary> library);

            template<typename ComponentInfo>
            std::optional<typename ComponentInfo::factory_ptr> tryCreateFactory(std::string_view componentType) const
            {
                std::optional<std::reference_wrapper<const ComponentInfo>> componentInfo = _moduleInfo.tryGetComponentInfo<ComponentInfo>(componentType);
                if (!componentInfo.has_value())
                    return std::nullopt;
                return componentInfo->get().createFactory();
            }

        private:
            const std::unique_ptr<const DynamicLibrary::ILibrary> _library;
            const ModuleInfo &_moduleInfo;
    };
}

#endif /* !RAYTRACER_MODULES_MODULE_HPP_ */
