/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** IComponentFactory
*/

#ifndef RAYTRACER_MODULES_ICOMPONENTFACTORY_HPP_
    #define RAYTRACER_MODULES_ICOMPONENTFACTORY_HPP_

    #include <memory>

namespace Raytracer::Modules {
    template<typename Component, typename Configuration>
    class IComponentFactory {
        public:
            virtual ~IComponentFactory() = default;

            virtual std::unique_ptr<Component> create(std::unique_ptr<const Configuration> configuration) const = 0;
    };
}

#endif /* !RAYTRACER_MODULES_ICOMPOMENTFACTORY_HPP_ */
