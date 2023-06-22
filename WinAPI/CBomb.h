#pragma once
#include "CGameObject.h"

class CBomb : public CGameObject
{
public:
	CBomb();
	virtual ~CBomb();

private:
	CAnimator* m_pBombAnimator;
	CAnimator* m_pSparkAnimator;
	CImage* m_pBombImage;
	CImage* m_pSparkImage;
	
	float m_fSpeed;
	float m_fCooltime;
	float m_fTimer;
	bool m_bIsTimesUP;

public:
	void BombTimer();
	void Boom();

	bool m_bIsPressE;
	bool m_bIsLeft;
	bool m_bIsRight;
	bool m_bIsUp;
	bool m_bIsDown;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;

};

