#pragma once
#include "CMissile.h"

enum class TearsState
{
	None,
	Hit,

	Size
};

class CPlayerMissile : public CMissile
{
public:
	CPlayerMissile();
	virtual ~CPlayerMissile();

private:
	Vector m_vecDir;
	float m_fVelocity;
	float m_fDamage;

	float m_fTimer;

private:
	CAnimator* m_pAnimator;
	CImage* m_pTearsImage;

	TearsState m_state;

	bool m_bIsHit;

	TearsState m_tearsState;
	wstring stateTears;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;

public:
	void SetDir(Vector dir);
	void SetVelocity(float velocity);
};