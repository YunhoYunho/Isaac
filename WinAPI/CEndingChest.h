#pragma once
#include "CGameObject.h"

class CEndingChest : public CGameObject
{
public:
	CEndingChest();
	virtual ~CEndingChest();

private:
	CAnimator* m_pAnimator;
	CImage* m_pEndingChestImage;
	bool m_bIsTouch;
	void SetTouch(bool touch) { m_bIsTouch = touch; }

public:
	bool GetTouch() { return m_bIsTouch; }

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};
