#include "framework.h"
#include "CSceneEnding.h"
#include "CEndingImage.h"

CSceneEnding::CSceneEnding()
{
	fCooltime = 0;
	pEndingSound = nullptr;
}

CSceneEnding::~CSceneEnding()
{
}

void CSceneEnding::Init()
{
	pEndingSound = RESOURCE->LoadSound(L"EndingSound", L"Sound\\Scene\\theCalm.ogg");

	CEndingImage* pEndingImage= new CEndingImage;
	pEndingImage->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	AddGameObject(pEndingImage);
}

void CSceneEnding::Enter()
{
	SOUND->Play(pEndingSound, 0.5f, false);
}

void CSceneEnding::Update()
{
	fCooltime += DT;

	if (fCooltime > 6.0f)
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
}

void CSceneEnding::Render()
{
}

void CSceneEnding::Exit()
{
	SOUND->Stop(pEndingSound);
}

void CSceneEnding::Release()
{
}
