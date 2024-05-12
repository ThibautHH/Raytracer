/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** PrimitiveFactory
*/

#ifndef RAYTRACER_PRIMITIVES_MODULES_PRIMITIVEFACTORY_HPP_
    #define RAYTRACER_PRIMITIVES_MODULES_PRIMITIVEFACTORY_HPP_

    #include "../../Modules/IComponentFactory.hpp"

    #include "../IPrimitive.hpp"
    #include "../IPrimitiveConfiguration.hpp"

namespace Raytracer::Primitives::Modules {
    template<std::derived_from<IPrimitive> T>
    class PrimitiveFactory : public Raytracer::Modules::IComponentFactory<IPrimitive, IPrimitiveConfiguration> {
        public:
            std::unique_ptr<IPrimitive> create(std::unique_ptr<const IPrimitiveConfiguration> configuration) const final
            {
                return std::make_unique<T>(std::move(configuration));
            }
    };
}

#endif /* !RAYTRACER_PRIMITIVES_MODULES_PRIMITIVEFACTORY_HPP_ */
