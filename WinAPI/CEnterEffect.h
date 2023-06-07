#pragma once
#include "CGameObject.h"

class CEnterEffect : public CGameObject
{
public:
	CEnterEffect();
	virtual ~CEnterEffect();

private:
	CAnimator* m_pAnimator;
	CImage* m_pEnterEffectImage;

	float m_fCooltime;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

