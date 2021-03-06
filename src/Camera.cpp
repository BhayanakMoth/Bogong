#include "../include/Camera.h"
#include "../include/Keyboard.h"
#include "../include/Mouse.h"
#include "../Imgui/imgui.h"
#include<string>
namespace bogong {
	class Mouse;
}

glm::mat4 bogong::Camera::GetProjection()
{
	return projection;
}

glm::mat4 bogong::Camera::GetView()
{
	return view;
}

bogong::FPCamera::FPCamera()
{
	projection = glm::perspective(glm::radians(45.0f), float(screenWidth) / float(screenHeight), 0.1f, 100.0f);
	view = lookAt(cameraPos, cameraPos + cameraFront, up);
}
void bogong::FPCamera::InputPos() {
	ImGui::InputFloat3("Cam Pos", (float *)&cameraPos, 4);
}
void bogong::FPCamera::Update(const std::shared_ptr<Keyboard>& kbd, const std::shared_ptr<Mouse>& mouse, float delta)
{

	float camSpeed = cameraSpeed * delta;
	if (kbd->isKeyPressed(KEY_W) || kbd->isKeyRepeating(KEY_W))
	{
		cameraPos += camSpeed * cameraFront;
	}
	if (kbd->isKeyPressed(KEY_S) || kbd->isKeyRepeating(KEY_S))
	{
		cameraPos -= camSpeed * cameraFront;
	}
	if (kbd->isKeyPressed(KEY_A) || kbd->isKeyRepeating(KEY_A))
	{
		cameraPos -= normalize(cross(cameraFront, up)) * camSpeed;
	}
	if (kbd->isKeyPressed(KEY_D) || kbd->isKeyRepeating(KEY_D))
	{
		cameraPos += normalize(cross(cameraFront, up)) * camSpeed;
	}
	if (kbd->isKeyPressed(KEY_Z) || kbd->isKeyRepeating(KEY_Z)) {
		cameraPos.y += camSpeed;
	}
	if (kbd->isKeyPressed(KEY_X) || kbd->isKeyRepeating(KEY_X)) {
		cameraPos.y -= camSpeed;
	}
	prevMouseX = currMouseX;
	prevMouseY = currMouseY;
	currMouseX = mouse->x;
	currMouseY = mouse->y;
	float xoffset = currMouseX - prevMouseX;
	float yoffset = prevMouseY - currMouseY;
	xoffset = 0.05*xoffset;
	yoffset = 0.05*yoffset;
	yaw += xoffset;
	pitch += yoffset;
	pitch = glm::clamp(pitch, -89.0f, 89.0f);
	glm::vec3 direction;
	direction.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw))*cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
	view = lookAt(cameraPos, cameraPos + cameraFront, up);
}
