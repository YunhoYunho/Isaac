#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CTripleShot : public CGameObject
{
public:
	CTripleShot();
	virtual ~CTripleShot();

private:
	CAnimator* m_pAnimator;
	CImage* m_pTripleShotImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

