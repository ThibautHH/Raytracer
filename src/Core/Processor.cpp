/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Processor
*/

#include "Processor.hpp"

using namespace Raytracer::Core;

Processor::Processor(std::unique_ptr<const Configuration::IConfiguration> configuration)
    : _configuration(std::move(configuration))
{
}

void Processor::render()
{
}
