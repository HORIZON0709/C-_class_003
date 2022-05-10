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

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CEnemy();
	~CEnemy();

public:		/* �����o�[�֐��錾 */
	void Init();					//������
	void Uninit();					//�I��
	void Input();					//����
	void Output();					//�o��

public:	/* �萔�̒�` */
	static const int MAX_ENEMY = 3;		//�G�̍ő吔
	static const int MIN_ENEMY = 1;		//�G�̍ŏ���

private:	/* �����o�[�ϐ��錾 */
	int m_nLife;	//�̗�
	int m_nAttack;	//�U����
};

#endif