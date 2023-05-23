#include "framework.h"
#include "CSceneSLoading.h"

#include "CSLoadingImage.h"

CSceneSLoading::CSceneSLoading()
{
	fCooltime = 0;
}

CSceneSLoading::~CSceneSLoading()
{
}

void CSceneSLoading::Init()
{
	CSLoadingImage* pLoading = new CSLoadingImage;
	pLoading->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	AddGameObject(pLoading);
}

void CSceneSLoading::Enter()
{
	CAMERA->FadeIn(0.25f);

	//SOUND->Play(pLoading, 1.0f, false);
}

void CSceneSLoading::Update()
{
	fCooltime += DT;

	if (fCooltime > 2.0f)
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Stage01, 0.25f);
	}
}

void CSceneSLoading::Render()
{
}

void CSceneSLoading::Exit()
{
	//SOUND->Pause(pLoading);
}

void CSceneSLoading::Release()
{
}
