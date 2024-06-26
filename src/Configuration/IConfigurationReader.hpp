/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IConfigurationReader
*/

#ifndef RAYTRACER_CONFIGURATION_ICONFIGURATIONREADER_HPP_
    #define RAYTRACER_CONFIGURATION_ICONFIGURATIONREADER_HPP_

    #include <istream>

    #include "IConfiguration.hpp"

namespace Raytracer::Configuration {
    class IConfigurationReader {
        public:
            virtual ~IConfigurationReader() = default;

            virtual std::unique_ptr<IConfiguration> readConfiguration(std::istream &is) const = 0;
    };
}

#endif /* !RAYTRACER_CONFIGURATION_ICONFIGURATIONREADER_HPP_ */
