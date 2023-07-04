#pragma once
#include "CGameObject.h"

class CPlayer;

class CItem : public CGameObject
{
public:
	CItem();
	virtual ~CItem();

	virtual void Activate(CPlayer* pPlayer) = 0;

protected:
	CAnimator* m_pAnimator;
	CPlayer* pPlayer;
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

