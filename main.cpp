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
//�X�^�e�B�b�N�ϐ�
//********************************
namespace
{
CEnemy* s_apEnemy[CEnemy::MAX_ENEMY];	//�G���̃|�C���^
}// namespace�͂����܂�

//********************************
//�v���g�^�C�v�錾
//********************************
namespace
{
int SetNumEnemy();
CEnemy::ENEMY_TYPE SelectType();
void OutputNumEnemy();

void Init();
void Input();
void Output();
void Uninit();
}// namespace�͂����܂�

//===================================================
//���C���֐�
//===================================================
void main(void)
{
	//������
	Init();
	
	//����
	Input();

	//�o��
	Output();

	//�I��
	Uninit();

	//�I�����b�Z�[�W & Enter���͑҂�
	printf("\n\n �v���O�������I�����܂��B�����l�ł����B");
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
//�G�̐���ݒ�
//---------------------------------------------------
int SetNumEnemy()
{
	int nNumEnemy = 0;	//�G�̐��ݒ�p

	while (1)
	{
		//���b�Z�[�W
		printf("\n �G�̐���ݒ�( %d�`%d�̂܂� ) > ", CEnemy::MIN_ENEMY,CEnemy::MAX_ENEMY);
		scanf("%d", &nNumEnemy);

		if ((nNumEnemy >= CEnemy::MIN_ENEMY) && (nNumEnemy <= CEnemy::MAX_ENEMY))
		{//�͈͓�
			break;
		}

		/* �͈͊O */

		//���b�Z�[�W & Enter���͑҂�
		printf("\n ������ �͈͊O�ł� ������");
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}

	//��ʂ��N���A
	system("cls");

	return nNumEnemy;	//�ݒ肵���G�̐���Ԃ�
}

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
		printf("\n ������ �͈͊O�ł� ������");
		PressEnter();

		//��ʂ��N���A
		system("cls");
	}

	return selectType;	//�I�������G�̎�ނ�Ԃ�
}

//---------------------------------------------------
//�G�̐���\��
//---------------------------------------------------
void OutputNumEnemy()
{
	printf("\n\n �G�̑��� : [ %d ]", CEnemy::GetNumAll());
	printf("\n �l�^ : [ %d ]", CEnemyHuman::GetNumAll());
	printf("\n ���^ : [ %d ]", CEnemyBird::GetNumAll());
}

//---------------------------------------------------
//������
//---------------------------------------------------
void Init()
{
	for (int i = 0; i < CEnemy::MAX_ENEMY; i++)
	{//nullptr�ŏ���������
		if (s_apEnemy[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͂Ȃ��ꍇ */

		//�I��
		s_apEnemy[i]->Uninit();

		//�������̉��
		delete s_apEnemy[i];
		s_apEnemy[i] = nullptr;
	}
}

//---------------------------------------------------
//����
//---------------------------------------------------
void Input()
{
	//�G�̐���ݒ�
	int nNumEnemy = SetNumEnemy();

	for (int i = 0; i < nNumEnemy; i++)
	{
		if (s_apEnemy[i] != nullptr)
		{//NULL�`�F�b�N
			//�������̉��
			delete s_apEnemy[i];
			s_apEnemy[i] = nullptr;
		}

		//���̖ڂ��\��
		printf("\n �s %d�̖� �t", (i + 1));

		//�G�̎�ނ�I��
		CEnemy::ENEMY_TYPE type = SelectType();

		switch (type)
		{//�G�̎�ޖ��̏���
		case CEnemy::ENEMY_TYPE::HUMAN:		/* �l�^ */

			//�������̓��I�m��
			s_apEnemy[i] = new CEnemyHuman;
			break;

		case CEnemy::ENEMY_TYPE::BIRD:		/* ���^ */

			//�������̓��I�m��
			s_apEnemy[i] = new CEnemyBird;
			break;

		case CEnemy::ENEMY_TYPE::NONE:		/* �I��͈͊O */
		case CEnemy::ENEMY_TYPE::MAX:
		default:
			assert(false);
			break;
		}

		//������
		s_apEnemy[i]->Init();

		if (s_apEnemy[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//����
		s_apEnemy[i]->Input();

		//��ʂ��N���A
		system("cls");
	}
}

//---------------------------------------------------
//�o��
//---------------------------------------------------
void Output()
{
	for (int i = 0; i < CEnemy::GetNumAll(); i++)
	{
		if (s_apEnemy[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//�o��
		s_apEnemy[i]->Output();
	}

	//�G�̐���\��
	OutputNumEnemy();
}

//---------------------------------------------------
//�I��
//---------------------------------------------------
void Uninit()
{
	for (int i = 0; i < CEnemy::MAX_ENEMY; i++)
	{
		if (s_apEnemy[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͂Ȃ��ꍇ */

		//�I��
		s_apEnemy[i]->Uninit();

		//�������̉��
		delete s_apEnemy[i];
		s_apEnemy[i] = nullptr;
	}
}
}