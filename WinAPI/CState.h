#pragma once
class CState
{
public:
	CState();
	virtual ~CState();

	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;

	void SetState(wstring stateName);

private:
	wstring m_curStateName;
};

