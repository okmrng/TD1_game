#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"

class Tutorial
{
public:
	//メンバ関数
	//初期化
	void Initialize();

	//更新処理
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, int scene);

	//描画処理
	void Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
		int tutorialText3Direction, int tutorialText3WASD, int tutorialText4, int tutorialText5, int tutorialText7, int textBox,
		int tutorialText9, int tutorialText10Direction, int tutorialText10WASD, int scene, int tutorialBg);

	//メンバ変数
	//ステージ入場演出
	Admission* admission_;

	//自機
	Player* player_;

	//敵
	Enemy* enemy_;

	//弾
	int shotTime_;
	bool isEnemyShot_[5];
	bool isEnemyMove_[5];
	float enemyBulletX_[5];
	float enemyBulletY_[5];
	float enemyBulletR_[5];
	float enmeyBulletSpeed_;

	//テキストフラグ
	int text_;
	bool textDisplay_;

	//テキスト位置
	float textX_;
	float textY_;

	//入力カウント
	int pushCount_;

	//シーン遷移
	bool next_;

	//自機移動フラグ
	bool onPlayerMove_;

	//自機弾発射フラグ
	bool onPlayerShot_;

	//ボムフラグ
	bool onBomb_;

	//当たり判定
	float playerBullet_moveEnemyX_;
	float playerBullet_moveEnemyY_;
	float playerBullet_moveEnemyDis_;

};

