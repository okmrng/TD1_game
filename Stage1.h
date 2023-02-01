#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"
#include "Clear.h"

class Stage1
{
public:
	//メンバ関数
	
	void Initialize();

	void Update();

	void Draw();

	//メンバ変数
	Admission* admission_;

	Player* player_;

	Enemy* enemy_;

	Clear* clear_;
};

