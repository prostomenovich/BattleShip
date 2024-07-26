#version 410
in vec2 texture_coords;
out vec4 fragColor;

uniform sampler2D tex;

void main()
{
    vec4 color = texture(tex, texture_coords);
    if (color.a <0.01){
        discard;
    }
    fragColor = color;
}