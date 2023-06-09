#pragma once
#include "CScene.h"
#include "CSLoadingImage.h"

class CSLoadingImage;

class CSceneSLoading : public CScene
{
public:
	CSceneSLoading();
	virtual ~CSceneSLoading();

	CSound* pSLoading = RESOURCE->LoadSound(L"SLoading", L"Sound\\Scene\\SLoading.ogg");

	float fCooltime = 0;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

