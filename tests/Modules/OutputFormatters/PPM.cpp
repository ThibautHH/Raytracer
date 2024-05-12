/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** DLLibrary tests
*/

#include <memory>
#include <optional>
#include <sstream>

#include <criterion/criterion.h>

#include "../../../src/DynamicLibrary/DLLibrary.hpp"
#include "../../../src/Modules/Module.hpp"

using namespace Raytracer;

static const char modulePath[] = "plugins/raytracer_ppm.so", componentName[] = "ppm";

Test(OutputFormatters_PPM, load)
{
    cr_assert_none_throw(Modules::Module(DynamicLibrary::DLLibraryFactory().loadLibrary(modulePath)));
}

Test(OutputFormatters_PPM, createFactory)
{
    Modules::Module module(DynamicLibrary::DLLibraryFactory().loadLibrary(modulePath));
    cr_assert_neq(module.tryCreateFactory<Modules::IOutputFormatterInfo>(componentName), std::nullopt);
}

class TestPPMConfiguration : public OutputFormatters::IOutputFormatterConfiguration
{
    public:
        std::string_view getType() const noexcept final { return componentName; }
};

Test(OutputFormatters_PPM, createFormatter)
{
    Modules::Module module(DynamicLibrary::DLLibraryFactory().loadLibrary(modulePath));
    auto factory = module.tryCreateFactory<Modules::IOutputFormatterInfo>(componentName);
    auto formatter = (*factory)->create(std::make_unique<TestPPMConfiguration>());
    cr_assert_not_null(formatter);
}

Test(OutputFormatters_PPM, write)
{
    Modules::Module module(DynamicLibrary::DLLibraryFactory().loadLibrary(modulePath));
    auto factory = module.tryCreateFactory<Modules::IOutputFormatterInfo>(componentName);
    auto formatter = (*factory)->create(std::make_unique<TestPPMConfiguration>());
    std::ostringstream ss;
    formatter->write(ss, {{{255, 255, 255}}});
    std::string str = ss.str();
    cr_assert_eq(ss.str(), "P3\n1 1\n255\n255 255 255\n");
}
