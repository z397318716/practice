////ɨ��
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//
//#define ROW 10
//#define COL 10
//#define ���� 1
//
////��ҿ����ĵ�ͼ
//char map[ROW][COL];
////����
//char mine_map[ROW + 2][COL + 2];
//int g_number_mine = (ROW - 1)*(COL - 1);
//
//
////��ʼ����ҿ����ĵ�ͼ
//void Init_map()
//{
//	for (int row = 0; row <= ROW; ++row)
//	{
//		for (int col = 0; col <= COL; ++col)
//		{
//			map[row][col] = ' ';
//		}
//	}
//
//}
//
////��ʼ������
//void Init_mine_map(int n)
//{
//	srand((unsigned)time(NULL));
//	for (int i = 0; i <= n; ++i)
//	{
//
//		int row = rand() % (ROW - 1) + 1;
//		int col = rand() % (COL - 1) + 1;
//		while (1)
//		{
//
//			if ((col < COL - 1) && mine_map[row][col] == 'x')
//			{
//				col++;
//			} else if ((col == COL - 1) && mine_map[row][col] == 'x')
//			{
//				row += 1;
//				col = 1;
//			} else if (row == ROW - 1 && col == COL&&mine_map[row][col] == 'x')
//			{
//				row = 1;
//				col = 1;
//			} else
//			{
//				mine_map[row][col] = 'x';
//				break;
//			}
//		}
//	}
//}
//
////��ӡ��ͼ
//void Print_map()
//{
//	for (int i = 1; i < ROW; ++i)
//	{
//		printf("   %d  ", i);
//	}
//	printf("\n|");
//	for (int j = 1; j < ROW; ++j)
//	{
//		printf("-----|");
//	}
//	printf("\n");
//	int i = 1;
//	for (int row = 1; row < ROW; ++row)
//	{
//		for (int col = 1; col < COL; ++col)
//		{
//			printf("|  %c  ", map[row][col]);
//		}
//		printf("|%d\n", i);
//		for (int b = 1; b < ROW; ++b)
//		{
//			printf("|-----");
//		}
//
//		printf("|");
//		printf("\n");
//		i = i + 1;
//	}
//}
////��ʾ����������꿪ʼ��Ϸ
//// 1.�Ϸ���У��(�Ƿ�Խ��
//// 2.�Ƿ��ظ�����,(�Ѿ��������)
//void Player_move(int row, int col)
//{
//
//	if (row < 1 || row >= ROW || col < 1 || col >= COL)
//	{
//		printf("�Ƿ�����!����������\n");
//	} else if (map[row][col] == 'o')
//	{
//		printf("�ظ�������Ч,����������!\n");
//	} else
//	{
//		map[row][col] = 'o';
//	}
//}
//
////�ж��Ƿ����
//int Judge_end(int row, int col)
//{
//	if (map[row][col] == 'o'&&mine_map[row][col] == 'x')
//	{
//		printf("��Ϸ����\n");
//		return ����;
//	}
//	return 0;
//}
//
////ͳ����Χ�˸������׵ĸ���,��������ʾ�ڵ�ǰ������
//int Count_number_mine(int row,int col)
//{
//	int n = 0;
//	for (int i = -1; i < 2; ++i)
//	{
//		for (int j = -1; j < 2; ++j)
//		{
//			if (mine_map[row+i][col+j] == 'x');
//			++n;
//		}
//	}
//	return n;
//}
//
//
//void Print_map_number()
//{
//	for (int i = 1; i < ROW; ++i)
//	{
//		printf("   %d  ", i);
//	}
//	printf("\n|");
//	for (int j = 1; j < ROW; ++j)
//	{
//		printf("-----|");
//	}
//	printf("\n");
//	int i = 1;
//	for (int row = 1; row < ROW; ++row)
//	{
//		for (int col = 1; col < COL; ++col)
//		{
//			printf("|  %d  ", map[row][col]);
//		}
//		printf("|%d\n", i);
//		for (int b = 1; b < ROW; ++b)
//		{
//			printf("|-----");
//		}
//
//		printf("|");
//		printf("\n");
//		i = i + 1;
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	int row = 0;
//	int col = 0;
//
//
//
//	while (1)
//	{
//
//
//		printf("�Զ����׵ĸ���:(1-50):\n");
//		scanf("%d", &n);
//		if (n < 0 || n >= g_number_mine)
//		{
//			printf("�Ƿ�����,����������!\n");
//		} else
//		{
//
//			Init_mine_map(n);
//			Init_map();
//			Print_map();
//
//			while (1)
//			{
//
//				printf("����������:(�м��ÿո����)\n");
//				scanf("%d %d", &row, &col);
//				Player_move(row, col);
//				if (Judge_end(row, col) == ����)
//				{
//					printf("������,��Ϸ����\n");
//					break;
//				}
//				else
//				{
//					Print_map();
//					map[row][col]=Count_number_mine(row, col);
//					//Print_map_number();
//				}
//
//			}
//
//
//		}
//	}
//
//	system("pause");
//	return 0;
//
//}