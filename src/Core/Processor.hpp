/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Processor
*/

#ifndef RAYTRACER_CORE_PROCESSOR_HPP_
    #define RAYTRACER_CORE_PROCESSOR_HPP_

    #include <memory>

    #include "../Configuration/IConfiguration.hpp"

namespace Raytracer::Core {
    class Processor {
        public:
            Processor(std::unique_ptr<const Configuration::IConfiguration> configuration);

            void render();

        private:
            const std::unique_ptr<const Configuration::IConfiguration> _configuration;
    };
}

#endif /* !RAYTRACER_CORE_PROCESSOR_HPP_ */
