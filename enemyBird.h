//===================================================
//
//���Ƃ���3[enemyBird.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMYBIRD_H_
#define _ENEMYBIRD_H_

#include "enemy.h"

//********************************
//���^�̓G�̃N���X��`
//********************************
class CEnemyBird : public CEnemy
{/* CEnemy�̔h���N���X */
public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CEnemyBird();
	~CEnemyBird();

public:		/* �����o�[�֐��錾 */
	void Init();	//������
	void Uninit();	//�I��
	void Input();	//����
	void Output();	//�o��

private:	/* �����o�[�ϐ��錾 */
	int m_nSpeedFly;	//��s�X�s�[�h
};

#endif