#ifndef _LIST_H_
#define _LIST_H_

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Device.h"
#include"Student.h"

typedef struct Node                 // node type
{
    // int32_t data;
    uint8_t *pData;                 // pointer to data 
    struct Node *pNext;
}Node;

typedef Node* ListType;             // single linked list type

typedef enum{                       // list status type
    LIST_EMPTY,
    LIST_OUT_OF_RANGE,
    LIST_OVER_MEMORY,
    LIST_OK,
    LIST_INVALID_VALID,
}ListStatusType;

// size_t List_getLength(Node* head);
// ListStatusType List_CreateNewNode(int32_t data, Node** pTemp);
// ListStatusType List_addHead(Node** headAddress, int32_t data);
// ListStatusType List_addTail(Node** headAddress, int32_t data);
// ListStatusType List_addAtNth(Node** headAddress, int32_t data, int32_t k);
// ListStatusType List_deleteHead(Node** headAddress);
// ListStatusType List_deleteTail(Node** headAddress);
// ListStatusType List_deleteAtNth(Node** headAddress, int32_t k);

size_t List_getLength(Node* head);
ListStatusType List_CreateNewNode(Node** pTemp, uint8_t *pData, uint32_t size_of_element);
ListStatusType List_addHead(Node** headAddress, uint8_t *pData, uint32_t size_of_element);
ListStatusType List_addTail(Node** headAddress, uint8_t *pData, uint32_t size_of_element);
ListStatusType List_addAtNth(Node** headAddress, uint8_t *pData, uint32_t size_of_element, int32_t k);

#endif  