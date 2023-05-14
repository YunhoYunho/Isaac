#pragma once
#include "CScene.h"
#include "CLoadingImage.h"

class CLoadingImage;

class CSceneLoading : public CScene
{
public:
	CSceneLoading();
	virtual ~CSceneLoading();

	CSound* pLoading = RESOURCE->LoadSound(L"Loading", L"Sound\\Scene\\Loading.wav");

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
