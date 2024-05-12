/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** MaterialInfo
*/

#ifndef RAYTRACER_MATERIALS_MODULES_MATERIALINFO_HPP_
    #define RAYTRACER_MATERIALS_MODULES_MATERIALINFO_HPP_

    #include "../../Modules/ComponentInfo.hpp"

    #include "MaterialFactory.hpp"

namespace Raytracer::Materials::Modules {
    template<const char type[], std::derived_from<IMaterial> T>
    class MaterialInfo : public Raytracer::Modules::AComponentInfo<type, IMaterial, IMaterialConfiguration> {
        public:
            std::unique_ptr<Raytracer::Modules::IComponentFactory<IMaterial, IMaterialConfiguration>> createFactory() const final
            {
                return std::make_unique<MaterialFactory<T>>();
            }
    };
}

#endif /* !RAYTRACER_MATERIALS_MODULES_MATERIALINFO_HPP_ */
