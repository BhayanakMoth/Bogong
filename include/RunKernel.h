#pragma once
#include "../Extra/helper_functions.h"
#include "../Extra/helper_cuda.h"
#include <cuda_runtime.h>
#include <cuda_gl_interop.h>
void UpdateMesh(float3 *pos, unsigned int width, unsigned int height,float time);
void UpdateColors(float4 *pos, unsigned int width, unsigned int height,float time);
void UpdateGrid(float3 * pos, unsigned int width, unsigned int height, float time);