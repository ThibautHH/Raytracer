/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Processor
*/

#include "Processor.hpp"

using namespace Raytracer::Core;

Processor::Processor(scene_ptr scene)
    : _scene(std::move(scene))
{
}

void Processor::render()
{
}
