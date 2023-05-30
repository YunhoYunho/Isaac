#pragma once
#include "CGameObject.h"

class CNormalChest : public CGameObject
{
public:
	CNormalChest();
	virtual ~CNormalChest();

private:
	CAnimator* m_pAnimator;
	CImage* m_pNormalChestImage;
	CSound* pOpenSound = RESOURCE->LoadSound(L"ChestOpen", L"Sound\\Item\\chest_open.wav");

protected:
	void Open();
	void OpenSound();

	bool m_bIsOpen;
	float m_fTimer = 0;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

