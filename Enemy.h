#pragma once
#include "Struct.h"

class Enemy
{
public:
	//ƒƒ“ƒoŠÖ”
	//‰Šú‰»
	void Initialize();

	//XVˆ—
	void Update();

	//“–‚½‚è”»’è
	//‰½‚à‚µ‚È‚¢“G
	void EnemyOnCollision(int playerBulletAttack);

	//ˆÚ“®‚·‚é“G
	void MoveEnemyOnCollision(int playerBulletAttack);

	//•`‰æˆ—
	void Draw();

	//ƒƒ“ƒo•Ï”
	//“G\‘¢‘Ì
	//‰½‚à‚µ‚È‚¢“G
	Zako enemy_;

	//ˆÚ“®‚·‚é“G
	Zako moveEnemy_;
};

