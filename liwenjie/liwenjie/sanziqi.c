
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<string.h>

#define Max_row 3
#define Max_col 3

char chess_board[Max_row][Max_col];
int menu(){
	printf("---------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("---------------\n");
	printf("����������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Init(){
	//������X��ʾ������ӣ�o��ʾ��������
	// ''��ʾδ����
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			chess_board[row][col] = ' ';
		}
	}
}
void Print(){
	for (int row = 0; row < Max_row; ++row){
		printf("| %c |%c |%c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != Max_row - 1){
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove(){
	printf("�������\n");
	while (1){
		printf("������һ������(row clo):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= Max_row || row < Max_row || col >= Max_col || col <= Max_col){
			printf("��������Ƿ���\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("������������Ѿ���ռ�ã�\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
void ComputerMove(){
	while (1){
		int row = rand() % Max_row;
		int col = rand() % Max_col;
		if (chess_board[row][col] != ' '){
			//���λ�ñ�ռ��
			//�������һ��
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
int IsFull(){
	for (int row = 0; row < Max_row; ++row){
		for (int col = 0; col < Max_col; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	//ֻҪ�ҵ�һ��λ��Ϊ' '����Ϊû��
	//����ð����е�λ�ö�����Ҳû���ֿո񣬴�ʱ��������
	return 1;
}
//����x�������ʤ
//����o��ʾ����ʤ
//����q��ʾ����
//����' ' ����δ�ֳ�ʤ����Ҳ���Ǻ��壬����������Ϸ
char CheckGameOver(){
	//���������
	for (int row = 0; row < Max_row; ++row){
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//���������
	for (int col = 0; col < Max_col; ++col){
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//���Խ���
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	if (IsFull()){
		return 'q';
	}
}
void Game(){
	//��������ʼ��һ������
	Init();
	char winner = ' ';
	while (1){
		//��ӡ����
		Print();
		//�������
		PlayerMove();
		//�����Ϸ����
		winner = CheckGameOver();
		if (winner != ' '){
			//�ֳ�ʤ�����ߺ���
			break;
		}
		//��������
		ComputerMove();
		//�����Ϸ����
		winner = CheckGameOver();
		if (winner != ' '){
			break;
		}
	}
	if (winner == 'x'){
		printf("���ʤ����\n");
	} else if (winner == 'o'){
		printf("����˵��Զ��²���\n");
	} else if (winner == 'q'){
		printf("�㻹����ˣ��͵������忪��\n");
	} else{
		printf("��������ˣ�\n");
	}
}
int main()
{
	while (1){
		int choice = menu();
		if (choice == 1){
			Game();
		} else if (choice == 0){
			printf("goodbye\n");
			break;
		} else {
			printf("������������\n");
		}
	}
	system("pause");
	return 0;
}