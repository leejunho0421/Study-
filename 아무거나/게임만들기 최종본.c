#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char Poseidon[9][9], Hades[9][9], Hide_Hades[9][9], coordinate[3];		//Poseidon : 내 행성, Hades : 적 행성, Hide_Hades : 화면에 보여질 적 행성, coordinate : 좌표 지정
static int P_Score = 14, H_Score = 14, P_record = 0, H_record = 0;		// P_Score : 포세이돈 행성 점수, H_Score : 하데스 행성 점수, P_record : 포세이돈 전적, H_record : 하데스 전적

void display_ocean() {		//ocean의 내용을 화면에 출력
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
		printf("%c ", i + 65);			//내 행성 출력
		for (j = 0; j < 9; j++)
			printf("%c ", Poseidon[i][j]);
		printf("\t%c ", i + 65);		//적 행성 출력
		for (j = 0; j < 9; j++)
			printf("%c ", Hide_Hades[i][j]);
		printf("\n");
	}
	printf("\n");
}
int check_input(char *direction) {		//입력받은 좌표값(coordinate)과 방향(direction)이 올바른 값인지 체크
	printf("좌표와 방향을 입력하세요 : ");
	gets(coordinate, &coordinate[3]);

	*direction = coordinate[3];
	if (coordinate[0] >= 'A' && coordinate[0] <= 'I' && coordinate[1] >= '1' && coordinate[1] <= '9') {	// 잘못된 좌표인지 확인,	ASCII코드 (A~I : 65~73, 1~9 : 49~57)
		if (*direction == 'E' || *direction == 'W' || *direction == 'S' || *direction == 'N')			
			return 1;
		else {
			printf("방향 오류 \n\n");
			return 0;
		}
	}
	else {
		printf("좌표값 오류 \n\n");
		return 0;
	}
}
void get_coordinate(int *row, int *column) {
	*row = coordinate[0] - 65;		//입력받은 좌표값(coordinate)에서 행 값(0부터 8사이의 값)으로 바꿈
	*column = coordinate[1] - 49;	//입력받은 좌표값(coordinate)에서 열 값(0부터 8사이의 값)으로 바꿈
}
int Poseidon_check_availability_and_deploy_ship(int row, int column, int shipsize, char ship, char direction) {		//ocean에 shipetype('C', 'B', 'F', 'S' 중 하나)의 함선을 row, column, direction에 배치 가능한지 체크
	int check;																										//만약 배치 가능하면 배치한 다음 1 (true)를 return하고, 배치 가능하지 않으면 0 (false)를 return

	switch (direction) {
	case 'E': {
		for (check = 0; check < shipsize; check++) {
			if (column + check > 8) {		//좌표를 넘어가는 경우
				printf("좌표를 넘어감 \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row][column + check] = '#';
				return 0;
			}
			else if (Poseidon[row][column + check] != '#') {	// 함대가 겹치는 경우
				printf("함대겹침 오류 \n\n");
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

			if (column - check < 0) {		//좌표를 넘어갈 경우
				printf("좌표를 넘어감 \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row][column - check] = '#';
				return 0;
			}

			else if (Poseidon[row][column - check] != '#') {	// 함대가 겹치는 경우
				printf("함대겹침 오류 \n\n");
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

			if (row + check > 8) {		//좌표를 넘어갈 경우
				printf("좌표를 넘어감 \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row + check][column] = '#';
				return 0;
			}

			else if (Poseidon[row + check][column] != '#') {	// 함대가 겹치는 경우
				printf("함대겹침 오류 \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row + check][column] = '#';
				return 0;
			}
			Poseidon[row + check][column] = ship;
		}
	} break;
	case 'N': {
		for (check = 0; check < shipsize; check++) {

			if (row - check < 0) {		//좌표를 넘어갈 경우
				printf("좌표를 넘어감 \n\n");
				for (check -= 1; check >= 0; check--)
					Poseidon[row - check][column] = '#';
				return 0;
			}

			else if (Poseidon[row - check][column] != '#') {		// 함대가 겹치는 경우
				printf("함대겹침 오류 \n\n");
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
void Poseidon_deploy_ship() {		//ocean에 shipetype('C', 'B', 'F', 'S' 중 하나)의 함선을 row, column, direction에 배치
	static int shipsize = 5;		//return값은 따로 없지만, ocean이 배열이기 때문에 함수 안에서 수정하면 그 결과가 반영됨
	int row, column, check;
	char ship, direction = " ";

	//함대 크기 체크 & 함대 종류 확인
	if (shipsize == 5) {
		printf("항공모함을 배치하겠습니다.\n");
		ship = 'C';
	}
	else if (shipsize == 4) {
		printf("전함을 배치하겠습니다.\n");
		ship = 'B';
	}
	else if (shipsize == 3) {
		printf("구축함을 배치하겠습니다.\n");
		ship = 'F';
	}
	else if (shipsize == 2) {
		printf("잠수함을 배치하겠습니다.\n");
		ship = 'S';
	}
	else		//모든 함대가 배치됐을 경우
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
			if (column + check > 8) {		//좌표를 넘어가는 경우
				for (check -= 1; check >= 0; check--)
					Hades[row][column + check] = '#';
				return 0;
			}
			else if (Hades[row][column + check] != '#') {	// 함대가 겹치는 경우
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

			if (column - check < 0) {		//좌표를 넘어갈 경우
				for (check -= 1; check >= 0; check--)
					Hades[row][column - check] = '#';
				return 0;
			}

			else if (Hades[row][column - check] != '#') {	// 함대가 겹치는 경우
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

			if (row + check > 8) {		//좌표를 넘어갈 경우
				for (check -= 1; check >= 0; check--)
					Hades[row + check][column] = '#';
				return 0;
			}

			else if (Hades[row + check][column] != '#') {	// 함대가 겹치는 경우
				for (check -= 1; check >= 0; check--)
					Hades[row + check][column] = '#';
				return 0;
			}
			Hades[row + check][column] = ship;
		}
	} break;
	case '4': {
		for (check = 0; check < shipsize; check++) {

			if (row - check < 0) {		//좌표를 넘어갈 경우
				for (check -= 1; check >= 0; check--)
					Hades[row - check][column] = '#';
				return 0;
			}

			else if (Hades[row - check][column] != '#') {		// 함대가 겹치는 경우
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
	printf("점수 : %02d \t\t점수 : %02d\n", P_Score, H_Score);
}
void Poseidon_Attack(){
	int row, column;

	while (1) {
		printf("공격할 좌표를 입력하세요 : ");
		gets(coordinate);
		
		row = coordinate[0] - 65;		//입력받은 좌표값(coordinate)에서 행 값(0부터 8사이의 값)으로 바꿈
		column = coordinate[1] - 49;	//입력받은 좌표값(coordinate)에서 열 값(0부터 8사이의 값)으로 바꿈
		if (row >= 0 && row <= 8 && column >= 0 && column <= 8) {
			if (Hide_Hades[row][column] != '#') {
				printf("이미 입력한 좌표입니다.\n");
				continue;
			}
			else break;
		}
		else
			printf("잘못된 좌표입니다.\n");
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
			printf("Hades 행성 승리!!\n");
			H_record++;
			break;
		}
		else if (H_Score == 0) {
			printf("Poseidon 행성 승리!!\n");
			P_record++;
			break;
		}
	}
}
int main() {

	errno_t err;
	FILE *record;

	err = fopen_s(&record, "war data.txt", "w");

	//-------------------------------------------------전적 출력----------------------------------------------------------
	printf("====================================\n");
	printf("사령관님 환영합니다.\n");
	printf("====================================\n");
	printf("현재까지 사령관님 대 행성 하데스 전쟁 전적\n");
	printf("%d승 %d패입니다.\n\n", P_record, H_record);

	system("pause");
	system("cls");


	int n1, n2;
	//-----------------------------------------------행성 초기 생성--------------------------------------------------------
	printf("       Poseidon		        Hades \n  ");
	for (n1 = 1; n1 <= 2; n1++) {
		for (n2 = 1; n2 < 10; n2++)
			printf("%d ", n2);
		printf("\t  ");
	}
	printf("\n");

	for (n1 = 0; n1 < 9; n1++) {
		printf("%c ", n1 + 65);			//내 행성 출력
		for (n2 = 0; n2 < 9; n2++) {
			Poseidon[n1][n2] = '#';
			printf("%c ", Poseidon[n1][n2]);
		}
		printf("\t%c ", n1 + 65);		//적 행성 출력
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

	fprintf(record, "현재까지 사령관님 대 행성 하데스 전쟁 전적은\n");
	fprintf(record, "%d승 %d패입니다.\n\n", P_record, H_record);

	fclose(record);

	getch();
	return 0;
}