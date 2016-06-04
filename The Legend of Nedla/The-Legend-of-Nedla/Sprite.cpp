#include "Sprite.h"



Sprite::Sprite()
{
	_vboID = 0;
}

//Deconstructor helps in closing shit?
Sprite::~Sprite()
{
	//Delete the buffer once were done with it
	if (_vboID != 0)
	{
		glDeleteBuffers(1, &_vboID);
	}
}

void Sprite::init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	//Generate a buffer if one doesn't exist already
	if (_vboID == 0)
	{
		glGenBuffers(1, &_vboID);
	}

	float vertexData[12];

	//First triangle
	vertexData[0] = x + width;
	vertexData[1] = y + height;
	
	vertexData[2] = x;
	vertexData[3] = y + height;
	
	vertexData[4] = x;
	vertexData[5] = y;

	//Second triangle
	vertexData[6] = x;
	vertexData[7] = y;

	vertexData[8] = x + width;
	vertexData[9] = y;

	vertexData[10] = x + width;
	vertexData[11] = y + height;

	glBindBuffer(GL_ARRAY_BUFFER, _vboID); //Makes current buffer (_vboID) the active one of type 'GL_ARRAY_BUFFER' which is a basic vertex buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW); //Again, type of buffer, amount of data, data itself, how to draw

	glBindBuffer(GL_ARRAY_BUFFER, 0); //Binding zero is to unbind the buffer
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vboID); //We can only have one buffer active at a time so each time we need to say this is the active one.

	glDisableVertexAttribArray(0); //Sending array of positions? The first position?

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0); //Pointing OpenGL to the start of the data, "how to start"? What?

	glDrawArrays(GL_TRIANGLES, 0, 6); //Draw it?

	glDisableVertexAttribArray(0); //Close it

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}