#include "framework.h"
#include "CState.h"

CState::CState()
{
}

CState::~CState()
{
}

void CState::SetState(wstring stateName)
{
	m_curStateName = stateName;
}
