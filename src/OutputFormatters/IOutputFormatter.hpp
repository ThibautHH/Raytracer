/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IOutputFormatter
*/

#ifndef RAYTRACER_OUTPUTFORMATTERS_IOUTPUTFORMATTER_HPP_
    #define RAYTRACER_OUTPUTFORMATTERS_IOUTPUTFORMATTER_HPP_

    #include <ostream>
    #include <vector>

    #include "../Core/Common.hpp"

namespace Raytracer::OutputFormatters {
    class IOutputFormatter {
        public:
            ~IOutputFormatter() = default;

            virtual std::ostream &write(std::ostream &os, const std::vector<std::vector<Core::Color>> &framebuffer) const = 0;
    };
}

#endif /* !RAYTRACER_OUTPUTFORMATTERS_IOUTPUTFORMATTER_HPP_ */
