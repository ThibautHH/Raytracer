/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** main
*/

#include <iostream>

#include "Core/Processor.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <config_file>" << std::endl;
        return 84;
    }

    Raytracer::Core::Processor(nullptr).render();

    return 0;
}
