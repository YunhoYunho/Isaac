#pragma once

#include "resource.h"

//========================================
//##    ��������(�ν��Ͻ�, ������ �ڵ�)	##
//========================================

extern HINSTANCE hInst;
extern HWND hWnd;

//========================================
//##			������ ����				##
//========================================

#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1280
#define	WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//========================================
//##			���Ӿ� �׷�				##
//========================================

// Title - TileTool - StageLoading - Stage01 - BossLoading - BossStage

enum class GroupScene
{
	Title,

	TileTool,

	StageLoading,

	Stage01,

	Loading,

	StageBoss,

	Size,
};

//========================================
//##				���̾�				##
//========================================

enum class Layer
{
	Default,
	Tile,
	Ending,
	Loading,
	Title,
	GroundTile,
	Obstacle,
	Missile,
	Monster,
	MonsterMissile,
	Player,
	PlayerMissile,
	ItemRock,
	Item,
	Bomb,
	Explosion,

	PlayerHP,
	Ui,
	Size,
};

//========================================
//##				Ÿ��					##
//========================================

enum class TypeTile
{
	None,
	Ground,
	Platform,
	Wall,

	Size,
};

//========================================
//##				����				##
//========================================

enum class PlayerState
{
	Idle,
	Move,
	Shot,
	TakeHit,
	GetItem,

	Size,
};

enum class MonsterState
{
	Ready,
	Move,
	Shot,
	Jump,
	Dead,

	Size,
};
