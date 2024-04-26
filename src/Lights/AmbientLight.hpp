/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** AmbientLight
*/

#ifndef RAYTRACER_LIGHTS_AMBIENTLIGHT_HPP_
    #define RAYTRACER_LIGHTS_AMBIENTLIGHT_HPP_

    #include "ILight.hpp"

namespace Raytracer::Lights {
    class AmbientLight : public ILight {
        public:
            AmbientLight(const Core::Color &color, float intensity = 1.0f);

            Core::ColorShift getShift(const Core::Vector &, const Core::Vector &) const noexcept final;

        private:
            const Core::ColorShift _shift;
    };
}

#endif /* !RAYTRACER_LIGHTS_AMBIENTLIGHT_HPP_ */
