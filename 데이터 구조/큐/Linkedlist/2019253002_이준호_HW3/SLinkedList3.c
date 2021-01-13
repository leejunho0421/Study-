#include <stdio.h>
#include <stdlib.h>
#include "SLinkedList3.h"

linkedList* initList() {
    linkedList* L;
    L = (linkedList*)malloc(sizeof(linkedList));
    L->head = NULL;
    L->length = 0;
    L->comp = NULL;
    return L;
}

int getLength(linkedList* L) {      // SLinkedList.c와 동일
    return L->length;
}

void displayList(linkedList* L) {
    listNode* p;
    printf("L=(");
    p = L->head;
    while (p != NULL) {
        printf("%d", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
    printf("list number is : %d\n", L->length);
}

void clear(linkedList* L) {
    listNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
        p = NULL;
    }
}

void setSortRule(linkedList* L, int (*comp)(element d1, element d2)) {
    L->comp = comp;      // 리스트의 멤버 comp를 초기화
}

void sortInsert(linkedList* L, element x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    listNode* point;
    int temp;
    if (L->head == NULL) {
        newNode->link = NULL;
        L->head = newNode;
    }
    else {
        newNode->link = L->head;
        L->head = newNode;
        point = L->head;
        while (L->comp(point->data, point->link->data)) { 
            temp = point->data;
            point->data = point->link->data;
            point->link->data = temp;
            point = point->link;
            if (point->link == NULL)
                break;
        }

    }
    L->length++;
}

int delete(linkedList* L, listNode* p) {
    listNode* pre;
    pre = (listNode*)malloc(sizeof(listNode));
    if (L == NULL)
        return FALSE;
    else if (p == NULL)
        return FALSE;
    else if (p == L) {
        L->head = p->link;
    }
    else {
        pre = L->head;
        while (!(pre->link == p)) {
            pre = pre->link;
            if (pre == NULL)
                return FALSE;
        }
        pre->link = p->link;
    }
    free(p);
    L->length--;
    return TRUE;
}

listNode* search(linkedList* L, element x) {
    listNode* temp = L->head;
    while (!(temp == NULL)) {
        if (temp->data == x) {
            printf("you Find");
            return temp;
        }
        else temp = temp->link;
    }
    return temp;
}