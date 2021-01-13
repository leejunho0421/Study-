#include <stdio.h>
#include "BinaryTree.h"
#pragma warning(disable: 4996)
void showData(BTData x) {
	printf("%d ", x);
}

void menu() {
	printf("\n*----------------*\n");
	printf("1: ���� Ž�� Ʈ�� ���(������ȸ)\n");
	printf("2: ���� Ž�� Ʈ�� ��� ����\n");
	printf("3: ���� Ž�� Ʈ�� ��� ����\n");
	printf("4: ���� Ž�� Ʈ�� ��� �˻�\n");
	printf("5: ����\n");
	printf("*----------------*\n");
	printf("�޴� �Է�>> ");
}

int main() {
	BinTree* bt = createBT();
	BinTree* p;
	int choice; 
	BTData key;
	
	setData(bt, 8);	
	insertBST(bt, 3);
	insertBST(bt, 10);
	insertBST(bt, 2);
	insertBST(bt, 5);
	insertBST(bt, 14);
	insertBST(bt, 11);
	insertBST(bt, 16);
	
	while(1) {
		menu();
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				printf("���� Ž�� Ʈ�� ���(���� ��ȸ)\n");
				InorderTraverse(bt, showData);
				break;
			case 2:
				printf("������ ���� �Է�: ");
				scanf("%d", &key);
				insertBST(bt, key); 
				printf("���� �� Ʈ�� ���(������ȸ)\n");
				InorderTraverse(bt, showData);
				break;
			case 3:
				printf("������ ���� �Է�: ");
				scanf("%d", &key);
				deleteBST(bt, key);
				printf("���� �� Ʈ�� ���(������ȸ)\n");
				InorderTraverse(bt, showData);
				break;
			case 4:
				printf("(4) Ž���� ���� �Է�: ");
				scanf("%d", &key);
				p = searchBST(bt, key);
				if(p != NULL) printf("%d�� Ž�� ����", key);
				else printf("%d Ž�� ����", key);
				break;
			case 5:
				return 0;
			default:
				printf("�߸� �Է��߽��ϴ�. �޴��� �ٽ� �����ϼ���.\n");
				break;
		}
	}	

	return 0;
}
