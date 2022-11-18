#pragma once
#include "CGameObject.h"

class CImage;
class CAnimator;

enum class ExplosionState
{
	None,
	Explosion,

	Size
};

class CExplosion : public CGameObject
{
public:
	CExplosion();
	virtual ~CExplosion();

private:
	CAnimator* m_pAnimator;
	CImage* m_pExplosionImage;

	ExplosionState m_stateEXplosion;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;

	bool m_bIsExplosion;

	float m_fSpeed = 200.0f;
	float m_fDamage;

	ExplosionState m_explosionState;
	wstring stateExplosion;

	bool Boom();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void AnimatorUpdate();

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

