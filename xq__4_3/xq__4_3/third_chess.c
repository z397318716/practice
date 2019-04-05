//三子棋
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 3
#define COL 3
#define 玩家胜利 0
#define 电脑胜利 1
#define 棋盘满了 2
char chess_table[ROW][COL];

//初始化棋盘
void Init_chess_table()
{
	for (int row = 0; row < ROW; ++row)
	{
		for (int col = 0; col < COL; ++col)
		{
			chess_table[row][col] = ' ';
		}
	}
}
//打印棋盘
void Print_chess_table()
{
	printf("    0    1    2  \n");
	printf(" |----|----|----|\n");
	int i = 0;
	for (int row = 0; row < ROW; ++row)
	{
		printf("%d|  %c |  %c |  %c |\n", i, chess_table[row][0], chess_table[row][1], chess_table[row][2]);
		printf(" |----|----|----|\n");
		++i;
	}
}
//玩家落子
void Player_move()
{

	while (1){
		int row = 0;
		int col = 0;
		printf("玩家落子,请输入落子坐标:(中间用空格隔开)\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("非法输入,请重新输入\n");
		} else if (chess_table[row][col] != ' ')
		{
			printf("该位置已有子了,请重新落子\n");
		} else
		{
			chess_table[row][col] = 'x';
			break;
		}
	}
}
//电脑落子
void Computer_move()
{
	printf("电脑落子!\n");
	while (1)
	{
		srand((unsigned)time(NULL));
		int row = rand() % 3;
		int col = rand() % 3;
		loop:
		if (chess_table[row][col] == ' ')
		{
			chess_table[row][col] = 'o';
			break;
		}

		if ((row == (ROW - 1)) &&( col == (COL - 1) )&&chess_table[row][col]!=' ')
		{
			row = 0;
			col = 0;
			goto loop;
		}


		if ((col == (ROW - 1)) && chess_table[row][col] != ' ')
		{
			row += 1;
			col = 0;
			goto loop;
		}
		else{
			col += 1;
			goto loop;
		}
		
	}
}

//判断棋盘是否满了
int Full_chess_table()
{
	for (int row = 0; row < ROW; ++row){
		for (int col = 0; col < COL; ++col){
			if (chess_table[row][col] == ' ')
			{
				return 3;
			} 
		}
	}
	return 棋盘满了;
}

int Judge_winner()
{
	for (int row = 0; row < ROW; ++row)
	{
		if (chess_table[row][0] == chess_table[row][1] &&
			chess_table[row][0] == chess_table[row][2] &&
			chess_table[row][0] == 'x')
		{
			return 玩家胜利;
		} else if (chess_table[row][0] == chess_table[row][1] &&
			chess_table[row][0] == chess_table[row][2] &&
			chess_table[row][0] == 'o')
		{
			return 电脑胜利;
		}
	}
	for (int col = 0; col < COL; ++col)
	{
		if (chess_table[0][col] == chess_table[1][col] &&
			chess_table[0][col] == chess_table[2][col] &&
			chess_table[0][col] == 'x')
		{
			return 玩家胜利;

		} else if (chess_table[0][col] == chess_table[1][col] &&
			chess_table[0][col] == chess_table[2][col] &&
			chess_table[0][col] == 'o')
		{
			return 电脑胜利;
		}
	}
	if (chess_table[0][0] == chess_table[1][1] &&
		chess_table[0][0] == chess_table[2][2] &&
		chess_table[0][0] == 'x')
	{
		printf("玩家胜利!\n");
		return 玩家胜利;
	} else if (chess_table[0][0] == chess_table[1][1] &&
		chess_table[0][0] == chess_table[2][2] &&
		chess_table[0][0] == 'o')
	{
		return 电脑胜利;
	} else if (chess_table[0][2] == chess_table[1][1] &&
		chess_table[0][2] == chess_table[2][0] &&
		chess_table[0][2] == 'x')
	{
		return 玩家胜利;
	} else if (chess_table[0][2] == chess_table[1][1] &&
		chess_table[0][2] == chess_table[2][0] &&
		chess_table[0][2] == 'o')
	{
		return 电脑胜利;
	}
	//判断是否和棋
	while (1)
	{
		for (int row = 0; row < ROW; ++row){
			for (int col = 0; col < COL; ++col){
				if (chess_table[row][col] == ' ')
				{
					return 3;
					break;
				} else
				{
					break;
				}
			}
		}
	}
	return 棋盘满了;
}
int main()
{
	int a = 0;
	printf("输入1开始游戏,输入其它结束游戏\n");
	scanf("%d", &a);
	if (a == 1)
	{
		Init_chess_table();
		Print_chess_table();

		while (1)
		{

			Player_move();
			Print_chess_table();
			Judge_winner();


			if (Judge_winner() == 玩家胜利)
			{
				printf("玩家胜利!\n");
				break;
			} else if (Judge_winner() == 电脑胜利)
			{
				printf("电脑胜利!\n");
				break;
			} else if (Judge_winner() == 棋盘满了)
			{
				printf("棋盘满了!\n");
				break;
			}

			Computer_move();
			Print_chess_table();
			Judge_winner();

			if (Judge_winner() == 玩家胜利)
			{
				printf("玩家胜利!\n");
				break;
			} else if (Judge_winner() == 电脑胜利)
			{
				printf("电脑胜利!\n");
				break;
			} else if (Judge_winner() == 棋盘满了)
			{
				printf("棋盘满了!\n");
				break;
			}
		}
	} else
	{
		printf("退出\n");
	}

	system("pause");
	return 0;
}