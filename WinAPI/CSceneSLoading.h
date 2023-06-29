#pragma once
#include "CScene.h"

class CSLoadingImage;

class CSceneSLoading : public CScene
{
public:
	CSceneSLoading();
	virtual ~CSceneSLoading();

	CSound* pSLoading;
	float fCooltime = 0;

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

