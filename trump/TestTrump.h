#pragma once
#include<iostream>
#include<random>
#include<string>
#include<map>
using namespace std;

struct Trump
{
	int deifinitionNum; //1~53�̊���U�萔��
	string CardName;	//�X�y�[�h��1�ȂǁB�J�[�h��
};

class Yamahuda
{
private:
	vector<Trump>m_Yamahuda;
	vector<int>Sutehuda;

	//Init
	void MakeYamahuda();

public:
	Yamahuda();
	virtual ~Yamahuda() = default;

	Trump Draw();
	void CardReset();
};

class Player
{
private:
	Trump myHand;
	string PlayerName;
public:
	void showHand();
};