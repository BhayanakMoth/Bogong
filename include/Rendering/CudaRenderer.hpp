#pragma once
#include "../VertexArray.hpp"
#include "../Shaders.hpp"
#include "../VertexBufferLayout.hpp"

#include "CudaMesh.hpp"
#include "../Globals.h"
#include <functional>
#include <memory>
namespace bogong {
	namespace cuda {
		class CudaRenderer 
		{
		private:
			
			VertexArray m_VAO;
			glm::mat4 m_Model = glm::mat4(1.0);
			GLenum m_DrawMode;
			Shader m_Shader;
			using DrawCall = std::function<void(GLenum, int)>;
			DrawCall  m_DrawCall = [](GLenum, int)-> void {};
		public:
			 
			CudaRenderer()
			{	
				m_VAO = VertexArray();
			}
		
			template<typename T>
			void RenderMesh(const std::shared_ptr<T> & cumesh)
			{
				m_VAO.Bind();
				m_Shader.Bind();
				if (cumesh->GetIndexBuffer().GetID() != 0)
				{
					m_DrawCall = [](GLenum DrawMode, size_t count) { glDrawElements(DrawMode, count, GL_UNSIGNED_INT, 0); };
				}
				else
				{
					m_DrawCall = [](GLenum DrawMode, size_t count) { glDrawArrays(DrawMode, 0, count);  };
				}
			
				size_t count = cumesh->GetCount();
				m_Shader.setMat4("model",m_Model);
				m_DrawCall(m_DrawMode, count);
				error();
			}
			template<typename T>
			void BindBuffer(const std::shared_ptr<T> & cumesh)
			{
				m_VAO.Bind();
				assert(!error());
				cumesh->Bind();
				error();
			}
			template<typename T>
			void UnbindBuffer(const std::shared_ptr<T> & cumesh)
			{
				cumesh->Unbind();
				m_VAO.Unbind();	
			}
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
}