#ifndef _LIST_H_
#define _LIST_H_

#include<stdint.h>
#include<stdlib.h>

typedef struct Node                 // node type
{
    int32_t data;
    struct Node *pNext;
}Node;

typedef Node* ListType;             // single linked list type

typedef enum{                       // list status type
    LIST_EMPTY,
    LIST_OUT_OF_RANGE,
    LIST_OVER_MEMORY,
    LIST_OK,
}ListStatusType;

size_t List_getLength(Node* head);
ListStatusType List_CreateNewNode(int32_t data, Node** pTemp);
ListStatusType List_addHead(Node** headAddress, int32_t data);
ListStatusType List_addTail(Node** headAddress, int32_t data);
ListStatusType List_addAtNth(Node** headAddress, int32_t data, int32_t k);
ListStatusType List_deleteHead(Node** headAddress);
ListStatusType List_deleteTail(Node** headAddress);
ListStatusType List_deleteAtNth(Node** headAddress, int32_t k);

#endif  