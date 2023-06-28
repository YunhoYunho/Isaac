#pragma once
#include "CScene.h"

class CEndingImage;

class CSceneEnding : public CScene
{
public:
	CSceneEnding();
	virtual ~CSceneEnding();

	CSound* pEndingSound= RESOURCE->LoadSound(L"EndingSound", L"Sound\\Scene\\theCalm.ogg");
	float fCooltime = 0;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

