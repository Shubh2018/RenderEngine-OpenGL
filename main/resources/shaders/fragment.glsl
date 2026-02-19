#version 440 core

in vec4 vertexColor;
out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D tex1, tex2;

void main()
{
    FragColor = mix(texture(tex1, texCoord), texture(tex2, texCoord), 0.2f);
}