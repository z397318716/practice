//������
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 3
#define COL 3
#define ���ʤ�� 0
#define ����ʤ�� 1
#define �������� 2
char chess_table[ROW][COL];

//��ʼ������
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
//��ӡ����
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
//�������
void Player_move()
{

	while (1){
		int row = 0;
		int col = 0;
		printf("�������,��������������:(�м��ÿո����)\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("�Ƿ�����,����������\n");
		} else if (chess_table[row][col] != ' ')
		{
			printf("��λ����������,����������\n");
		} else
		{
			chess_table[row][col] = 'x';
			break;
		}
	}
}
//��������
void Computer_move()
{
	printf("��������!\n");
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

//�ж������Ƿ�����
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
	return ��������;
}

int Judge_winner()
{
	for (int row = 0; row < ROW; ++row)
	{
		if (chess_table[row][0] == chess_table[row][1] &&
			chess_table[row][0] == chess_table[row][2] &&
			chess_table[row][0] == 'x')
		{
			return ���ʤ��;
		} else if (chess_table[row][0] == chess_table[row][1] &&
			chess_table[row][0] == chess_table[row][2] &&
			chess_table[row][0] == 'o')
		{
			return ����ʤ��;
		}
	}
	for (int col = 0; col < COL; ++col)
	{
		if (chess_table[0][col] == chess_table[1][col] &&
			chess_table[0][col] == chess_table[2][col] &&
			chess_table[0][col] == 'x')
		{
			return ���ʤ��;

		} else if (chess_table[0][col] == chess_table[1][col] &&
			chess_table[0][col] == chess_table[2][col] &&
			chess_table[0][col] == 'o')
		{
			return ����ʤ��;
		}
	}
	if (chess_table[0][0] == chess_table[1][1] &&
		chess_table[0][0] == chess_table[2][2] &&
		chess_table[0][0] == 'x')
	{
		printf("���ʤ��!\n");
		return ���ʤ��;
	} else if (chess_table[0][0] == chess_table[1][1] &&
		chess_table[0][0] == chess_table[2][2] &&
		chess_table[0][0] == 'o')
	{
		return ����ʤ��;
	} else if (chess_table[0][2] == chess_table[1][1] &&
		chess_table[0][2] == chess_table[2][0] &&
		chess_table[0][2] == 'x')
	{
		return ���ʤ��;
	} else if (chess_table[0][2] == chess_table[1][1] &&
		chess_table[0][2] == chess_table[2][0] &&
		chess_table[0][2] == 'o')
	{
		return ����ʤ��;
	}
	//�ж��Ƿ����
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
	return ��������;
}
int main()
{
	int a = 0;
	printf("����1��ʼ��Ϸ,��������������Ϸ\n");
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


			if (Judge_winner() == ���ʤ��)
			{
				printf("���ʤ��!\n");
				break;
			} else if (Judge_winner() == ����ʤ��)
			{
				printf("����ʤ��!\n");
				break;
			} else if (Judge_winner() == ��������)
			{
				printf("��������!\n");
				break;
			}

			Computer_move();
			Print_chess_table();
			Judge_winner();

			if (Judge_winner() == ���ʤ��)
			{
				printf("���ʤ��!\n");
				break;
			} else if (Judge_winner() == ����ʤ��)
			{
				printf("����ʤ��!\n");
				break;
			} else if (Judge_winner() == ��������)
			{
				printf("��������!\n");
				break;
			}
		}
	} else
	{
		printf("�˳�\n");
	}

	system("pause");
	return 0;
}