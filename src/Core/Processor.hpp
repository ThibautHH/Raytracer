/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Processor
*/

#ifndef RAYTRACER_CORE_PROCESSOR_HPP_
    #define RAYTRACER_CORE_PROCESSOR_HPP_

    #include <memory>

    #include "IScene.hpp"

namespace Raytracer::Core {
    class Processor {
        private:
            typedef std::unique_ptr<const IScene> scene_ptr;
            const scene_ptr _scene;

        public:
            Processor(scene_ptr scene);

            void render();
    };
}

#endif /* !RAYTRACER_CORE_PROCESSOR_HPP_ */
