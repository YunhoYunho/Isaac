#pragma once
#include "CGameObject.h"

class CAnimator;
class CImage;

class CItemRock : public CGameObject
{
public:
	CItemRock();
	virtual ~CItemRock();

private:
	CAnimator* m_pAnimator;
	CImage* m_pItemRockImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;
};

