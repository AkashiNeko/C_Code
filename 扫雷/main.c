//**********************************************************//
//															//
//		data:   2022-5-8									//
//		author: Akashi (����)								//
//		github: https://github.com/AkashiNeko/C_Code		//
//		gitee:  https://gitee.com/AkashiNeko/C_Code			//
//		QQ:     1006554341									//
//															//
//**********************************************************//

#include "game.h"

HANDLE h;

void setrd(int x, int y)
{
	COORD rd;
	rd.X = x;
	rd.Y = y;
	SetConsoleCursorPosition(h, rd);
}

void setcl(int color)
{
	SetConsoleTextAttribute(h, color);
}

int game(short map[COL_MAX][COL_MAX], int size, int mine)
{
	int play_ret;
	//��ӡ��ͼ
	do
	{
		short display[COL_MAX][COL_MAX]; //�Ƿ���ʾ�����֣�
		print_map(map, size, display);
		memset(display, 0, sizeof(display));
		memset(map, 0, sizeof(display)); //��ʼ��
		//������
		set_mine(map, size, mine);
		
		//��ʼ����
		initial_area(map, size, display);

		//��Ҳ���
		play_ret = play(map, size, display);
		if (play_ret == 1) //�˳�
			return 1;
		if (play_ret == 2) //�ؿ�
			continue;
	} while (1);

	return 0;
}
int main()
{
	short map[COL_MAX][COL_MAX];
	int size = 15, mine = 50, game_ret;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	system("title ɨ��       By AkashiNeko");
	memset(map, 0, sizeof(map)); //��ʼ��
	setcl(0x0f);
start:
	switch (menu())
	{
	case 0:
		//��ʼ
		game_ret = game(map, size, mine);
		if (game_ret)
		{
			setcl(0x0f);
			system("cls");
			goto start;
		}
		break;
	case 1:
		//����
		menu_set(&size, &mine);
		setcl(0x0f);
		system("cls");
		goto start;
		break;
	case 2:
		//�˳�
		return 0;
	}
	return 0;
}