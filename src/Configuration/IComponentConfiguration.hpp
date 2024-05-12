/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IComponentConfiguration
*/

#ifndef RAYTRACER_CONFIGURATION_ICOMPONENTCONFIGURATION_HPP_
    #define RAYTRACER_CONFIGURATION_ICOMPONENTCONFIGURATION_HPP_

    #include <optional>
    #include <string>
    #include <unordered_map>

namespace Raytracer::Configuration {
    class IComponentConfiguration : public std::unordered_map<std::string, std::optional<std::string>> {
        public:
            virtual ~IComponentConfiguration() = default;

            virtual std::string_view getType() const noexcept = 0;
    };
}

#endif /* !RAYTRACER_CONFIGURATION_ICOMPONENTCONFIGURATION_HPP_ */
