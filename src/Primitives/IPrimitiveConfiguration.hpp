/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IPrimitiveConfiguration
*/

#ifndef RAYTRACER_PRIMITVES_IPRIMITVECONFIGURATION_HPP_
    #define RAYTRACER_PRIMITVES_IPRIMITVECONFIGURATION_HPP_

    #include "../Core/Vector.hpp"

    #include "../Configuration/IComponentConfiguration.hpp"
    #include "../Materials/IMaterialConfiguration.hpp"

namespace Raytracer::Primitives {
    class IPrimitiveConfiguration : Configuration::IComponentConfiguration {
        public:
            virtual ~IPrimitiveConfiguration() = default;

            virtual const Materials::IMaterialConfiguration &getMaterial() const noexcept = 0;
            virtual Core::Vector getPosition() const noexcept = 0;
            virtual Core::Vector getRotation() const noexcept = 0;
            virtual Core::Vector getScale() const noexcept = 0;
    };
}

#endif /* !RAYTRACER_PRIMITVES_IPRIMITVECONFIGURATION_HPP_ */
