/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** MaterialFactory
*/

#ifndef RAYTRACER_MATERIALS_MODULES_MATERIALFACTORY_HPP_
    #define RAYTRACER_MATERIALS_MODULES_MATERIALFACTORY_HPP_

    #include "../../Modules/IComponentFactory.hpp"

    #include "../IMaterial.hpp"
    #include "../IMaterialConfiguration.hpp"

namespace Raytracer::Materials::Modules {
    template<std::derived_from<IMaterial> T>
    class MaterialFactory : public Raytracer::Modules::IComponentFactory<IMaterial, IMaterialConfiguration> {
        public:
            std::unique_ptr<IMaterial> create(std::unique_ptr<const IMaterialConfiguration> configuration) const final
            {
                return std::make_unique<T>(std::move(configuration));
            }
    };
}

#endif /* !RAYTRACER_MATERIALS_MODULES_MATERIALFACTORY_HPP_ */
