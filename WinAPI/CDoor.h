#pragma once
#include "CGameObject.h"

class CDoor : public CGameObject
{
public:
	CDoor();
	virtual ~CDoor();

private:
	CAnimator* m_pAnimator;
	//CSound* pOpenSound = RESOURCE->LoadSound(L"DoorOpen", L"Sound\\")

	void Open();

	bool m_bIsTouch;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

