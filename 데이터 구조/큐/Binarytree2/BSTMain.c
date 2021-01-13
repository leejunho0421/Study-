#include <stdio.h>
#include "BinaryTree.h"
#pragma warning(disable: 4996)
void showData(BTData x) {
	printf("%d ", x);
}

void menu() {
	printf("\n*----------------*\n");
	printf("1: 이진 탐색 트리 출력(중위순회)\n");
	printf("2: 이진 탐색 트리 노드 삽입\n");
	printf("3: 이진 탐색 트리 노드 삭제\n");
	printf("4: 이진 탐색 트리 노드 검색\n");
	printf("5: 종료\n");
	printf("*----------------*\n");
	printf("메뉴 입력>> ");
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
				printf("이진 탐색 트리 출력(중위 순회)\n");
				InorderTraverse(bt, showData);
				break;
			case 2:
				printf("삽입할 숫자 입력: ");
				scanf("%d", &key);
				insertBST(bt, key); 
				printf("삽입 후 트리 출력(중위순회)\n");
				InorderTraverse(bt, showData);
				break;
			case 3:
				printf("삭제할 숫자 입력: ");
				scanf("%d", &key);
				deleteBST(bt, key);
				printf("삭제 후 트리 출력(중위순회)\n");
				InorderTraverse(bt, showData);
				break;
			case 4:
				printf("(4) 탐색할 숫자 입력: ");
				scanf("%d", &key);
				p = searchBST(bt, key);
				if(p != NULL) printf("%d를 탐색 성공", key);
				else printf("%d 탐색 실패", key);
				break;
			case 5:
				return 0;
			default:
				printf("잘못 입력했습니다. 메뉴를 다시 선택하세요.\n");
				break;
		}
	}	

	return 0;
}
