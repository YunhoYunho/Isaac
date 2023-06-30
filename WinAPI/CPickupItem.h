#pragma once
#include "CGameObject.h"

class CImage;
class CPlayer;

class CPickupItem : public CGameObject
{
	friend CPlayer;
public:
	CPickupItem();
	virtual ~CPickupItem();

	virtual void Activate(CPlayer* pPlayer) = 0;

protected:
	CAnimator* m_pAnimator;
	CPlayer* pPlayer;

	float m_fTimer;
	bool m_bIsContact = false;

	void Contact();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

