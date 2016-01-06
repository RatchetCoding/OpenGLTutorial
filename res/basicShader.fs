#version 120

uniform sampler2D diffuse;

varying vec2 texCoord0;

uniform mat4 transform;


void main()
{
	gl_FragColor = texture2D(diffuse,texCoord0);
}