#pragma once
#include "Struct.h"
#include "EnemyBullet.h"

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

	//’P”­’e‚ğŒ‚‚Â“G
	void BulletEnemyOnCollision(int playerBulletAttack);

	//•¡”’e‚ğŒ‚‚Â“G
	void BulletsEnemyOnCollision(int playerBulletAttack);

	//•`‰æˆ—
	void Draw();

	//ƒƒ“ƒo•Ï”
	//“G\‘¢‘Ì
	//‰½‚à‚µ‚È‚¢“G
	Zako enemy_;

	//ˆÚ“®‚·‚é“G
	Zako moveEnemy_;

	//’P”­’e‚ğŒ‚‚Â“G
	Zako bulletEnemy_;

	//•¡”’e‚ğŒ‚‚Â“G
	Zako bulletsEnemy_;

	//’e
	EnemyBullet* enemyBullet_;
};

