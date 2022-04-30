//2022-4-30
//by Akashi (氟氟)
//https://github.com/AkashiNeko/C_Code

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
	case 0: //玩家先
		while (1)
		{
			player_chess(map); //玩家下棋
			state = game_state(map);
			if (state)
				break;
			computer_chess(map);
			printPiece(map);
			state = game_state(map); //电脑下棋
			if (state)
				break;
		}
		break;
	case 1:
		while (1)
		{
			computer_chess(map);
			printPiece(map);
			state = game_state(map); //电脑下棋
			if (state)
				break;
			player_chess(map); //玩家下棋
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
		cout << "玩家胜利！";
		break;
	case cpt_win:
		cout << "电脑胜利！";
		break;
	case draw:
		cout << "平局";
		break;
	default:
		cout << "奇怪的错误qwq?";
		break;
	}
	Sleep(3000);
	system("cls");
}

int main()
{
	int model;
	srand((unsigned int)time(NULL)); //置随机数种子
	do 
	{
		if (menu()) return 0;    //主菜单选择（开始/退出）
		model = model_select();  //模式选择（先后手）
		game(model);			 //进入游戏
		//game(1);
	} while (1);
	return 0;
}