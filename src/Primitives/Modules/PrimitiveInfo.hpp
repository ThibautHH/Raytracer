/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** PrimitiveInfo
*/

#ifndef RAYTRACER_PRIMITIVES_MODULES_PRIMITIVEINFO_HPP_
    #define RAYTRACER_PRIMITIVES_MODULES_PRIMITIVEINFO_HPP_

    #include "../../Modules/ComponentInfo.hpp"

    #include "PrimitiveFactory.hpp"

namespace Raytracer::Primitives::Modules {
    template<std::derived_from<IPrimitive> T>
    class PrimitiveInfo : public Raytracer::Modules::AComponentInfo<T::type, IPrimitive, IPrimitiveConfiguration> {
        public:
            std::unique_ptr<Raytracer::Modules::IComponentFactory<IPrimitive, IPrimitiveConfiguration>> createFactory() const final
            {
                return std::make_unique<PrimitiveFactory<T>>();
            }
    };
}

#endif /* !RAYTRACER_PRIMITIVES_MODULES_PRIMITIVEINFO_HPP_ */
