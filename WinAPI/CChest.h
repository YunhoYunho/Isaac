#pragma once
#include "CGameObject.h"

class CChest : public CGameObject
{
public:
	CChest();
	virtual ~CChest();

protected:
	CAnimator* m_pAnimator;
	CSound* pOpenSound = RESOURCE->LoadSound(L"ChestOpen", L"Sound\\Item\\chest_open.wav");

	void Open();
	void OpenSound();
	void RandomItem();
	void ChoiceItem(int num);

	bool m_bIsOpen;
	bool m_bIsGolden;
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

