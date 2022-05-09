#include "game.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//设置屏幕打印坐标
void setrd(int x, int y)
{
	COORD rd;
	rd.X = x;
	rd.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
}

//主菜单
bool menu()
{
	SetConsoleTextAttribute(hConsole, 0x0e);
	setrd(10, 3);
	cout << "=== 三子棋 ===" << endl << endl;
	setrd(12, 5);
	cout << "1. 开始" << endl;
	setrd(12, 7);
	cout << "2. 退出" << endl;
	setrd(0, 0);
	while (1)
	{
		if (GetAsyncKeyState('1'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 5);
			cout << "1. 开始" << endl;
			Sleep(MENU_SLEEP);
			system("cls");
			return false;
		}
		else if (GetAsyncKeyState('2'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 7);
			cout << "2. 退出" << endl;
			Sleep(MENU_SLEEP);
			system("cls");
			SetConsoleTextAttribute(hConsole, 0x0f);
			return true;
		}
	}
}

//模式选择菜单  0-玩家先  1-电脑先
int model_select()
{
	SetConsoleTextAttribute(hConsole, 0x0e);
	setrd(12, 3);
	cout << "选择先后手";
	setrd(12, 5);
	cout << "1. 我先走";
	setrd(12, 7);
	cout << "2. 电脑先走";
	setrd(0, 0);
	while (1)
	{
		if (GetAsyncKeyState('1'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 5);
			cout << "1. 我先走" << endl;
			SetConsoleTextAttribute(hConsole, 0x0e);
			Sleep(MENU_SLEEP);
			system("cls");
			return 0;
		}
		else if (GetAsyncKeyState('2'))
		{
			SetConsoleTextAttribute(hConsole, 0x0b);
			setrd(12, 7);
			cout << "2. 电脑先走" << endl;
			SetConsoleTextAttribute(hConsole, 0x0e);
			Sleep(MENU_SLEEP);
			system("cls");
			return 1;
		}
	}
}

//初始化棋盘
void resetMap(char arr[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			arr[i][j] = P0;
}

//打印棋盘
void printMap(char map[3][3])
{
	SetConsoleTextAttribute(hConsole, C0);
	cout << endl;
	cout << "       1   2   3   " << endl;
	cout << "      --- --- ---  " << endl;
	cout << "   A |   |   |   | " << endl;
	cout << "      --- --- ---  " << endl;
	cout << "   B |   |   |   | " << endl;
	cout << "      --- --- ---  " << endl;
	cout << "   C |   |   |   | " << endl;
	cout << "      --- --- ---  " << endl;

}

//打印棋子
void printPiece(char map[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			switch (map[i][j]) //在棋盘上打印棋子
			{
			case P0:
				setrd(7 + j * 4, 3 + i * 2);
				cout << P0; 
				break;
			case P1:
				SetConsoleTextAttribute(hConsole, C1);
				setrd(7 + j * 4, 3 + i * 2);
				cout << P1;
				break;
			case P2:
				SetConsoleTextAttribute(hConsole, C2);
				setrd(7 + j * 4, 3 + i * 2);
				cout << P2;
				break;
			case P3:
				SetConsoleTextAttribute(hConsole, C3);
				setrd(7 + j * 4, 3 + i * 2);
				cout << P3;
				break;
			default:
				break;
			}
		}
}

//玩家下棋
void player_chess(char map[3][3])
{
	int i, s_x = N, s_y = N;
	setrd(3, 10);
	SetConsoleTextAttribute(hConsole, 0x08);
	cout << "请输入行标和列标";
	while (1) //接收输入坐标
	{
		if (GetAsyncKeyState('A')) //输入A
		{
			if (s_y == A) continue;
			setrd(0, 3);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "-> A";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(0, 5);
			cout << "   B";
			setrd(0, 7);
			cout << "   C";
			if (s_x == N)
			{
				for (i = 0; i < 3; i++)
				{
					//将第1行空白换为P3
					if (map[0][i] == P0) map[0][i] = P3;
					//将其他行P3换为空白
					if (map[1][i] == P3) map[1][i] = P0;
					if (map[2][i] == P3) map[2][i] = P0;
				}
			}
			else
			{
				//将第1行第s_x列空白换为P3
				if (map[0][s_x] == P0) map[0][s_x] = P3;
				//将其他行第s_x列P3换为空白
				if (map[1][s_x] == P3) map[1][s_x] = P0;
				if (map[2][s_x] == P3) map[2][s_x] = P0;
			}
			printPiece(map);
			s_y = A;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('B')) //输入B
		{
			if (s_y == B) continue;
			setrd(0, 5);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "-> B";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(0, 3);
			cout << "   A";
			setrd(0, 7);
			cout << "   C";
			if (s_x == N)
			{
				for (i = 0; i < 3; i++)
				{
					//将第2行空白换为P3
					if (map[1][i] == P0) map[1][i] = P3;
					//将其他行P3换为空白
					if (map[0][i] == P3) map[0][i] = P0;
					if (map[2][i] == P3) map[2][i] = P0;
				}
			}
			else
			{
				//将第2行第s_x列空白换为P3
				if (map[1][s_x] == P0) map[1][s_x] = P3;
				//将其他行第s_x列P3换为空白
				if (map[0][s_x] == P3) map[0][s_x] = P0;
				if (map[2][s_x] == P3) map[2][s_x] = P0;
			}
			printPiece(map);
			s_y = B;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('C')) //输入C
		{
			if (s_y == C) continue;
			setrd(0, 7);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "-> C";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(0, 3);
			cout << "   A";
			setrd(0, 5);
			cout << "   B";
			if (s_x == N)
			{
				for (i = 0; i < 3; i++)
				{
					//将第3行空白换为P3
					if (map[2][i] == P0) map[2][i] = P3;
					//将其他行P3换为空白
					if (map[1][i] == P3) map[1][i] = P0;
					if (map[0][i] == P3) map[0][i] = P0;
				}
			}
			else
			{
				//将第3行第s_x列空白换为P3
				if (map[2][s_x] == P0) map[2][s_x] = P3;
				//将其他行第s_x列P3换为空白
				if (map[1][s_x] == P3) map[1][s_x] = P0;
				if (map[0][s_x] == P3) map[0][s_x] = P0;
			}
			printPiece(map);
			s_y = C;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('1')) //输入1
		{
			if (s_x == 0) continue;
			setrd(7, 1);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "1";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(11, 1);
			cout << "2";
			setrd(15, 1);
			cout << "3";
			if (s_y == N)
			{
				for (i = 0; i < 3; i++)
				{
					//将第1列空白换为P3
					if (map[i][0] == P0) map[i][0] = P3;
					//将其他列P3换为空白
					if (map[i][1] == P3) map[i][1] = P0;
					if (map[i][2] == P3) map[i][2] = P0;
				}
			}
			else
			{
				//将第1列第s_y行空白换为P3
				if (map[s_y][0] == P0) map[s_y][0] = P3;
				//将其他列第s_y行P3换为空白
				if (map[s_y][1] == P3) map[s_y][1] = P0;
				if (map[s_y][2] == P3) map[s_y][2] = P0;
			}
			printPiece(map);
			s_x = 0;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('2')) //输入2
		{
			if (s_x == 1) continue;
			setrd(11, 1);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "2";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(7, 1);
			cout << "1";
			setrd(15, 1);
			cout << "3";
			if (s_y == N)
			{
				for (i = 0; i < 3; i++)
				{
					//将第2列空白换为P3
					if (map[i][1] == P0) map[i][1] = P3;
					//将其他列P3换为空白
					if (map[i][0] == P3) map[i][0] = P0;
					if (map[i][2] == P3) map[i][2] = P0;
				}
			}
			else
			{
				//将第2列第s_y行空白换为P3
				if (map[s_y][1] == P0) map[s_y][1] = P3;
				//将其他列第s_y行P3换为空白
				if (map[s_y][0] == P3) map[s_y][0] = P0;
				if (map[s_y][2] == P3) map[s_y][2] = P0;
			}
			printPiece(map);
			s_x = 1;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState('3')) //输入3
		{
			if (s_x == 2) continue;
			setrd(15, 1);
			SetConsoleTextAttribute(hConsole, 0x06);
			cout << "3";
			SetConsoleTextAttribute(hConsole, C0);
			setrd(7, 1);
			cout << "1";
			setrd(11, 1);
			cout << "2";
			if (s_y == N)
			{
				for (i = 0; i < 3; i++)
				{
					//将第3列空白换为P3
					if (map[i][2] == P0) map[i][2] = P3;
					//将其他列P3换为空白
					if (map[i][0] == P3) map[i][0] = P0;
					if (map[i][1] == P3) map[i][1] = P0;
				}
			}
			else
			{
				//将第3列第s_y行空白换为P3
				if (map[s_y][2] == P0) map[s_y][2] = P3;
				//将其他列第s_y行P3换为空白
				if (map[s_y][0] == P3) map[s_y][0] = P0;
				if (map[s_y][1] == P3) map[s_y][1] = P0;
			}
			printPiece(map);
			s_x = 2;
			setrd(0, 0);
			goto tips;
		}
		else if (GetAsyncKeyState(VK_RETURN)) //回车
		{
			if (s_y == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x0c);
				cout << "请输入行标(A,B,C)  ";
				setrd(0, 0);
				continue;
			}
			if (s_x == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x0c);
				cout << "请输入列标(1,2,3)  ";
				setrd(0, 0);
				continue;
			}
			if (map[s_y][s_x] != P3)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x0c);
				cout << "该位置已存在其他棋子";
				setrd(0, 0);
				continue;
			}
			break;
		}
		if (false)
		{
		tips:
			//未选择行标
			if (s_y == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x08);
				cout << "请输入行标(A,B,C)  ";
				setrd(0, 0);
				continue;
			}
			//未选择列标
			if (s_x == N)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x08);
				cout << "请输入列标(1,2,3)  ";
				setrd(0, 0);
				continue;
			}
			//选择处存在其他棋子
			if (map[s_y][s_x] != P3)
			{
				setrd(3, 10);
				SetConsoleTextAttribute(hConsole, 0x08);
				cout << "该位置已存在其他棋子";
				setrd(0, 0);
				continue;
			}
			//允许落子
			setrd(3, 10);
			SetConsoleTextAttribute(hConsole, 0x08);
			cout << "按下回车确定落子        ";
			setrd(0, 0);
		}
	} //接收坐标结束
	map[s_y][s_x] = P1;
	printPiece(map);
	Sleep(100);
	SetConsoleTextAttribute(hConsole, C0);
	switch (s_y)
	{
	case 0:
		setrd(0, 3);
		cout << "   A";
		break;
	case 1:
		setrd(0, 5);
		cout << "   B";
		break;
	case 2:
		setrd(0, 7);
		cout << "   C";
		break;
	default:
		return;
	}
	setrd(7, 1);
	cout << "1   2   3";
}

//游戏状态判断  0-继续 1-玩家胜 2-电脑胜 3-平局
int game_state(char map[3][3])
{
	int a, i, j;
	for (a = 0; a < 3; a++)
	{
		if (map[a][0] != P0 && map[a][0] == map[a][1] && map[a][1] == map[a][2]) //第a列棋子相同
			if (map[a][0] == P1) //第a行的棋子是P1
				return plr_win;
			else				 //第a行的棋子是P2
				return cpt_win;
		if (map[0][a] != P0 && map[0][a] == map[1][a] && map[1][a] == map[2][a]) //第a列棋子相同
			if (map[0][a] == P1) //第a列的棋子是P1
				return plr_win;
			else				 //第a列的棋子是P2
				return cpt_win;
	}
	//判断主对角线棋子
	if (map[0][0] != P0 && map[0][0] == map[1][1] && map[1][1] == map[2][2]) //主对角线棋子相同
		if (map[0][0] == P1) //主对角线的棋子是P1
			return plr_win;
		else				 //主对角线的棋子是P2
			return cpt_win;
	//判断副对角线棋子
	if (map[0][2] != P0 && map[0][2] == map[1][1] && map[1][1] == map[2][0]) //副对角线棋子相同
		if (map[0][2] == P1) //副对角线的棋子是P1
			return plr_win;
		else				 //副对角线的棋子是P2
			return cpt_win;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (map[i][j] == P0)
				return cont;
	return draw;
}

//电脑下棋
void computer_chess(char map[3][3])
{
	int i, j, space_num = 0;
	char* space[8];
	setrd(3, 10);
	SetConsoleTextAttribute(hConsole, 0x08);
	cout << "等待电脑下棋\t\t\t";
	setrd(0, 0);
	//中间没有子时，走中间
	if (map[1][1] == P0)
	{
		map[1][1] = P2;
		return;
	}
	//三点连线上有自己的两个子时
	for (i = 0; i < 3; i++)
	{
		//判断3行内是否有相同的自己的两子
		if (map[i][0] == P2 && map[i][2] == P0 && map[i][0] == map[i][1]) //i,0 = i,1
		{
			map[i][2] = P2;
			return;
		}
		if (map[i][1] == P2 && map[i][0] == P0 && map[i][1] == map[i][2]) //i,1 = i,2
		{
			map[i][0] = P2;
			return;
		}
		if (map[i][0] == P2 && map[i][1] == P0 && map[i][0] == map[i][2]) //i,0 = i,2
		{
			map[i][1] = P2;
			return;
		}
		//判断3列内是否有相同的自己的两子
		if (map[0][i] == P2 && map[2][i] == P0 && map[0][i] == map[1][i]) //0,i = 1,i
		{
			map[2][i] = P2;
			return;
		}
		if (map[1][i] == P2 && map[0][i] == P0 && map[1][i] == map[2][i]) //1,i = 2,i
		{
			map[0][i] = P2;
			return;
		}
		if (map[0][i] == P2 && map[1][i] == P0 && map[0][i] == map[2][i]) //0,i = 2,i
		{
			map[1][i] = P2;
			return;
		}
	}
	//判断主对角线上是否有相同的自己的两个子
	if (map[0][0] == P2 && map[2][2] == P0 && map[0][0] == map[1][1]) //0,0 = 1,1 -> 2,2
	{
		map[2][2] = P2;
		return;
	}
	if (map[1][1] == P2 && map[0][0] == P0 && map[1][1] == map[2][2]) //1,1 = 2,2 -> 0,0
	{
		map[0][0] = P2;
		return;
	}
	//判断副对角线上是否有相同的自己的两个子
	if (map[0][2] == P2 && map[2][0] == P0 && map[0][2] == map[1][1]) //0,2 = 1,1 -> 2,0
	{
		map[2][0] = P2;
		return;
	}
	if (map[1][1] == P2 && map[0][2] == P0 && map[1][1] == map[2][0]) //1,1 = 2,0 -> 0,2
	{
		map[0][2] = P2;
		return;
	}

	//三点连线上没有自己的两个子，且有玩家的两个子时
	for (i = 0; i < 3; i++)
	{
		//判断3行内是否有相同的对方的两子
		if (map[i][0] == P1 && map[i][2] == P0 && map[i][0] == map[i][1]) //i,0 = i,1
		{
			map[i][2] = P2;
			return;
		}
		if (map[i][1] == P1 && map[i][0] == P0 && map[i][1] == map[i][2]) //i,1 = i,2
		{
			map[i][0] = P2;
			return;
		}
		if (map[i][0] == P1 && map[i][1] == P0 && map[i][0] == map[i][2]) //i,0 = i,2
		{
			map[i][1] = P2;
			return;
		}
		//判断3列内是否有相同的对方的两子
		if (map[0][i] == P1 && map[2][i] == P0 && map[0][i] == map[1][i]) //0,i = 1,i
		{
			map[2][i] = P2;
			return;
		}
		if (map[1][i] == P1 && map[0][i] == P0 && map[1][i] == map[2][i]) //1,i = 2,i
		{
			map[0][i] = P2;
			return;
		}
		if (map[0][i] == P1 && map[1][i] == P0 && map[0][i] == map[2][i]) //0,i = 2,i
		{
			map[1][i] = P2;
			return;
		}
	}
	//判断主对角线上是否有相同的玩家的两个子
	if (map[0][0] == P1 && map[2][2] == P0 && map[0][0] == map[1][1]) //0,0 = 1,1 -> 2,2
	{
		map[2][2] = P2;
		return;
	}
	if (map[1][1] == P1 && map[0][0] == P0 && map[1][1] == map[2][2]) //1,1 = 2,2 -> 0,0
	{
		map[0][0] = P2;
		return;
	}
	//判断副对角线上是否有相同的玩家的两个子
	if (map[0][2] == P1 && map[2][0] == P0 && map[0][2] == map[1][1]) //0,2 = 1,1 -> 2,0
	{
		map[2][0] = P2;
		return;
	}
	if (map[1][1] == P1 && map[0][2] == P0 && map[1][1] == map[2][0]) //1,1 = 2,0 -> 0,2
	{
		map[0][2] = P2;
		return;
	}

	//三点连线上没有自己的两个子也没有玩家的两个子时
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (map[i][j] == P0)
			{
				space[space_num] = &map[i][j];
				space_num++;
			}
	if (space_num == 0)
		return;
	*space[rand() % space_num] = P2;
	SetConsoleTextAttribute(hConsole, C0);
}
