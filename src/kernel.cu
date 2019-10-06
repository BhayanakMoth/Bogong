#include <cuda_runtime.h>
#include "../include/RunKernel.h"
/////////////////////////////////////////////////////////////////////////////////
////! Simple kernel to modify vertex positions in sine wave pattern
////! @param data  data in global memory
/////////////////////////////////////////////////////////////////////////////////
__global__ void simple_vbo_kernel(float3 *pos, unsigned int width, unsigned int height, float time)
{
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;

	// calculate uv coordinates
	float u = x / (float)width;
	float v = y / (float)height;
	u = u * 2.0f - 1.0f;
	v = v * 2.0f - 1.0f;

	// calculate simple sine wave pattern
	float freq = 4.0f;
	float w = sinf(u*freq + time) * cosf(v*freq + time) * 0.5f;

	// write output vertex
	pos[y*width + x] = make_float3(u, w, v);
}
__global__ void color_kernel(float4 *pos, unsigned int width, unsigned int height, float time)
{
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;
	float xx = x / (float)width;
	float yy = y / (float)height;
	float u = 0.5f + 0.5f*cosf(time + xx + 0);
	float v = 0.5f + 0.5f*cosf(time + yy + 2);
	float w = 0.5f + 0.5f*cosf(time + xx + 4);
	
	// write output vertex
	pos[y*width + x] = make_float4(u, v, w,1.0);
}
__global__ void grid_kernel(float3 * pos, unsigned int width, unsigned int height, float time)
{
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	unsigned int z = blockIdx.y*blockDim.y + threadIdx.y;
	float u = pos[x + z * width].x;
	float v = pos[x + z * width].y;
	float freq = 4.0f;
	pos[x + z * width].y = sinf(u*freq + time) * cosf(v*freq + time) * 0.5f;

}
void UpdateMesh(float3 *pos, unsigned int mesh_width,
	unsigned int mesh_height, float time)
{
	// execute the kernel
	dim3 block(8, 8, 1);
	dim3 grid(mesh_width / block.x, mesh_height / block.y, 1);
	simple_vbo_kernel << < grid, block >> > (pos, mesh_width, mesh_height, time);
}

void UpdateColors(float4 * pos, unsigned int width, unsigned int height, float time)
{
	// execute the kernel
	dim3 block(8, 8, 1);
	dim3 grid(width / block.x, height / block.y, 1);
	color_kernel << < grid, block >> > (pos, width, height, time);
}

void UpdateGrid(float3 * pos, unsigned int width, unsigned int height, float time)
{
	dim3 block(8, 8, 1);
	dim3 grid(width / block.x, height / block.y, 1);
	grid_kernel << <grid, block >> > (pos, width, height, time);
}
