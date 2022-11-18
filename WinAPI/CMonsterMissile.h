#pragma once
#include "CMissile.h"

enum class TearsState
{
	None,
	Hit,

	Size
};

class CMonsterMissile : public CMissile
{
public:
	CMonsterMissile();
	virtual ~CMonsterMissile();

private:
	Vector m_vecDir;
	float m_fVelocity;

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