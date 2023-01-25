#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"
#include "Clear.h"

/// <summary>
/// チュートリアル
/// </summary>
class Tutorial
{
public:
	//メンバ関数
	
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys"></param>
	/// <param name="preKeys"></param>
	/// <param name="WASDStile_"></param>
	/// <param name="directionStile_"></param>
	/// <param name="scene"></param>
	void Update(char* keys, char* preKeys, bool WASDStile_, bool directionStile_, int scene);

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="frameSide"></param>
	/// <param name="Plate"></param>
	/// <param name="WASDStile_"></param>
	/// <param name="directionStile_"></param>
	/// <param name="tutorialText1"></param>
	/// <param name="tutorialText2"></param>
	/// <param name="tutorialText3Direction"></param>
	/// <param name="tutorialText3WASD"></param>
	/// <param name="tutorialText4"></param>
	/// <param name="tutorialText5"></param>
	/// <param name="tutorialText7"></param>
	/// <param name="textBox"></param>
	/// <param name="tutorialText9"></param>
	/// <param name="tutorialText10Direction"></param>
	/// <param name="tutorialText10WASD"></param>
	/// <param name="scene"></param>
	/// <param name="tutorialBg"></param>
	void Draw(int frameSide, int Plate, bool WASDStile_, bool directionStile_, int tutorialText1, int tutorialText2,
		int tutorialText3Direction, int tutorialText3WASD, int tutorialText4, int tutorialText5, int tutorialText7, int textBox,
		int tutorialText9, int tutorialText10Direction, int tutorialText10WASD, int tutorialText11, int tutorialText12, 
		int tutorialText13, int tutorialText14, int scene, int tutorialBg,int bombBullet);

	//メンバ変数
	//ステージ入場演出
	Admission* admission_;

	//自機
	Player* player_;

	//敵
	Enemy* enemy_;

	//クリア演出
	Clear* clear_;

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