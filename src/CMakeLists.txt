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
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        core/Timer.h
        core/Timer.cpp
        graphics/Camera.h
        graphics/Camera.cpp
        graphics/Shader.h
        graphics/Shader.cpp
        graphics/Vertex.h
        graphics/Mesh.h
        graphics/Mesh.cpp
        graphics/QuadMesh.h
        graphics/QuadMesh.cpp
        scene/Transform.h
        scene/Transform.cpp
        scene/SceneObject.h
        scene/SceneObject.cpp
        graphics/Material.h
        graphics/Material.cpp
        scene/Scene.h
        scene/Scene.cpp
        graphics/Texture.h
        graphics/Texture.cpp
        graphics/stb_image.cpp
        scene/Billboard.h
        scene/Billboard.cpp
        particles/RainParticle.h
        particles/RainParticle.cpp
        particles/ParticleEmitter.h
        particles/ParticleEmitter.cpp
        particles/RainSystem.h
        particles/RainSystem.cpp
        particles/RainResources.h
        particles/RainResources.cpp
        scene/Ground.h
        scene/Ground.cpp
        scene/GroundResources.h
        scene/GroundResources.cpp
        graphics/GroundMesh.h
        graphics/GroundMesh.cpp
        scene/Tree.h
        scene/Tree.cpp
        scene/TreeResources.h
        scene/TreeResources.cpp
        scene/TreeSystem.h
        scene/TreeSystem.cpp
        audio/AudioManager.h
        audio/AudioManager.cpp
        weather/LightingSystem.h
        weather/LightingSystem.cpp
        weather/WeatherSystem.h
        weather/WeatherSystem.cpp
        #resources/Resources.h
        #resources/Resources.cpp
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

        ${EXTERNAL_DIR}/miniaudio
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