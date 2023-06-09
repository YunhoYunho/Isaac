#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;
class CPlayer;

class CPassiveItem : public CGameObject
{
public:
	CPassiveItem();
	virtual ~CPassiveItem();

protected:
	CAnimator* m_pAnimator;
	CPlayer* pPlayer;

	float m_fTimer = 0;
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

