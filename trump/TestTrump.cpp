#include"stdafx.h"
#include"TestTrump.h"


Yamahuda::Yamahuda()
{
	MakeYamahuda();

}

Trump Yamahuda::Draw()
{
	int drawNum;
	//すでに使った数以外が出るまで乱数を回す
	do
	{
		 drawNum = RandomKaesu();
	} 
	while (find(Sutehuda.begin(), Sutehuda.end(), drawNum) != Sutehuda.end());
	//そこのカードをとってくる
	Trump card = m_Yamahuda.at(drawNum);
	//捨て札に追加
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
		//1~52を1~13に修正
		int CardNum = (i % 13 == 0 ? 13 : i % 13);
		string cardPattern;
		
		if (i <= 13)
			cardPattern = "スペードの";

		else if (i <= 26)
			cardPattern = "クラブの";

		else if (i <= 39)
			cardPattern = "ハートの";

		else if (i <= 52)
			cardPattern = "ダイヤの";

		//ex)"スペードの"+"1"
		Trump card={ i,cardPattern + to_string(CardNum) };
		m_Yamahuda.emplace_back(card);
	}
	Trump joker{ 53,"ジョーカー" };
	
}

void battle(int PlayerANum, int PlayerBNum)
{
	int returnNum;
	//ジョーカーの処理
	if (PlayerANum == 53 || PlayerBNum == 53)
	{
		PlayerANum == 53 ? cout << "プレイヤーAの勝ち!" << endl : cout << "プレイヤーBの勝ち!" << endl;
		return;
	}

	//13の剰余を取れば、1~13,14~26,27~39,40~52の数値が対等条件で揃う
	int battleNumA = PlayerANum % 13;
	int	battleNumB = PlayerBNum % 13;

	//同数になった場合の絵柄勝負 スペード,クラブ,ハート,ダイヤの順に数値が大きくなるので勝敗はその逆
	if (battleNumA == battleNumB)
	{
		PlayerANum < PlayerBNum ? cout << "プレイヤーAの勝ち!" << endl : cout << "プレイヤーBの勝ち!" << endl;
		return;
	}

	//以下、同数にならなかった場合

	//13を引けば勝ち
	if (battleNumA == 0 || battleNumB == 0)
	{
		battleNumA == 0 ? cout << "プレイヤーAの勝ち!" << endl : cout << "プレイヤーBの勝ち!" << endl;
		return;
	}

	//13以外なら剰余の値が大きい方の勝ち
	else
		battleNumA>battleNumB ? cout << "プレイヤーAの勝ち!" << endl : cout << "プレイヤーBの勝ち!" << endl;

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
		cout << "プレイヤー名をつけてください。" << endl;
		return;
	}

	if (myHand.CardName.empty())
	{
		cout << "カードを引いてください" << endl;
		return;
	}
	cout << PlayerName << ":" << myHand.CardName << endl;
}
