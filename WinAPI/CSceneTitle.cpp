#include "framework.h"
#include "CSceneTitle.h"

#include "WinAPI.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CEventManager.h"
#include "CCameraManager.h"

#include "CTitleImage.h"

CSceneTitle::CSceneTitle()
{
}

CSceneTitle::~CSceneTitle()
{
}

void CSceneTitle::Init()
{
	CTitleImage* pTitle = new CTitleImage;
	pTitle->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	AddGameObject(pTitle);
}

void CSceneTitle::Enter()
{
	CAMERA->FadeIn(0.25f);

	SOUND->Play(pSound, 1.0f, false);
}

void CSceneTitle::Update()
{
	if (BUTTONDOWN(VK_F1))
	{
		CHANGESCENE(GroupScene::TileTool);
	}
	if (BUTTONDOWN(VK_SPACE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Loading, 0.25f);
	}
}

void CSceneTitle::Render()
{
	//RENDER->Text(L"press space to start",
	//	WINSIZEX * 0.5f - 100,
	//	WINSIZEY * 0.5f - 10,
	//	WINSIZEX * 0.5f + 100,
	//	WINSIZEY * 0.5f + 10,
	//	Color(0, 0, 0, 1.f),
	//	20.f);
}

void CSceneTitle::Exit()
{
	SOUND->Pause(pSound);
}

void CSceneTitle::Release()
{
}