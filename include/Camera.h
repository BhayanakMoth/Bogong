﻿#pragma once
#include<glm/gtx/transform.hpp>
#include <memory>
#include "Defs.h"
namespace bogong
{
	class Keyboard;
	class Mouse;
	class Camera
	{
	protected:
		glm::mat4 projection;
		glm::mat4 view;
		int width = 3840;
		int height = 2160;
	public:
		glm::mat4 GetProjection();

		glm::mat4 GetView();
	};

	class FPCamera : public Camera
	{
		glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
		float cameraSpeed = 1.0f;
		int screenWidth = SCREEN_WIDTH;
		int screenHeight = SCREEN_HEIGHT;
		float prevMouseX = 0;
		float prevMouseY = 0;
		float currMouseX = 0.0f;
		float currMouseY = 0.0f;
		float pitch = 0.0f;
		float yaw = -90.0f;	
	public:
		FPCamera();
		void Update(const std::shared_ptr<Keyboard> &kbd, const std::shared_ptr<Mouse> & mouse, float delta);
		glm::vec3 GetPos() {
			return cameraPos;
		}
		void InputPos();
	};

	
}
