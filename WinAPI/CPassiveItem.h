#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;
class CPlayer;

class CPassiveItem : public CGameObject
{
	friend CPlayer;
public:
	CPassiveItem();
	virtual ~CPassiveItem();

	virtual void Activate(CPlayer* pPlayer) = 0;

protected:
	CAnimator* m_pAnimator;
	CPlayer* pPlayer;

	float m_fTimer = 0;
	int m_iCount = 0;
	bool m_bIsGetItem = false;

	void GetItem();
	void CheckColl(CCollider* pOtherCollider);

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

