#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable: 4996)
#define MAX_CHILD 10

typedef struct ano* nodeptr;
typedef struct ano {
	char name[30];
	float gpa;
	char place[100];
	nodeptr links[MAX_CHILD];
}nodetype;

nodeptr root = NULL;
nodeptr stack[100];
int top = -1;

int read_upper(FILE* fp, char buf[20][50]); 	// ������ ������ ��ݺ��� �� �� �д� �Լ� 
void read_store_lower_data(FILE* fp);			// ������ ������ �Ϲݺ��� �� �� �д� �Լ� 
void print_general_tree(nodeptr curr);			// ��� ����� ������ ���
void make_node_and_attach_to_parent(nodeptr parent, char* tname, int loc);	// parent�� loc ��ġ�� �ڽ� ��带 ����� �Ŵް� �̸��� tname�� �־���
void push_stack(nodeptr nptr);
void pop_stack();

nodeptr search_node(nodeptr cur, char name[]);	// �̸����� ��� Ž��
void calc_height(nodeptr cur, int par_height, int* tree_height);	// Find the height of the whole tree
int calc_depth(nodeptr cur, int par_height, char* sname);		// Find the depth of a specific person
int find_ancestors(nodeptr cur, char* sname);	// Find all ancestors of a specific person
void calc_descendants(nodeptr cur, int* cnt);	// Find the number of descendants of a specific person

int main() {
	char buf[20][50];
	char line[100];
	char command[100];
	char name[10];
	int num_persons, k, i, res;
	nodeptr np;
	
	FILE* fp;
	fp = fopen("tree_data.txt", "r");
	if(!fp) {
		printf("file open error\n");
		return 0;
	}
	
	do {
		num_persons = read_upper(fp, buf);	// read one line of several names
		if(num_persons == 0)	// '-' in first letter of the first person's name
			break;
		if(!root) {	// no node in the tree
			np = (nodeptr)malloc(sizeof(nodetype));
			strcpy(np->name, buf[0]);	// �θ� �̸� ����
			root = np;
			np->links[0] = NULL;
			for(k=1; k<num_persons; k++)	// �ڽĵ��� ����� �Ŵ���
				make_node_and_attach_to_parent(np, buf[k], k-1);
			// put NULL in links field after the last child
			np->links[k-1] = NULL; 
		}
		else {	// ordinary case of a tree with one or more nodes
			np = search_node(root, buf[0]);
			if(!np) {
				printf("Error: 2° �� ������ ù �̸� ��尡 ����\n");
				getchar();
			}
			for(k=1; k<num_persons; k++)
				make_node_and_attach_to_parent(np, buf[k], k-1);
			// put NULL in links field after the last child
			np->links[k-1] = NULL; 
		}
	} while(1);
	
	// �� ��忡 ���� �����͸� �о ����
	read_store_lower_data(fp);
	
	// Ʈ�� ���� ��� ����� �����͸� preorder ������� ���
	print_general_tree(root);
	
	do {
		printf("Type a command> ");
		gets(line);
		
		i = 0;
		while(line[i] == ' ' || line[i] == '\t') i++;	// move to 1st letter of the command
		k = 0;
		while(!(line[i] == ' ' || line[i] == '\t' || line[i] == '\0')) {
			command[k] = line[i];
			i++; k++;
		}
		command[k] = '\0';	// finish the command
		
		if(strcmp(command, "ex") == 0)
			break;
		else if(strcmp(command, "ht") == 0) {
			int tree_height = 0;
			calc_height(root, 0, &tree_height);
			printf("Height of the tree : %d \n", tree_height);
			continue;
		}
		
		// read a name given after the command
		k = 0;
		while(line[i] == ' ' || line[i] == '\t') i++;	// move to 1st letter of the command
		while(!(line[i] == ' ' || line[i] == '\t' || line[i] == '\0')) {
			name[k] = line[i];
			i++; k++;
		}
		name[k] = '\0';
		
		if(strcmp(command, "se") == 0) {
			np = search_node(root, name);
			if(np)
				printf("Search success: %s %5.2f %s\n", np->name, np->gpa, np->place);
			else
				printf("Such a person does not exist\n");
		}
		else if(strcmp(command, "dp") == 0) {
			res = calc_depth(root, 0, name);
			if(!res)
				printf("Such a name does not exist in the tree\n");
		}
		else if(strcmp(command, "ac") == 0) {
			top = -1;
			res = find_ancestors(root, name);
			if(!res)
				printf("Such a name does not exist in the tree\n");
		}
		else if(strcmp(command, "nm") == 0) {
			int cnt = 0;
			np = search_node(root, name);
			calc_descendants(np, &cnt);
			printf("%d ��\n", cnt);
		}
		else {
			printf("Wrong command\n");
		}
	} while(1);
	 
	return 0;
}

// ������ ������ ��ݺ��� �� �� �д� �Լ� 
// �� ���� �о 2���� �迭 buf�� �ְ�, ��� ���� ��ȯ
// 0�� --- ���� ���� ��쿡 ��ȯ�� 
int read_upper(FILE* fp, char buf[20][50]) {
	// read "parent-children" lines to create the tree
	int i, j, k;
	char line[400];
	char* cp;
	cp = fgets(line, 400, fp);
	if(!cp) {
		// fail in reading
		printf("Impossible for the control to reach here\n");
		return 0;
	}
	else {
		if(line[0] == '-')  // ���� ��ܺ� �б� ����
			return 0;
		
		i = 0;		// number of names read so far
		j = 0; 		// index to line
		while(1) {
			k = 0; 	// index to a character of the i-th name
			while(line[j] != ' ' && line[j] != '\n') {
				buf[i][k] = line[j];
				j++; k++;
			}
			buf[i][k] = '\0';	// finish one name
			i++;	// increase the name count
			if(line[j] == '\n')
				break;
			else {
				do j++; while(line[j] == ' ');
			}
		}
		return i;
	}
}

// ������ ������ �ϴܺθ� �о� ������ ����
void read_store_lower_data(FILE* fp) {
	char rname[30], address[100];
	float rgpa;
	nodeptr np;
	int read_num;
	
	do {
		read_num = fscanf(fp, "%s%f%s", rname, &rgpa, address);
		if(read_num != 3)
			break;
		else {
			// ���� �̸��� ���� ��带 Ʈ������ ã��
			np = search_node(root, rname);
			if(!np)
				printf("�̷� �̸��� ���� ��尡 �����ϴ�.\n");
			else {
				// ���� �����͸� ���� 
				strcpy(np->name, rname);
				np->gpa = rgpa;
				strcpy(np->place, address);
			}
		}		
	} while(1);
}

// ��� ����� ������ ���
void print_general_tree(nodeptr cur) {
	int i;
	if(!cur)
		return;
	printf("�̸�: %s\t����: %5.2f\t�ּ�: %s \n", cur->name, cur->gpa, cur->place);
	for(i=0; cur->links[i]; i++)
		print_general_tree(cur->links[i]);
} 

// parent�� loc ��ġ�� �ڽ� ��带 ����� �Ŵް� �̸��� tname�� �־���
void make_node_and_attach_to_parent(nodeptr parent, char* tname, int loc) {
	nodeptr np1;
	np1 = (nodeptr)malloc(sizeof(nodetype));
	strcpy(np1->name, tname);
	np1->links[0] = NULL;
	parent->links[loc] = np1;
} 

void push_stack(nodeptr nptr) {
	top++;
	stack[top] == nptr;
}

// this pop des not return the element
void pop_stack() {
	top--;
}

// �̸����� search 
// cur : Ʈ���� ��忡 ���� ������
// name : ã�� �̸�
// ��ȯ�� : ã�� ����� ������ (�� ã�� ��� NULL) 
nodeptr search_node(nodeptr cur, char name[]) {
	int i;
	nodeptr rptr;
	
	if(!cur)
		return NULL;
	
	if(strcmp(cur->name, name) == 0)
		return cur;		// ����
	else {
		for(i=0; cur->links[i] != NULL; i++) {
			rptr = search_node(cur->links[i], name);
			if(rptr) return rptr;
		}
		return NULL;	// �ڽĵ� ��ο����� �� ã�����Ƿ� ���� 
	} 
}

// Find the height of the whole tree
void calc_height(nodeptr cur, int par_height, int* tree_height) {
	// Fill your code
	int height = par_height + 1;
	if (height > * tree_height) {
		*tree_height = height;
	}
	if (cur->links[0] == NULL) {
		return;
	}
	for (int i = 0;cur->links[i];i++) {
		calc_height(cur->links[i], height - 1, tree_height);
	}
}

// Find the depth of a specific person
// return value : 1 if the name has been found and its depth was printed
//				  0 if the name was not found in the subtree with root of cur
int calc_depth(nodeptr cur, int par_height, char* sname) {
	// Fill your code

	if (search_node(cur, sname) == NULL)
		return 0;
	else push_stack(cur);

	if (cur->links[0] == NULL) 
		return 0;

	for (int i = 0; cur->links[i]; i++) {
		calc_depth(cur->links[i], par_height, sname);
	}
	return 0;
}

// Find all ancestors of a specific person
int find_ancestors(nodeptr cur, char* sname) {
	// Fill your code
	if (cur == NULL) return 0;

	if (strcmp(cur->name, sname)) 
		return 0;

	if (!search_node(cur, sname))
		push_stack(cur);

	for (int i = 0; cur->links[i]; i++)
		find_ancestors(cur->links[i], sname);

	return 0;
}

// Find the number of descendants of a specific person
void calc_descendants(nodeptr cur, int* cnt) {
	// Fill your code

	if (cur == NULL) {
		return;
	}

	for (int i = 0; cur->links[i] != 0; i++) { 
		calc_descendants(cur->links[i], cnt);
		*cnt++;
	}
}

