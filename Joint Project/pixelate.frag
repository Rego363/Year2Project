#version 400
uniform sampler2D tex;

void main()
{
    gl_FragColor = gl_Color* tex;
}