#include "framework.h"
#include "CCameraController.h"

#include "CInputManager.h"
#include "CCameraManager.h"

CCameraController::CCameraController()
{
}

CCameraController::~CCameraController()
{
}

void CCameraController::Init()
{
}

void CCameraController::Update()
{
	Controller();
	Mover();
}

void CCameraController::Render()
{
}

void CCameraController::Release()
{
}

void CCameraController::Controller()
{
	if (LMOUSEDOWN(false))
	{
		CAMERA->SetTargetPos(MOUSEWORLDPOS, 1);
	}

	Vector dir;
	if (BUTTONSTAY(VK_DELETE))
	{
		dir.x = -1;
	}
	else if (BUTTONSTAY(VK_NEXT))
		dir.x = 1;
	else dir.x = 0;

	if (BUTTONSTAY(VK_HOME))
		dir.y = -1;
	else if (BUTTONSTAY(VK_END))
		dir.y = 1;
	else
		dir.y = 0;

	CAMERA->Scroll(dir, m_fScrollSpeed);
}

void CCameraController::Mover()
{
	if (BUTTONDOWN(VK_F1))
	{
		CAMERA->SetTargetPos(Vector(640, 360), 0.1f);
	}

	if (BUTTONDOWN(VK_F2))
	{
		CAMERA->SetTargetPos(Vector(1920, 360), 0.1f);
	}

	if (BUTTONDOWN(VK_F3))
	{
		CAMERA->SetTargetPos(Vector(3200, 360), 0.1f);
	}

	if (BUTTONDOWN(VK_F4))
	{
		CAMERA->SetTargetPos(Vector(640, 1080), 0.1f);
	}

	if (BUTTONDOWN(VK_F5))
	{
		CAMERA->SetTargetPos(Vector(1920, 1080), 0.1f);
	}
}
