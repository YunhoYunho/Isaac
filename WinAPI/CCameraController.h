#pragma once
#include "CGameObject.h"
class CCameraController : public CGameObject
{
public:
	CCameraController();
	virtual ~CCameraController();

private:
	float m_fMouseTime = 1;
	float m_fScrollSpeed = 2000.0f;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void Controller();
	void Mover();
};

