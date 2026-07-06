#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D uTexture;

void main()
{
    FragColor = vec4(0.2, 0.7, 1.0, 1.0);

    // Más adelante será:
    // FragColor = texture(uTexture, TexCoord);
}