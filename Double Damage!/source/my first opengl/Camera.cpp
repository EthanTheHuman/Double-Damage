#include "Camera.h"
#include "Utils2.h"


Camera::Camera()
{
	// View Matrix
	SetViewMatrix();

	// Projection Matrix
	SetProjectionMatrix();
}

Camera::Camera(glm::vec3 _Position, glm::vec3 _Facing, glm::vec3 _Normal)
{
	//Set Variables
	SetCameraPosition(_Position);
	SetCameraFacing(_Facing);
	SetCameraNormal(_Normal);

	// View Matrix
	SetViewMatrix();

	// Projection Matrix
	SetProjectionMatrix();
}


Camera::~Camera()
{
}

void Camera::Update()
{
	float currentTime = glutGet(GLUT_ELAPSED_TIME);
	currentTime = currentTime * 0.001f;
	SetCameraPosition({ (sin(currentTime) * 5),  1,  (cos(currentTime) * 5) });
	SetViewMatrix();
	SetProjectionMatrix();
	LookAt();
}

glm::mat4 Camera::GetViewMatrix()
{
	return m_ViewMatrix;
}

void Camera::SetViewMatrix()
{
	m_ViewMatrix = glm::lookAt(m_CameraPosition, glm::vec3(0, 0, 0), m_CameraNormal);
}

void Camera::SetViewMatrix(glm::vec3 _Position, glm::vec3 _Facing, glm::vec3 _Normal)
{
	m_ViewMatrix = glm::lookAt(_Position, _Position + _Facing, _Normal);
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return m_ProjectionMatrix;
}

void Camera::SetProjectionMatrix()
{
	float HalfWidth = SourceWidth / 2;
	float HalfHeight = SourceHeight / 2;
	m_ProjectionMatrix = glm::perspective(
		45.0f,									//Field of View
		(float)SRCWIDTH / (float) SRCHEIGHT,	//Aspect ratio
		0.1f,									//Near cutoff
		5000.0f									//Far cutoff
	);
}

glm::vec3 Camera::GetCameraPosition()
{
	return m_CameraPosition;
}

void Camera::SetCameraPosition(glm::vec3 _Position)
{
	m_CameraPosition = _Position;
}

glm::vec3 Camera::GetCameraFacing()
{
	return m_CameraFacing;
}

void Camera::SetCameraFacing(glm::vec3 _Facing)
{
	m_CameraFacing = _Facing;
}

glm::vec3 Camera::GetCameraNormal()
{
	return m_CameraNormal;
}

void Camera::SetCameraNormal(glm::vec3 _Normal)
{
	m_CameraNormal = _Normal;
}

void Camera::LookAt()
{
	gluLookAt
	(
		m_CameraPosition.x, m_CameraPosition.y, m_CameraPosition.z,
		m_CameraPosition.x + m_CameraFacing.x, m_CameraPosition.y + m_CameraFacing.y, m_CameraPosition.z + m_CameraFacing.z,
		m_CameraNormal.x, m_CameraNormal.y, m_CameraNormal.z
	);
}

void Camera::LookAt(glm::vec3 _Position, glm::vec3 _Facing, glm::vec3 _Normal)
{
	gluLookAt
	(
		_Position.x, _Position.y, _Position.z,
		_Position.x + _Facing.x, _Position.y + _Facing.y, _Position.z + _Facing.z,
		_Normal.x, _Normal.y, _Normal.z
	);
}
