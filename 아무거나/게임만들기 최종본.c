#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char Poseidon[9][9], Hades[9][9], Hide_Hades[9][9], coordinate[3];		//Poseidon : �� �༺, Hades : �� �༺, Hide_Hades : ȭ�鿡 ������ �� �༺, coordinate : ��ǥ ����
static int P_Score = 14, H_Score = 14, P_record = 0, H_record = 0;		// P_Score : �����̵� �༺ ����, H_Score : �ϵ��� �༺ ����, P_record : �����̵� ����, H_record : �ϵ��� ����

void display_ocean() {		//ocean�� ������ ȭ�鿡 ���
	int i, j;
	system("cls");
	printf("       Poseidon		        Hades \n  ");
	for (i = 1; i <= 2; i++) {
		for (j = 1; j < 10; j++)
			printf("%d ", j);
		printf("\t  ");
	}
	printf("\n");

	for (i = 0; i < 9; i++) {
		printf("%c ", i + 65);			//�� �༺ ���
		for (j = 0; j < 9; j++)
			printf("%c ", Poseidon[i][j]);
		printf("\t%c ", i + 65);		//�� �༺ ���
		for (j = 0; j < 9; j++)
			printf("%c ", Hide_Hades[i][j]);
		printf("\n");
	}
	printf("\n");
}
int check_input(char *direction) {		//�Է¹��� ��ǥ��(coordinate)�� ����(direction)�� �ùٸ� ������ üũ
	printf("��ǥ�� ������ �Է��ϼ��� : ");
	gets(coordinate, &coordinate[3]);

	*direction = coordinate[3];
	if (coordinate[0] >= 'A' && coordinate[0] <= 'I' && coordinate[1] >= '1' && coordinate[1] <= '9') {	// �߸��� ��ǥ���� Ȯ��,	ASCII�ڵ� (A~I : 65~73, 1~9 : 49~57)
		if (*direction == 'E' || *direction == 'W' || *direction == 'S' || *direction == 'N')			
			return 1;
		else {
			printf("���� ���� \n\n");
			return 0;
		}
	}
	else {
		printf("��ǥ�� ���� \n\n");
		return 0;
	}
}
void get_coordinate(int *row, int *column) {
	*row = coordinate[0] - 65;		//�Է¹��� ��ǥ��(coordinate)���� �� ��(0���� 8������ ��)���� �ٲ�
	*column = coordinate[1] - 49;	//�Է¹��� ��ǥ��(coordinate)���� �� ��(0���� 8������ ��)���� �ٲ�
}
int Poseidon_check_availability_and_deploy_ship(int row, int column, int shipsize, char ship, char direction) {		//ocean�� shipetype('C', 'B', 'F', 'S' �� �ϳ�)�� �Լ��� row, column, direction�� ��ġ �������� üũ
	int check;																										//���� ��ġ �����ϸ� ��ġ�� ���� 1 (true)�� return�ϰ�, ��ġ �������� ������ 0 (false)�� return

	switch (direction) {
	case 'E': {
		for (check = 0; check < shipsize; check++) {
			if (column + check > 8) {		//��ǥ�� �Ѿ�� ���
				printf("��ǥ�� �Ѿ \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row][column + check] = '#';
				return 0;
			}
			else if (Poseidon[row][column + check] != '#') {	// �Դ밡 ��ġ�� ���
				printf("�Դ��ħ ���� \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row][column + check] = '#';
				return 0;
			}
			else
				Poseidon[row][column + check] = ship;
		}
	} break;
	case 'W': {
		for (check = 0; check < shipsize; check++) {

			if (column - check < 0) {		//��ǥ�� �Ѿ ���
				printf("��ǥ�� �Ѿ \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row][column - check] = '#';
				return 0;
			}

			else if (Poseidon[row][column - check] != '#') {	// �Դ밡 ��ġ�� ���
				printf("�Դ��ħ ���� \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row][column - check] = '#';
				return 0;
			}
			else
				Poseidon[row][column - check] = ship;
		}
	} break;
	case 'S': {
		for (check = 0; check < shipsize; check++) {

			if (row + check > 8) {		//��ǥ�� �Ѿ ���
				printf("��ǥ�� �Ѿ \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row + check][column] = '#';
				return 0;
			}

			else if (Poseidon[row + check][column] != '#') {	// �Դ밡 ��ġ�� ���
				printf("�Դ��ħ ���� \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row + check][column] = '#';
				return 0;
			}
			Poseidon[row + check][column] = ship;
		}
	} break;
	case 'N': {
		for (check = 0; check < shipsize; check++) {

			if (row - check < 0) {		//��ǥ�� �Ѿ ���
				printf("��ǥ�� �Ѿ \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row - check][column] = '#';
				return 0;
			}

			else if (Poseidon[row - check][column] != '#') {		// �Դ밡 ��ġ�� ���
				printf("�Դ��ħ ���� \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row - check][column] = '#';
				return 0;
			}
			else
				Poseidon[row - check][column] = ship;
		}
	} break;
	}
	return 1;
}
void Poseidon_deploy_ship() {		//ocean�� shipetype('C', 'B', 'F', 'S' �� �ϳ�)�� �Լ��� row, column, direction�� ��ġ
	static int shipsize = 5;		//return���� ���� ������, ocean�� �迭�̱� ������ �Լ� �ȿ��� �����ϸ� �� ����� �ݿ���
	int row, column, check;
	char ship, direction = " ";

	//�Դ� ũ�� üũ & �Դ� ���� Ȯ��
	if (shipsize == 5) {
		printf("�װ������� ��ġ�ϰڽ��ϴ�.\n");
		ship = 'C';
	}
	else if (shipsize == 4) {
		printf("������ ��ġ�ϰڽ��ϴ�.\n");
		ship = 'B';
	}
	else if (shipsize == 3) {
		printf("�������� ��ġ�ϰڽ��ϴ�.\n");
		ship = 'F';
	}
	else if (shipsize == 2) {
		printf("������� ��ġ�ϰڽ��ϴ�.\n");
		ship = 'S';
	}
	else		//��� �Դ밡 ��ġ���� ���
		return;

	while (1) {
		while (1) {
			check = check_input(&direction);
			if (check == 1) break;
		}

		get_coordinate(&row, &column);
		check = Poseidon_check_availability_and_deploy_ship(row, column, shipsize, ship, direction);
		if (check == 1) break;
	}
	display_ocean();
	shipsize--;
	Poseidon_deploy_ship();
}
void get_random_coordinate(int *row, int *column, char *direction) {
	*row = rand() % 9;
	*column = rand() % 9;
	*direction = 49 + rand() % 4;
}
int Hades_check_availability_and_deploy_ship(int row, int column, int shipsize, char ship, char direction) {
	int check;

	switch (direction) {
	case '1': {
		for (check = 0; check < shipsize; check++) {
			if (column + check > 8) {		//��ǥ�� �Ѿ�� ���
				for (check -= 1; check >= 0; check--)
					Hades[row][column + check] = '#';
				return 0;
			}
			else if (Hades[row][column + check] != '#') {	// �Դ밡 ��ġ�� ���
				for (check -= 1; check >= 0; check--)
					Hades[row][column + check] = '#';
				return 0;
			}
			else
				Hades[row][column + check] = ship;
		}
	} break;
	case '2': {
		for (check = 0; check < shipsize; check++) {

			if (column - check < 0) {		//��ǥ�� �Ѿ ���
				for (check -= 1; check >= 0; check--)
					Hades[row][column - check] = '#';
				return 0;
			}

			else if (Hades[row][column - check] != '#') {	// �Դ밡 ��ġ�� ���
				for (check -= 1; check >= 0; check--)
					Hades[row][column - check] = '#';
				return 0;
			}
			else
				Hades[row][column - check] = ship;
		}
	} break;
	case '3': {
		for (check = 0; check < shipsize; check++) {

			if (row + check > 8) {		//��ǥ�� �Ѿ ���
				for (check -= 1; check >= 0; check--)
					Hades[row + check][column] = '#';
				return 0;
			}

			else if (Hades[row + check][column] != '#') {	// �Դ밡 ��ġ�� ���
				for (check -= 1; check >= 0; check--)
					Hades[row + check][column] = '#';
				return 0;
			}
			Hades[row + check][column] = ship;
		}
	} break;
	case '4': {
		for (check = 0; check < shipsize; check++) {

			if (row - check < 0) {		//��ǥ�� �Ѿ ���
				for (check -= 1; check >= 0; check--)
					Hades[row - check][column] = '#';
				return 0;
			}

			else if (Hades[row - check][column] != '#') {		// �Դ밡 ��ġ�� ���
				for (check -= 1; check >= 0; check--)
					Hades[row - check][column] = '#';
				return 0;
			}
			else
				Hades[row - check][column] = ship;
		}
	} break;
	}
	return 1;
}
void Hades_deploy_ship() {
	static int shipsize = 5;
	int row, column, direction, check;
	char ship;
	srand(time(NULL));

	if (shipsize == 5)
		ship = 'C';
	else if (shipsize == 4)
		ship = 'B';
	else if (shipsize == 3)
		ship = 'F';
	else if (shipsize == 2)
		ship = 'S';
	else {
		display_ocean();
		return;
	}

	while (1) {
		row = rand() % 9;
		column = rand() % 9;
		direction = 49 + rand() % 4;
		get_random_coordinate(&row, &column, &direction);
		check = Hades_check_availability_and_deploy_ship(row, column, shipsize, ship, direction);
		if (check == 1) break;
	}
	shipsize--;
	Hades_deploy_ship();
}
void Print_Score() {
	display_ocean();
	printf("���� : %02d \t\t���� : %02d\n", P_Score, H_Score);
}
void Poseidon_Attack(){
	int row, column;

	while (1) {
		printf("������ ��ǥ�� �Է��ϼ��� : ");
		gets(coordinate);
		
		row = coordinate[0] - 65;		//�Է¹��� ��ǥ��(coordinate)���� �� ��(0���� 8������ ��)���� �ٲ�
		column = coordinate[1] - 49;	//�Է¹��� ��ǥ��(coordinate)���� �� ��(0���� 8������ ��)���� �ٲ�
		if (row >= 0 && row <= 8 && column >= 0 && column <= 8) {
			if (Hide_Hades[row][column] != '#') {
				printf("�̹� �Է��� ��ǥ�Դϴ�.\n");
				continue;
			}
			else break;
		}
		else
			printf("�߸��� ��ǥ�Դϴ�.\n");
	}

	if (Hades[row][column] == '#')
		Hide_Hades[row][column] = 'X';
	else if (Hades[row][column] != 'X' && Hades[row][column] != '#') {
		Hide_Hades[row][column] = Hades[row][column];
		H_Score--;
	}
}
void Hades_Attack() {
	int row, column;

	while (1) {
		row = rand() % 9;
		column = rand() % 9;
		if (Poseidon[row][column] != 'X')
			break;
	}

	if (Poseidon[row][column] == '#')
		Poseidon[row][column] = 'X';
	else if (Poseidon[row][column] != 'X' && Poseidon[row][column] != '#') {
		Poseidon[row][column] = 'X';
		P_Score--;
	}
}
void War() {


	while (1) {
		Poseidon_Attack();
		Print_Score();
		Hades_Attack();
		Print_Score();

		if (P_Score == 0) {
			printf("Hades �༺ �¸�!!\n");
			H_record++;
			break;
		}
		else if (H_Score == 0) {
			printf("Poseidon �༺ �¸�!!\n");
			P_record++;
			break;
		}
	}
}
int main() {

	errno_t err;
	FILE *record;

	err = fopen_s(&record, "war data.txt", "w");

	//-------------------------------------------------���� ���----------------------------------------------------------
	printf("====================================\n");
	printf("��ɰ��� ȯ���մϴ�.\n");
	printf("====================================\n");
	printf("������� ��ɰ��� �� �༺ �ϵ��� ���� ����\n");
	printf("%d�� %d���Դϴ�.\n\n", P_record, H_record);

	system("pause");
	system("cls");


	int n1, n2;
	//-----------------------------------------------�༺ �ʱ� ����--------------------------------------------------------
	printf("       Poseidon		        Hades \n  ");
	for (n1 = 1; n1 <= 2; n1++) {
		for (n2 = 1; n2 < 10; n2++)
			printf("%d ", n2);
		printf("\t  ");
	}
	printf("\n");

	for (n1 = 0; n1 < 9; n1++) {
		printf("%c ", n1 + 65);			//�� �༺ ���
		for (n2 = 0; n2 < 9; n2++) {
			Poseidon[n1][n2] = '#';
			printf("%c ", Poseidon[n1][n2]);
		}
		printf("\t%c ", n1 + 65);		//�� �༺ ���
		for (n2 = 0; n2 < 9; n2++) {
			Hades[n1][n2] = '#';
			Hide_Hades[n1][n2] = Hades[n1][n2];
			printf("%c ", Hide_Hades[n1][n2]);
		}
		printf("\n");
	}
	printf("\n");
	Poseidon_deploy_ship();
	Hades_deploy_ship();
	War();

	fprintf(record, "������� ��ɰ��� �� �༺ �ϵ��� ���� ������\n");
	fprintf(record, "%d�� %d���Դϴ�.\n\n", P_record, H_record);

	fclose(record);

	getch();
	return 0;
}