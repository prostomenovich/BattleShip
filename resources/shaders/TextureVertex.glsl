#version 410
layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;
layout (location = 2) in vec2 textureCoords;
out vec3 color;
out vec2 texture_coords;

void main()
{
    color = vertexColor;
    texture_coords = textureCoords;
    gl_Position =  vec4(vertexPosition, 1.0);
}