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
		DELAYCHANGESCENE(GroupScene::StageLoading, 0.25f);
	}
}

void CSceneTitle::Render()
{
}

void CSceneTitle::Exit()
{
	SOUND->Pause(pSound);
}

void CSceneTitle::Release()
{
}