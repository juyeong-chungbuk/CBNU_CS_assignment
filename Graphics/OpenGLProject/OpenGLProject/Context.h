#pragma once
#include "Dog.h"

/*
The context holds all rendered objects, a single point to access the scene objects.
*/
class Context {
public:
	GLfloat globalAmbient = 0.3f;
	int isDogView = 0;
	Dog dog;

};