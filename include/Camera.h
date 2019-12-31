#pragma once
#include<glm/gtx/transform.hpp>
#include <memory>

namespace bogong
{
	class Keyboard;
	class Mouse;
	class Camera
	{
	protected:
		glm::mat4 projection;
		glm::mat4 view;
		int width = 2372;
		int height = 1536;
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
		int screenWidth = 2372;
		int screenHeight = 1536;
		float prevMouseX = 2560.0f/2.0f;
		float prevMouseY = 1440.0f/2.0f;
		float currMouseX = 0.0f;
		float currMouseY = 0.0f;
		float pitch = 0.0f;
		float yaw = -90.0f;	
	public:
		FPCamera();
		void Update(const std::shared_ptr<Keyboard> &kbd, const std::shared_ptr<Mouse> & mouse, float delta);
	};

	
}
