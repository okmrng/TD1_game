#pragma once
#include "Admission.h"
#include "Player.h"
#include "Enemy.h"
#include "Clear.h"

class Stage1
{
public:
	//�����o�֐�
	
	void Initialize();

	void Update();

	void Draw();

	//�����o�ϐ�
	Admission* admission_;

	Player* player_;

	Enemy* enemy_;

	Clear* clear_;
};

