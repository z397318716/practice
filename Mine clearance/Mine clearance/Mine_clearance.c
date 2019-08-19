//#include "Mine_clearance.h"
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
//}
//
////初始化雷阵
//void Init_mine_map(int input_count)
//{
//	for (int row = 0; row < ROW; ++row)
//	{
//		for (int col = 0; col < COL; ++col)
//		{
//			mine_map[row][col] = ' ';
//		}
//	}
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < input_count; ++i)
//	{
//
//		int row = rand() % (ROW - 1) + 1;
//		int col = rand() % (COL - 1) + 1;
//		while (1)
//		{
//			if (mine_map[row][col] == 'x' && row == (ROW - 1) && col == (COL - 1))
//			{
//				row = 1;
//				col = 1;
//			} else if (mine_map[row][col] == 'x' && (col == COL - 1))
//			{
//				row += 1;
//				col = 1;
//			} else if (mine_map[row][col] == 'x' && (col < COL - 1))
//			{
//				col++;
//			} else
//			{
//				mine_map[row][col] = 'x';
//
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
//
////如果踩雷需要把雷阵打印出来
//void Print_mine_map()
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
//			printf("|  %c  ", mine_map[row][col]);
//		}
//		printf("|%d\n", i);
//		for (int b = 1; b < ROW; ++b)
//		{
//			printf("|-----");
//		}
//		printf("|");
//		printf("\n");
//		i = i + 1;
//	}
//}
//
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
//int Judge_mine_end(int row, int col)
//{
//	if (map[row][col] == 'o'&&mine_map[row][col] == 'x')
//	{
//		return 踩雷;
//	}
//	return 1;
//}
//
////统计周围八个方块雷的个数
//char Count_number_mine(int row, int col)
//{
//	int n = 0;
//	for (int i = -1; i < 2; ++i)
//	{
//		for (int j = -1; j < 2; ++j)
//		{
//			if (mine_map[row + i][col + j] == 'x')
//			{
//				n += 1;
//			}
//		}
//	}
//	return n;
//}
////将周围八个方块雷的数量显示在当前方块上
//void Print_mine_number(int row, int col, int n)
//{
//	char num_mine[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
//	switch (n){
//	case 0:
//		map[row][col] = num_mine[0];
//		break;
//	case 1:
//		map[row][col] = num_mine[1];
//		break;
//	case 2:
//		map[row][col] = num_mine[2];
//		break;
//	case 3:
//		map[row][col] = num_mine[3];
//		break;
//	case 4:
//		map[row][col] = num_mine[4];
//		break;
//	case 5:
//		map[row][col] = num_mine[5];
//		break;
//	case 6:
//		map[row][col] = num_mine[6];
//		break;
//	case 7:
//		map[row][col] = num_mine[7];
//		break;
//	case 8:
//		map[row][col] = num_mine[8];
//		break;
//	default:
//		printf("雷数非法\n");
//		break;
//	}
//}
//
//int Judge_win(int input_count)
//{
//	int num_mine = 0;
//	for (int row = 1; row < ROW; ++row)
//	{
//		for (int col = 1; col < COL; ++col)
//		{
//			if (map[row][col] != ' ')
//			{
//				num_mine += 1;
//			}
//		}
//	}
//	if (num_mine == (ROW - 1)*(COL - 1) - input_count)
//	{
//		return 玩家胜利;
//	}
//	return 2;
//}
//
