#pragma once
#include "CDoor.h"

class CDoorFrame : public CDoor
{
public:
	CDoorFrame();
	virtual ~CDoorFrame();

private:
	CImage* m_pNLFrameImage;
	CImage* m_pNRFrameImage;

	CImage* m_pGLFrameImage;
	CImage* m_pGRFrameImage;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

