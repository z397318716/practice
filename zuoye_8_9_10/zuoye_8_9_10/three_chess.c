//// 1.�����ö�ά�����ʾ����
////2.��Ҫ�����̽��г�ʼ��(������԰������ʼ����ȫ�ǿո�)
////3.�ȴ�ӡһ������.
////4.�������,˳����һ����Ϸ�Ƿ����
////5.��������,˳����һ����Ϸ�Ƿ����
//
//#define _CRT_SECURE_NO_WARNINGS
//#define ROW 3
//#define COL 3
//#include<stdio.h>
//#include<stdlib.h>
////�˴���������ĳ���,��ö���ɺ�.
////����δ���Գ��������չ,�����Ҫ�޸������Ԫ�ظ���,ֱ���޸ĺ꼴��
//
//char g_chess_board[ROW][COL];
//// 1.�����ö�ά�����ʾ����
//
//void Init(){
//	// �����̽��г�ʼ��
//	for (int row = 0; row < ROW; ++row){
//		for (int col = 0; col < COL; ++col){
//			g_chess_board[row][col] = ' ';
//		}
//	}
//}
//
//void Print(){
//	//tu do ��ӡ����
//	for (int row = 0; row < ROW; ++row){
//		printf("| %c | %c | %c |\n", g_chess_board[row][0],
//			g_chess_board[row][1], g_chess_board[row][2]);
//		if (row == ROW - 1){
//			//�������һ�л����һ���߽�
//			break;
//		}
//		printf("|---|---|---|\n");
//	}
//}
//
//void PlayerMove(){
//	// �������
//	while (1){
//		//1.��ʾ�������һ������
//		printf("������(��������): ");
//		//2.��ȡ��ҵ�����
//		int row = -1;
//		int col = -1;
//		scanf("%d %d", &row, &col);
//		//3.����ҵ��������У��.(��ԶҲ��Ҫ�����û�������)
//		//     a).У������������Ƿ��Ǻ���Χ
//		//     b).��ҵ����������Ӧ��λ�����Ƿ��Ѿ�����
//		if (row < 0 || row >= ROW || col < 0 || col >= COL){
//			printf("���������Ƿ�,����������!\n");
//			continue;
//		}
//		//b).��ҵ����������Ӧ��λ�����Ƿ��Ѿ�����
//		if (g_chess_board[row][col] != ' '){
//			//��ǰλ�ñ�ռ��,��������
//			printf("��ǰλ���Ѿ�������,����������!\n");
//			continue;
//		}
//		//4.����������Ϸ�,�Ͱ������ϵĶ�Ӧλ����Ϊ 'x'
//		g_chess_board[row][col] = 'x';
//		break;
//	}
//}
//
////�������˷��� 1, û������ 0
//int IsFull(){
//	for (int row = 0; row < ROW; ++row){
//		for (int col = 0; col < COL; ++col){
//			if (g_chess_board[row][col] == ' '){
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//// ʹ�� x ��ʾ���,ʹ�� o ��ʾ����
////Լ�� CheckWinner ����,���� x ��ʾ���ʤ��
////������� o ��ʾ����ʤ��,����һ�� q ��ʾ����
////������� �ո� ��ʾʤ��δ��
//char CheckWinner(){
//	//�����Ϸ�Ƿ����
//	//1.�ȼ�����е��п��ǲ�������������һ��
//	for (int row = 0; row < ROW; ++row){
//		if (g_chess_board[row][0] == g_chess_board[row][1]
//			&& g_chess_board[row][0] == g_chess_board[row][2]
//			&& g_chess_board[row][0] != ' '){
//			return g_chess_board[row][0];
//		}
//	}
//	//2.�ڼ�����е����Ƿ�����һ��
//	for (int col = 0; col < COL; ++col){
//		if (g_chess_board[0][col] == g_chess_board[1][col]
//			&& g_chess_board[0][col] == g_chess_board[2][col]
//			&& g_chess_board[0][col] != ' '){
//			return g_chess_board[0][col];
//		}
//	}
//	//3.���Խ���
//	if (g_chess_board[0][0] == g_chess_board[1][1]
//		&& g_chess_board[0][0] == g_chess_board[2][2]
//		&& g_chess_board[0][0] != ' '){
//		return g_chess_board[0][0];
//	}
//	if (g_chess_board[2][0] == g_chess_board[1][1]
//		&& g_chess_board[2][0] == g_chess_board[0][2]
//		&& g_chess_board[2][0] != ' '){
//		return g_chess_board[2][0];
//	}
//	//4.����Ƿ����
//	if (IsFull()){
//		return 'q';
//	}
//	return 'f';
//}
//
//void ComputerMove(){
//	//��������,�������
//	//�����������һ����,���������һ����
//	//���������λ�����Ѿ�������,���ڲ���һ��
//	printf("���������!\n");
//	int row = 0;
//	int col = 0;
//	while (1){
//		row = rand() % ROW;//[0,2]
//		col = rand() % COL;//[0,2]
//		if (g_chess_board[row][col] == ' '){
//			g_chess_board[row][col] = 'o';
//			break;
//		}
//	}
//}
//int main(){
//	char winner = ' ';
//	Init();
//	while (1){
//		//3.�ȴ�ӡһ������.
//		Print();
//		//4.�������,˳����һ����Ϸ�Ƿ����
//		PlayerMove();
//		winner = CheckWinner();
//		if (winner != 'f'){
//			//��Ϸ����
//			break;
//		}
//		//5.��������,˳����һ����Ϸ�Ƿ����
//		ComputerMove();
//		winner = CheckWinner();
//		if (winner != 'f'){
//			//��Ϸ����
//			break;
//		}
//	}
//	if (winner == 'x'){
//		printf("��һ�ʤ!\n");
//	} else if (winner == 'o'){
//		printf("���Ի�ʤ!\n");
//
//	} else if (winner == 'q'){
//		printf("����!\n");
//	}
//
//	system("pause");
//	return 0;
//}