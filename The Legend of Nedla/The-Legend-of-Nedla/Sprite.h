#pragma once
#include <GL\glew.h>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void init(float x, float y, float width, float height);

	void draw();

private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint _vboID; //Vertex buffer object? Just the data containing the information about the object/buffer?
};

