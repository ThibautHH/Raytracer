/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** OutputFormatter
*/

#include <algorithm>
#include <vector>

#include "OutputFormatter.hpp"

using namespace Raytracer::OutputFormatters::Modules::PPM;

std::ostream &operator<<(std::ostream &os, const Raytracer::Core::Color &color)
{
    return os << +color.r << ' ' << +color.g << ' ' << +color.b;
}

OutputFormatter::OutputFormatter(std::unique_ptr<const IOutputFormatterConfiguration>)
{
}

std::ostream &OutputFormatter::write(std::ostream &os, const std::vector<std::vector<Core::Color>> &framebuffer) const
{
    os << "P3\n" << framebuffer.size() << " " << framebuffer.front().size() << "\n255\n";
    for (const std::vector<Core::Color> &line : framebuffer) {
        if (line.size() != framebuffer.front().size())
            throw std::runtime_error("IOuputFormatter::write: framebuffer line size mismatch");
        std::vector<Core::Color>::const_iterator last = --line.cend();
        std::for_each(line.cbegin(), last, [&os](const Core::Color &pixel) {
            os << pixel << " ";
        });
        os << *last << "\n";
    }
    return os;
}
