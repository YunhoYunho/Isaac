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

	float m_fCooltime;
	bool m_bIsTimesUP;

public:
	void BombTimer();
	void Boom();

	bool m_bIsPressE;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

