//#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//
//#define ROW 11
//#define COL 11
//#define ���� 0
//#define ���ʤ�� 1
//
//int g_number_mine = (ROW - 1)*(COL - 1);	//�׵���������
//char map[ROW][COL];							//��ҿ����ĵ�ͼ
//char mine_map[ROW + 2][COL + 2];			//����
//
//void Init_map();							//��ʼ����ҿ����ĵ�ͼ
//void Init_mine_map(int input_count);		//��ʼ������
//void Print_map();							//��ӡ��ͼ
//void Print_mine_map();						//���������Ҫ�������ӡ����
//void Player_move(int row, int col);			//��ʾ����������꿪ʼ��Ϸ 1.�Ϸ���У��(�Ƿ�Խ��)2.�Ƿ��ظ�����,(�Ѿ��������)
//int Judge_mine_end(int row, int col);		//�ж��Ƿ����
//char Count_number_mine(int row, int col);	//ͳ����Χ�˸������׵ĸ���
//void Print_mine_number(int row, int col, int n);//����Χ�˸������׵�������ʾ�ڵ�ǰ������
//int Judge_win(int input_count);				//�ж��Ƿ��ʤ
