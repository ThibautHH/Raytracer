/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Processor
*/

#ifndef RAYTRACER_CORE_PROCESSOR_HPP_
    #define RAYTRACER_CORE_PROCESSOR_HPP_

namespace Raytracer::Core {
    class Processor {
        public:
            Processor(const char *configFile);

            void render();
    };
}

#endif /* !RAYTRACER_CORE_PROCESSOR_HPP_ */
