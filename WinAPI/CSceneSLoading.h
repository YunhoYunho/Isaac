#pragma once
#include "CScene.h"
#include "CSLoadingImage.h"

class CSLoadingImage;

class CSceneSLoading : public CScene
{
public:
	CSceneSLoading();
	virtual ~CSceneSLoading();

	//CSound* pLoading = RESOURCE->LoadSound(L"Loading", L"Sound\\Scene\\SLoading.wav");

	float fCooltime = 0;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

