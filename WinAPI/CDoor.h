#pragma once
#include "CGameObject.h"

class CDoor : public CGameObject
{
public:
	CDoor();
	virtual ~CDoor();

private:
	CAnimator* m_pAnimator;
	bool m_bIsTouch;

	void Open();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

