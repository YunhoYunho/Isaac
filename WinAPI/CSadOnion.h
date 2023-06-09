#pragma once
#include "CPassiveItem.h"

class CPlayer;

class CSadOnion : public CPassiveItem
{
public:
	CSadOnion();
	virtual ~CSadOnion();

	void Activate(CPlayer* pPlayer) override;

private:
	CImage* m_pSadOnionImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

