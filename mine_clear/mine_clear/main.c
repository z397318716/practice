#define _CRT_SECURE_NO_WARNINGS
#include "mine.h"


void game()
{
	int input_count = 0;
	int count_mine = 0;
	int row = 0;
	int col = 0;

	printf("自定义雷的个数:\n");
	scanf("%d", &input_count);
	if (input_count < 1 || input_count >= g_number_mine)
	{
		printf("非法输入,请重新输入!\n");
	} else
	{
		Init_mine_map(input_count);
		Init_map();
		Print_map();
		while (1)
		{
			printf("请输入坐标:(中间用空格隔开)\n");
			scanf("%d %d", &row, &col);
			Player_move(row, col);
			if (Judge_mine_end(row, col) == 踩雷)
			{
				printf("踩雷了,游戏结束\n");
				Print_mine_map();
				break;
			} else
			{
				count_mine = Count_number_mine(row, col);
				Print_mine_number(row, col, count_mine);
				Print_map();
				if (Judge_win(input_count) == 玩家胜利)
				{
					printf("你赢了!\n");
					break;
				}
			}

		}
	}
}



int main()
{
	game();



	system("pause");
	return 0;

}