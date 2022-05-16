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
public:		/* �ÓI�����o�֐��錾 */
	static int GetNumAll();	//�������擾

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CEnemyBird();
	~CEnemyBird()override;

public:		/* �����o�[�֐��錾 */
	void Init()override;	//������
	void Uninit()override;	//�I��
	void Input()override;	//����
	void Output()override;	//�o��

private:	/* �ÓI�����o�ϐ��錾 */
	static int m_nNumAll;	//����

private:	/* �����o�[�ϐ��錾 */
	int m_nSpeedFly;	//��s�X�s�[�h
};

#endif