////扫雷
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//
//#define ROW 10
//#define COL 10
//#define 踩雷 1
//
////玩家看到的地图
//char map[ROW][COL];
////雷阵
//char mine_map[ROW + 2][COL + 2];
//int g_number_mine = (ROW - 1)*(COL - 1);
//
//
////初始化玩家看到的地图
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
////初始化雷阵
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
////打印地图
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
////提示玩家输入坐标开始游戏
//// 1.合法性校验(是否越界
//// 2.是否重复输入,(已经输入过的)
//void Player_move(int row, int col)
//{
//
//	if (row < 1 || row >= ROW || col < 1 || col >= COL)
//	{
//		printf("非法输入!请重新输入\n");
//	} else if (map[row][col] == 'o')
//	{
//		printf("重复输入无效,请重新输入!\n");
//	} else
//	{
//		map[row][col] = 'o';
//	}
//}
//
////判断是否踩雷
//int Judge_end(int row, int col)
//{
//	if (map[row][col] == 'o'&&mine_map[row][col] == 'x')
//	{
//		printf("游戏结束\n");
//		return 踩雷;
//	}
//	return 0;
//}
//
////统计周围八个方块雷的个数,并将其显示在当前方块上
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
//		printf("自定义雷的个数:(1-50):\n");
//		scanf("%d", &n);
//		if (n < 0 || n >= g_number_mine)
//		{
//			printf("非法输入,请重新输入!\n");
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
//				printf("请输入坐标:(中间用空格隔开)\n");
//				scanf("%d %d", &row, &col);
//				Player_move(row, col);
//				if (Judge_end(row, col) == 踩雷)
//				{
//					printf("踩雷了,游戏结束\n");
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