#pragma once

#ifndef __GAME_H__
#define __GAME_H__

#define P0 ' '  //棋盘背景
#define P1 'X'  //玩家棋子
#define P2 'O'  //电脑棋子
#define P3 'x'  //预放棋子

#define C0 0x0e //棋盘颜色
#define C1 0x0a //玩家棋子颜色
#define C2 0x0c //电脑棋子颜色
#define C3 0x08 //预放棋子颜色

#define MENU_SLEEP 300 //菜单选择延迟

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

enum row { A, B, C, N };
enum state {
	cont,		//0-继续
	plr_win,	//1=玩家胜
	cpt_win,	//2-电脑胜
	draw		//3-平局
};

//设置屏幕打印坐标
void setrd(int x, int y);

//主菜单
bool menu();

//模式选择菜单  0-玩家先  1-电脑先
int model_select();

//初始化棋盘
void resetMap(char[3][3]);

//打印棋盘
void printMap(char[3][3]);

//打印棋子
void printPiece(char[3][3]);

//玩家下棋
void player_chess(char[3][3]);

//游戏状态判断  0-继续 1-玩家胜 2-电脑胜 3-平局
int game_state(char[3][3]);

//电脑下棋
void computer_chess(char[3][3]);


#endif