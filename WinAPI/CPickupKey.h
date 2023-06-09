#pragma once
#include "CPickupItem.h"

class CPlayer;

class CPickupKey : public CPickupItem
{
public:
	CPickupKey();
	virtual ~CPickupKey();

	void Activate(CPlayer* pPlayer) override;

private:
	CImage* m_pKeyImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};
