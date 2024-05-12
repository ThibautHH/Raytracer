/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** container_init
*/

#ifndef UTILS_CONTAINER_INIT_HPP_
    #define UTILS_CONTAINER_INIT_HPP_

    #include <utility>

namespace Utils {
    template<template<typename> typename C, typename T, typename ...Types>
    C<T> container_init(Types&& ...values)
    {
        C<T> container;
        (container.emplace_back(std::forward<Types>(values)), ...);
        return container;
    }
}

#endif /* !UTILS_CONTAINER_INIT_HPP_ */
