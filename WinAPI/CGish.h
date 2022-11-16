#pragma once
#include "CMonster.h"

class CImage;
class CAnimator;

enum class GishState
{
	Move,
	Jump,
	Shot,
	Dead,

	Size
};

class CGish : public CMonster
{
public:
	CGish();
	virtual ~CGish();

private:
	CAnimator* m_pAnimator;
	CImage* m_pGishLeftImage;
	CImage* m_pGishRightImage;

	GishState m_stateGish;

	Vector m_vecMoveDir;
	Vector m_vecLookDir;

	GishState m_GishState;
	wstring stateGish;

	bool m_bIsJump;

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

