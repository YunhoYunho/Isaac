#include "framework.h"
#include "CSceneEnding.h"
#include "CEndingImage.h"

CSceneEnding::CSceneEnding()
{
	fCooltime = 0;
}

CSceneEnding::~CSceneEnding()
{
}

void CSceneEnding::Init()
{
	CEndingImage* pEndingImage= new CEndingImage;
	pEndingImage->SetPos(WINSIZEX / 2, WINSIZEY / 2);
	AddGameObject(pEndingImage);
}

void CSceneEnding::Enter()
{
	SOUND->Play(pEndingSound, 1.0f, false);
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
