#pragma once
#include "CGameObject.h"

class CImage;
class CPlayer;

class CPickupItem : public CGameObject
{
public:
	CPickupItem();
	virtual ~CPickupItem();

protected:
	CAnimator* m_pAnimator;
	CPlayer* pPlayer;

	float m_fTimer;
	bool m_bIsContact;

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

