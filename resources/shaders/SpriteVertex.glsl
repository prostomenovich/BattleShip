#version 410
layout (location = 0) in vec2 vertexPosition;
layout (location = 1) in vec2 textureCoords;
out vec2 texture_coords;

uniform mat4 modelMat;
uniform mat4, projectionMat;

void main()
{
    texture_coords = textureCoords;
    gl_Position =  projectionMat * modelMat * vec4(vertexPosition, 0.0, 1.0);
}