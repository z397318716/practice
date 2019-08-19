//#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//
//#define ROW 11
//#define COL 11
//#define 踩雷 0
//#define 玩家胜利 1
//
//int g_number_mine = (ROW - 1)*(COL - 1);	//雷的数量上限
//char map[ROW][COL];							//玩家看到的地图
//char mine_map[ROW + 2][COL + 2];			//雷阵
//
//void Init_map();							//初始化玩家看到的地图
//void Init_mine_map(int input_count);		//初始化雷阵
//void Print_map();							//打印地图
//void Print_mine_map();						//如果踩雷需要把雷阵打印出来
//void Player_move(int row, int col);			//提示玩家输入坐标开始游戏 1.合法性校验(是否越界)2.是否重复输入,(已经输入过的)
//int Judge_mine_end(int row, int col);		//判断是否踩雷
//char Count_number_mine(int row, int col);	//统计周围八个方块雷的个数
//void Print_mine_number(int row, int col, int n);//将周围八个方块雷的数量显示在当前方块上
//int Judge_win(int input_count);				//判断是否获胜
