#pragma once
#include "../VertexArray.hpp"
#include "../Shaders.hpp"
#include "../VertexBufferLayout.hpp"
#include "Mesh.hpp"
#include "../Globals.h"
#include <string>
#include <functional>
#include <map>
namespace bogong
{
	class RendererBase
	{
	protected:
		GLenum m_DrawMode;
		Shader m_Shader;
		using DrawCall = std::function<void(GLenum, int)>;
		DrawCall  m_DrawCall = [](GLenum, int)-> void {};
	public:
		
		RendererBase(){}
		
		void SetShader(Shader p_Shader)
		{
			m_Shader = p_Shader;
		}
		void SetDrawMode(GLenum p_DrawMode)
		{
			m_DrawMode = p_DrawMode;
		}
		void SetDrawCall(DrawCall p_DrawCall)
		{
			m_DrawCall = p_DrawCall;
		}

	};
}