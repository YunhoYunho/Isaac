#pragma once
#include "CDoor.h"

class CDoorControl : public CDoor
{
public:
	CDoorControl();
	virtual ~CDoorControl();

private:
	CImage* m_pNLCloseImage;
	CImage* m_pNLOpenImage;
	CImage* m_pNRCloseImage;
	CImage* m_pNROpenImage;

	CImage* m_pBLCloseImage;
	CImage* m_pBLOpenImage;
	CImage* m_pBRCloseImage;
	CImage* m_pBROpenImage;

	void RenderController();

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	void OnCollisionEnter(CCollider* pOtherCollider) override;
	void OnCollisionStay(CCollider* pOtherCollider) override;
	void OnCollisionExit(CCollider* pOtherCollider) override;
};

