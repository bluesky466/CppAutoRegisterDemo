cmake_minimum_required(VERSION 3.15.0)
project(Demo)

include_directories(../)
set(CMAKE_CXX_STANDARD 11)

option(EN_SHARED_FROM_THIS "enable shared_from_this" ON)
message(STATUS "EN_SHARED_FROM_THIS: " ${EN_SHARED_FROM_THIS})
if(EN_SHARED_FROM_THIS)
    add_compile_definitions(EN_SHARED_FROM_THIS)
endif()

add_compile_definitions(DEPENDENT_MODE)

if(DEPENDENT_MODE STREQUAL "STATIC")
    message(STATUS "Build on STATIC")

    add_library(${PROJECT_NAME}-Lib STATIC
        ../factory.cpp
        ../component_a.cpp
        ../component_b.cpp
    )

    add_executable(${PROJECT_NAME}
        ../main.cpp
    )

    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-Lib)
elseif(DEPENDENT_MODE STREQUAL "SHARED")
    message(STATUS "Build on SHARED")

    add_library(${PROJECT_NAME}-Lib SHARED
        ../factory.cpp
        ../component_a.cpp
        ../component_b.cpp
    )

    add_executable(${PROJECT_NAME}
        ../main.cpp
    )

    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-Lib)
elseif(DEPENDENT_MODE STREQUAL "SOURCE")
    message(STATUS "Build on SOURCE")
    
    add_executable(${PROJECT_NAME}
        ../main.cpp
        ../factory.cpp
        ../component_a.cpp
        ../component_b.cpp
    )
else()
    message(STATUS "Unknown DEPENDENT_MODE: " ${DEPENDENT_MODE})
endif()
