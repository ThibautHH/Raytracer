/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Camera
*/

#ifndef RAYTRACER_CORE_CAMERA_HPP_
    #define RAYTRACER_CORE_CAMERA_HPP_

    #include "Vector.hpp"

namespace Raytracer::Core {
    struct Camera {
        Camera(Vector pos, Vector rot)
            : position(pos), rotation(rot)
        {}

        const Vector position, rotation;
    };
}

#endif /* !RAYTRACER_CORE_CAMERA_HPP_ */
