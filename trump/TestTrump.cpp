#include"stdafx.h"
#include"TestTrump.h"


Yamahuda::Yamahuda()
{
	MakeYamahuda();

}

Trump Yamahuda::Draw()
{
	int drawNum;
	//���łɎg�������ȊO���o��܂ŗ�������
	do
	{
		 drawNum = RandomKaesu();
	} 
	while (find(Sutehuda.begin(), Sutehuda.end(), drawNum) != Sutehuda.end());
	//�����̃J�[�h���Ƃ��Ă���
	Trump card = m_Yamahuda.at(drawNum);
	//�̂ĎD�ɒǉ�
	Sutehuda.emplace_back(drawNum);

	return card;
}

void Yamahuda::CardReset()
{
	Sutehuda.clear();
}

void Yamahuda::MakeYamahuda()
{
	for (int i = 1; i <= 52; i++)
	{
		//1~52��1~13�ɏC��
		int CardNum = (i % 13 == 0 ? 13 : i % 13);
		string cardPattern;
		
		if (i <= 13)
			cardPattern = "�X�y�[�h��";

		else if (i <= 26)
			cardPattern = "�N���u��";

		else if (i <= 39)
			cardPattern = "�n�[�g��";

		else if (i <= 52)
			cardPattern = "�_�C����";

		//ex)"�X�y�[�h��"+"1"
		Trump card={ i,cardPattern + to_string(CardNum) };
		m_Yamahuda.emplace_back(card);
	}
	Trump joker{ 53,"�W���[�J�[" };
	
}

void battle(int PlayerANum, int PlayerBNum)
{
	int returnNum;
	//�W���[�J�[�̏���
	if (PlayerANum == 53 || PlayerBNum == 53)
	{
		PlayerANum == 53 ? cout << "�v���C���[A�̏���!" << endl : cout << "�v���C���[B�̏���!" << endl;
		return;
	}

	//13�̏�]�����΁A1~13,14~26,27~39,40~52�̐��l���Γ������ő���
	int battleNumA = PlayerANum % 13;
	int	battleNumB = PlayerBNum % 13;

	//�����ɂȂ����ꍇ�̊G������ �X�y�[�h,�N���u,�n�[�g,�_�C���̏��ɐ��l���傫���Ȃ�̂ŏ��s�͂��̋t
	if (battleNumA == battleNumB)
	{
		PlayerANum < PlayerBNum ? cout << "�v���C���[A�̏���!" << endl : cout << "�v���C���[B�̏���!" << endl;
		return;
	}

	//�ȉ��A�����ɂȂ�Ȃ������ꍇ

	//13�������Ώ���
	if (battleNumA == 0 || battleNumB == 0)
	{
		battleNumA == 0 ? cout << "�v���C���[A�̏���!" << endl : cout << "�v���C���[B�̏���!" << endl;
		return;
	}

	//13�ȊO�Ȃ��]�̒l���傫�����̏���
	else
		battleNumA>battleNumB ? cout << "�v���C���[A�̏���!" << endl : cout << "�v���C���[B�̏���!" << endl;

	return;

}


int RandomKaesu()
{
	random_device seed_gen;
	default_random_engine engine(seed_gen());
	uniform_int_distribution<> dist(1, 53);

	return dist(engine);
}

void Player::showHand()
{
	if (PlayerName.empty())
	{
		cout << "�v���C���[�������Ă��������B" << endl;
		return;
	}

	if (myHand.CardName.empty())
	{
		cout << "�J�[�h�������Ă�������" << endl;
		return;
	}
	cout << PlayerName << ":" << myHand.CardName << endl;
}
