#define _CRT_SECURE_NO_WARNINGS
#include "mine.h"


void game()
{
	int input_count = 0;
	int count_mine = 0;
	int row = 0;
	int col = 0;

	printf("�Զ����׵ĸ���:\n");
	scanf("%d", &input_count);
	if (input_count < 1 || input_count >= g_number_mine)
	{
		printf("�Ƿ�����,����������!\n");
	} else
	{
		Init_mine_map(input_count);
		Init_map();
		Print_map();
		while (1)
		{
			printf("����������:(�м��ÿո����)\n");
			scanf("%d %d", &row, &col);
			Player_move(row, col);
			if (Judge_mine_end(row, col) == ����)
			{
				printf("������,��Ϸ����\n");
				Print_mine_map();
				break;
			} else
			{
				count_mine = Count_number_mine(row, col);
				Print_mine_number(row, col, count_mine);
				Print_map();
				if (Judge_win(input_count) == ���ʤ��)
				{
					printf("��Ӯ��!\n");
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