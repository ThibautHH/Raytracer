/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IScene
*/

#ifndef RAYTRACER_CORE_ISCENE_HPP_
    #define RAYTRACER_CORE_ISCENE_HPP_

    #include <list>
    #include <memory>

    #include "../Core/Common.hpp"
    #include "../Core/Camera.hpp"

    #include "../Lights/ILight.hpp"
    #include "../Primitives/IPrimitive.hpp"

namespace Raytracer::Core {
    class IScene {
        public:
            virtual ~IScene() = default;

            virtual const Core::ColorShift &getBackground() const noexcept = 0;

            virtual const Core::Camera &getCamera() const noexcept = 0;

            virtual const std::list<std::unique_ptr<Primitives::IPrimitive>> &getPrimitives() const noexcept = 0;

            virtual const std::list<std::unique_ptr<Lights::ILight>> &getLights() const noexcept = 0;
    };
}

#endif /* !RAYTRACER_CORE_ISCENE_HPP_ */
