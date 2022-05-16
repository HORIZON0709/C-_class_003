//===================================================
//
//���Ƃ���3[enemy.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//********************************
//�G�̃N���X��`
//********************************
class CEnemy
{/* ��{�N���X */
public:		/* �񋓌^�̒�` */
	enum class ENEMY_TYPE
	{
		NONE = 0,
		HUMAN,	//�l�^
		BIRD,	//���^
		MAX,
	};

public:		/* �萔�̒�` */
	static const int MAX_ENEMY = 5;		//�G�̍ő吔
	static const int MIN_ENEMY = 1;		//�G�̍ŏ���

public:		/* �ÓI�����o�֐��錾 */
	static int GetNumAll();	//�G�̑������擾

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CEnemy();
	virtual ~CEnemy();

public:		/* �����o�֐��錾 */
	virtual void Init();	//������
	virtual void Uninit();	//�I��
	virtual void Input();	//����
	virtual void Output();	//�o��

private:	/* �ÓI�����o�ϐ��錾 */
	static int m_nNumAll;	//�G�̑���

private:	/* �����o�ϐ��錾 */
	int m_nLife;	//�̗�
	int m_nAttack;	//�U����
};

#endif