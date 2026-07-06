add_executable(${PROJECT_NAME}

        main.cpp

        ${EXTERNAL_DIR}/glad/src/glad.c

        #imGUI
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp

        #backends
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl2.cpp
        core/Timer.h
        core/Timer.cpp
        graphics/Camera.h
        graphics/Camera.cpp
        graphics/Shader.h
        graphics/Shader.cpp
)

add_subdirectory(core)
add_subdirectory(gui)
add_subdirectory(graphics)
add_subdirectory(math)
add_subdirectory(scene)
add_subdirectory(particles)
add_subdirectory(utils)

target_include_directories(${PROJECT_NAME}
        PRIVATE

        ${CMAKE_CURRENT_SOURCE_DIR}

        ${EXTERNAL_DIR}/glad/include
        ${EXTERNAL_DIR}/stb

        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
)

add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

target_link_libraries(${PROJECT_NAME}

        PRIVATE

        glfw3
        opengl32
        glu32
        gdi32
)