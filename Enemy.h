#pragma once
#include "Struct.h"
#include "EnemyBullet.h"

/// <summary>
/// “G
/// </summary>
class Enemy
{
public:
	//ƒƒ“ƒoŠÖ”
	//‰Šú‰»
	void Initialize();

	//XVˆ—
	void Update(int scene, int text_);

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
	void Draw(int scene, int enemyTutorial, int enemyBulletImage);

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

	//ƒ{ƒ€ƒQƒbƒg‚Å‚«‚é“G
	Zako bombEnemy_;

	//’e
	EnemyBullet* enemyBullet_;

    //“G‚ªŒ»‚ê‚é‚Ü‚Å‚ÌƒJƒEƒ“ƒg
	int enemyCount_;
};

