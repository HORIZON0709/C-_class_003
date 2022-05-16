//===================================================
//
//���Ƃ���3[enemyHuman.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMYHUMAN_H_
#define _ENEMYHUMAN_H_

#include "enemy.h"

//********************************
//�l�^�̓G�̃N���X��`
//********************************
class CEnemyHuman : public CEnemy
{/* CEnemy�̔h���N���X */
public:		/* �ÓI�����o�֐��錾 */
	static int GetNumAll();	//�������擾

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CEnemyHuman();
	~CEnemyHuman()override;

public:		/* �����o�[�֐��錾 */
	void Init()override;	//������
	void Uninit()override;	//�I��
	void Input()override;	//����
	void Output()override;	//�o��

private:	/* �ÓI�����o�ϐ��錾 */
	static int m_nNumAll;	//����

private:	/* �����o�[�ϐ��錾 */
	int m_nSpeedWalk;	//�����X�s�[�h
};

#endif