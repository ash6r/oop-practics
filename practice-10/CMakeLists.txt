cmake_minimum_required(VERSION 4.1)

project("practice-10" CXX)

find_package(SFML COMPONENTS Graphics REQUIRED)

add_executable("${PROJECT_NAME}" "main.cpp")

target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_23)

target_link_libraries("${PROJECT_NAME}" PRIVATE SFML::Graphics)
