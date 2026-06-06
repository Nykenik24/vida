file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(vida_input STATIC ${SOURCES})
add_library(vida::input ALIAS vida_input)

set_target_properties(vida_input PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/vida
)

target_include_directories(vida_input
    PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(vida_input
    PUBLIC
        vida::core
        vida::window
        glfw
        OpenGL::GL
        glad
)

target_compile_options(vida_input PRIVATE
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
