#pragma once
#include <GL/glew.h>
#include <gl/gl.h>
#include "Vertex.h"
namespace bogong {
	
	class VertexBuffer
	{
	protected:
		unsigned int m_ID=0;
		bool m_IsBound;
		unsigned int m_BufferSize = 0;
	
	public:
		VertexBuffer() = default;
		VertexBuffer(const VertexBuffer & vertexBuffer)
		{
			m_ID = vertexBuffer.m_ID;
			m_IsBound = vertexBuffer.m_IsBound;
			m_BufferSize = vertexBuffer.m_BufferSize;
		}
		VertexBuffer(const void * p_Data, unsigned int p_Size, unsigned int p_Draw = GL_DYNAMIC_DRAW)
		{
			m_BufferSize = p_Size;
			glGenBuffers(1, &m_ID);
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
			glBufferData(GL_ARRAY_BUFFER, p_Size, p_Data, p_Draw);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		VertexBuffer & operator=(VertexBuffer & vbuff)
		{
			this->m_BufferSize = vbuff.m_BufferSize;
			this->m_ID = vbuff.m_ID;
			this->m_IsBound = vbuff.m_IsBound;
			return *this;
		}
		VertexBuffer & operator=(const VertexBuffer & vbuff)
		{
			this->m_BufferSize = vbuff.m_BufferSize;
			this->m_ID = vbuff.m_ID;
			this->m_IsBound = vbuff.m_IsBound;
			return *this;
		}
		void Bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		}
		void Unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		unsigned int getID() const
		{
			return m_ID;
		}
		virtual int GetStride()
		{
			return sizeof(Vertex<float>);
		}
	};
}