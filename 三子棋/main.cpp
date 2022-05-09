//*********************************************************//
//                                                         //
//      data:   2022-5-8                                   //
//      author: Akashi (����)                               //
//      github: https://github.com/AkashiNeko/C_Code       //
//      QQ:     1006554341                                 //
//                                                         //
//*********************************************************//

#include "game.h"
#include <conio.h>

void game(int model)
{
	char map[3][3] = {
		{P0,P0,P0},
		{P0,P0,P0},
		{P0,P0,P0}
	};
	int state;
	printMap(map);
	switch (model)
	{
	case 0: //�����
		while (1)
		{
			player_chess(map); //�������
			state = game_state(map);
			if (state)
				break;
			computer_chess(map);
			printPiece(map);
			state = game_state(map); //��������
			if (state)
				break;
		}
		break;
	case 1:
		while (1)
		{
			computer_chess(map);
			printPiece(map);
			state = game_state(map); //��������
			if (state)
				break;
			player_chess(map); //�������
			state = game_state(map);
			if (state)
				break;
		}
		break;
	}
	Sleep(500);
	system("cls");
	switch (state)
	{
	case plr_win:
		cout << "���ʤ����";
		break;
	case cpt_win:
		cout << "����ʤ����";
		break;
	case draw:
		cout << "ƽ��";
		break;
	default:
		cout << "��ֵĴ���qwq?";
		break;
	}
	Sleep(3000);
	system("cls");
}

int main()
{
	int model;
	system("title ������    By AkashiNeko");
	srand((unsigned int)time(NULL)); //�����������
	do 
	{
		if (menu()) return 0;    //���˵�ѡ�񣨿�ʼ/�˳���
		model = model_select();  //ģʽѡ���Ⱥ��֣�
		game(model);			 //������Ϸ
		//game(1);
	} while (1);
	return 0;
}