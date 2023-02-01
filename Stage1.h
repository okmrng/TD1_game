#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"
#include "Clear.h"

class Stage1
{
public:
	//ƒƒ“ƒoŠÖ”
	
	void Initialize();

	void Update();

	void Draw();

	//ƒƒ“ƒo•Ï”
	Admission* admission_;

	Player* player_;

	Enemy* enemy_;

	Clear* clear_;
};

