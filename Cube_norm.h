#pragma once
#include "Model.h"
class Cube_norm : public Model
{
	glm::vec4 p_Color = glm::vec4(1.0f, 1.0f, 0.666f, 1.0f);
public:
	Cube_norm()
	{

	}
	Cube_norm(glm::vec3 p_Position, glm::vec4 p_Color, float p_Length)
	{
		
		m_Meshes.push_back(std::move(Mesh(p_Position)));
		m_Meshes[0].SetVertices(vertices);
		m_Meshes[0].SetDrawMode(GL_TRIANGLES);
	}
	float vertices[360] = {
		-0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, -1.0f,
		 0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, -1.0f,
		 0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, -1.0f,
		-0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, -1.0f,
		-0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, -1.0f,
						  
		-0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f,0.0f,  0.0f, 1.0f,
						   
		-0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f,-1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f,-1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f,-1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f,-1.0f,  0.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f,-1.0f,  0.0f,  0.0f,
		-0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f,-1.0f,  0.0f,  0.0f,
						  
		 0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f, 1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f, 1.0f,  0.0f,  0.0f,
	     0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f, 1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f, 1.0f,  0.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f, 1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f, 1.0f,  0.0f,  0.0f,

						   
		-0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f, 0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f, 0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f, 0.0f, -1.0f,  0.0f,
		 0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f, 0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f,  0.5f,1.0,0.0,0.0,1.0f, 0.0f, -1.0f,  0.0f,
		-0.5f, -0.5f, -0.5f,1.0,0.0,0.0,1.0f, 0.0f, -1.0f,  0.0f,
						  
		-0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f, 0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f, 0.0f,  1.0f,  0.0f,
	     0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f, 0.0f,  1.0f,  0.0f,
		 0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f, 0.0f,  1.0f,  0.0f,
		-0.5f,  0.5f, -0.5f,1.0,0.0,0.0,1.0f, 0.0f,  1.0f,  0.0f,
	    - 0.5f,  0.5f,  0.5f,1.0,0.0,0.0,1.0f, 0.0f,  1.0f,  0.0f

	};
};
