#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#define P0 ' '  //���̱���
#define P1 'X'  //�������
#define P2 'O'  //��������
#define P3 'x'  //Ԥ������

#define C0 0x0e //������ɫ
#define C1 0x0a //���������ɫ
#define C2 0x0c //����������ɫ
#define C3 0x08 //Ԥ��������ɫ

#define MENU_SLEEP 300 //�˵�ѡ���ӳ�

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

enum row { A, B, C, N };
enum state {
	cont,		//0-����
	plr_win,	//1=���ʤ
	cpt_win,	//2-����ʤ
	draw		//3-ƽ��
};

//������Ļ��ӡ����
void setrd(int x, int y);

//���˵�
bool menu();

//ģʽѡ��˵�  0-�����  1-������
int model_select();

//��ʼ������
void resetMap(char[3][3]);

//��ӡ����
void printMap(char[3][3]);

//��ӡ����
void printPiece(char[3][3]);

//�������
void player_chess(char[3][3]);

//��Ϸ״̬�ж�  0-���� 1-���ʤ 2-����ʤ 3-ƽ��
int game_state(char[3][3]);

//��������
void computer_chess(char[3][3]);


#endif