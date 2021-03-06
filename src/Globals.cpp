#include "../include/Globals.h"
#include <string>
#include <iostream>
#include <gl/glew.h>
namespace bogong{
bool error()
{
	GLenum err = glGetError();
	if (err != GL_NO_ERROR)
	{
		std::string error = "";
		switch (err) {
		case GL_INVALID_OPERATION:      error = "INVALID_OPERATION";      break;
		case GL_INVALID_ENUM:           error = "INVALID_ENUM";           break;
		case GL_INVALID_VALUE:          error = "INVALID_VALUE";          break;
		case GL_OUT_OF_MEMORY:          error = "OUT_OF_MEMORY";          break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:  error = "INVALID_FRAMEBUFFER_OPERATION";  break;
		}
		std::cout << "GL_" << error.c_str();
		return true;
	}
	return false;
}
}