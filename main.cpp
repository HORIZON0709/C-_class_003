//===================================================
//
//���Ƃ���3[main.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "main.h"
#include "enemy.h"
#include "enemyHuman.h"
#include "enemyBird.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�萔�̒�`
//********************************
namespace
{

}// namespace�͂����܂�

//********************************
//�v���g�^�C�v�錾
//********************************
namespace
{
CEnemy::ENEMY_TYPE SelectType();
int SetNumEnemy();
}// namespace�͂����܂�

//===================================================
//���C���֐�
//===================================================
void main(void)
{
	//�|�C���^
	CEnemyHuman* pEnemyHuman = nullptr;		//�l�^�̓G
	CEnemyBird* pEnemyBird = nullptr;		//���^�̓G

	//�G�̎�ނ�I��
	CEnemy::ENEMY_TYPE type = SelectType();
	
	//�G�̐���ݒ�
	int nNumEnemy = SetNumEnemy();

	switch (type)
	{
	case CEnemy::ENEMY_TYPE::HUMAN:	/* �l�^ */

		if (pEnemyHuman == nullptr)
		{//NULL�`�F�b�N
			//�������̓��I�m��
			pEnemyHuman = new CEnemyHuman[nNumEnemy];
		}

		for (int i = 0; i < nNumEnemy; i++)
		{//������
			pEnemyHuman[i].Init();
		}

		for (int i = 0; i < nNumEnemy; i++)
		{//����
			pEnemyHuman[i].Input();
		}

		//��ʂ��N���A
		system("cls");

		for (int i = 0; i < nNumEnemy; i++)
		{//�o��
			printf("\n %d�̖�", (i + 1));	//���̖ڂ��\��
			pEnemyHuman[i].Output();
		}

		for (int i = 0; i < nNumEnemy; i++)
		{//�I��
			pEnemyHuman[i].Uninit();
		}

		if (pEnemyHuman != nullptr)
		{//NULL�`�F�b�N
			//�������̉��
			delete[] pEnemyHuman;
			pEnemyHuman = nullptr;
		}
		break;

	case CEnemy::ENEMY_TYPE::BIRD:

		if (pEnemyBird == nullptr)
		{//NULL�`�F�b�N
			//�������̓��I�m��
			pEnemyBird = new CEnemyBird[nNumEnemy];
		}

		for (int i = 0; i < nNumEnemy; i++)
		{//������
			pEnemyBird[i].Init();
		}

		for (int i = 0; i < nNumEnemy; i++)
		{//����
			pEnemyBird[i].Input();
		}

		//��ʂ��N���A
		system("cls");

		for (int i = 0; i < nNumEnemy; i++)
		{//�o��
			printf("\n %d�̖�", (i + 1));	//���̖ڂ��\��
			pEnemyBird[i].Output();
		}

		for (int i = 0; i < nNumEnemy; i++)
		{//�I��
			pEnemyBird[i].Uninit();
		}

		if (pEnemyBird != nullptr)
		{//NULL�`�F�b�N
			//�������̉��
			delete[] pEnemyBird;
			pEnemyBird = nullptr;
		}
		break;
	}

	//�I�����b�Z�[�W
	printf("\n �v���O�������I�����܂��B�����l�ł����B");

	//Enter���͑҂�
	PressEnter();
}

//===================================================
//Enter���͑҂�
//===================================================
void PressEnter()
{
	//Enter���͑҂�
	printf("\n\n Press Enter");
	rewind(stdin);
	getchar();
}

namespace
{
//---------------------------------------------------
//�G�̎�ނ�I��
//---------------------------------------------------
CEnemy::ENEMY_TYPE SelectType()
{
	CEnemy::ENEMY_TYPE selectType;	//�G�̎�ޑI��p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �s �G�̎�ނ�I�� �t");
		printf("\n [%d] �l�^",CEnemy::ENEMY_TYPE::HUMAN);
		printf("\n [%d] ���^", CEnemy::ENEMY_TYPE::BIRD);
		printf("\n �ԍ������ > ");
		scanf("%d", &selectType);

		if ((selectType > CEnemy::ENEMY_TYPE::NONE) && (selectType < CEnemy::ENEMY_TYPE::MAX))
		{//�͈͓�
			break;
		}

		/* �͈͊O */

		//���b�Z�[�W & Enter���͑҂�
		printf("\n\n ������ �͈͊O�ł� ������");
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}

	return selectType;	//�I�������G�̎�ނ�Ԃ�
}

//---------------------------------------------------
//�G�̐���ݒ�
//---------------------------------------------------
int SetNumEnemy()
{
	int nNumEnemy = 0;	//�G�̐��ݒ�p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �G�̐���ݒ�( %d�̂܂� ) > ",CEnemy::MAX_ENEMY);
		scanf("%d", &nNumEnemy);

		if ((nNumEnemy >= CEnemy::MIN_ENEMY) && (nNumEnemy <= CEnemy::MAX_ENEMY))
		{//�͈͓�
			break;
		}

		/* �͈͊O */

		//���b�Z�[�W & Enter���͑҂�
		printf("\n\n ������ �͈͊O�ł� ������");
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}

	//��ʂ��N���A
	system("cls");

	return nNumEnemy;	//�ݒ肵���G�̐���Ԃ�
}
}