#version 330 core

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTexCoord;

uniform mat4 uView;
uniform mat4 uProjection;
uniform mat4 uModel;

uniform vec3 uCameraRight;
uniform vec3 uCameraUp;

out vec2 TexCoord;

void main()
{
    TexCoord = aTexCoord;

    //-----------------------------------
    // Centro del billboard
    //-----------------------------------

    vec3 center = vec3(uModel[3]);

    //-----------------------------------
    // Escala tomada del Transform
    //-----------------------------------

    float scaleX = length(uModel[0].xyz);
    float scaleY = length(uModel[1].xyz);

    //-----------------------------------
    // Construcción del quad
    //-----------------------------------

    vec3 worldPosition =
            center
            + uCameraRight * aPosition.x * scaleX
            + uCameraUp    * aPosition.y * scaleY;

    gl_Position =
        uProjection *
        uView *
        vec4(worldPosition,1.0);
}