#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;
class CPlayer;

class CTripleShot : public CGameObject
{
public:
	CTripleShot();
	virtual ~CTripleShot();

private:
	CAnimator* m_pAnimator;
	CImage* m_pTripleShotImage;
	CPlayer* pPlayer;
	
	float m_fTimer;
	bool m_bIsGetItem;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

