#version 330 core

// Ouput data
in vec2 texCoords;
in vec4 fragColor;
out vec4 color;
void main()
{
    color = fragColor;
 
}