#include"List.h"

ListStatusType List_CreateNewNode(int32_t data, Node** pTemp)
{
    ListStatusType status = LIST_OVER_MEMORY;
    Node *ptr = (Node*)malloc(sizeof(Node));
    if(ptr != NULL){
        ptr->data = data;
        ptr->pNext = NULL;
        *pTemp = ptr;
        status = LIST_OK;        // overflowed heap memory
    }
    return status;
}

ListStatusType List_addHead(Node** headAddress, int32_t data)
{
    ListStatusType status = LIST_OK;
    Node* ptr = NULL;
    status = List_CreateNewNode(data, &ptr);
    if(status == LIST_OK){
        if(*headAddress == NULL){
            *headAddress = ptr;
        }else{
            ptr->pNext = *headAddress;
            *headAddress = ptr;
        }
    }else{
        status = LIST_OVER_MEMORY;
    }
    return status;
}

ListStatusType List_addTail(Node** headAddress, int32_t data)
{
    ListStatusType status = LIST_OK;
    Node* ptr = NULL; 
    Node* pTemp = NULL;
    status = List_CreateNewNode(data, &ptr);
    if(status == LIST_OK){
        if(*headAddress == NULL){
            *headAddress = ptr;
        }else{
            pTemp = *headAddress;
            while (pTemp->pNext != NULL)
            {
                pTemp = pTemp->pNext;
            }
            pTemp->pNext = ptr;
        }
    }else{
        status = LIST_OVER_MEMORY;
    }
    return status;
}

size_t List_getLength(Node* head)
{
    Node* ptr = head;
    size_t len = 0;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->pNext;
    }
    return len;
}

ListStatusType List_addAtNth(Node** headAddress, int32_t data, int32_t k)     // k = 1, 2, 3...
{
    ListStatusType status = LIST_OK;
    size_t len = List_getLength(*headAddress);
    // len = 0 still be applied
    if(k == 1){
        status = List_addHead(headAddress, data);
    }else if(k > 1 && k < len + 1){
        int32_t i;
        Node* ptr = NULL, * pTemp = NULL;
        status = List_CreateNewNode(data, &ptr);
        if(status == LIST_OK){
            pTemp = *headAddress;
            // find the (K-1)th Node
            for(i = 1; i < k - 1; i++){         
                pTemp = pTemp->pNext;
            }

            ptr->pNext = pTemp->pNext;
            pTemp->pNext = ptr;
        }else{
            status = LIST_OVER_MEMORY;
        }
    }else if (k >= len + 1)
    {
        status = List_addTail(headAddress, data);
    }
    return status;
}

// List_deleteHead()
ListStatusType List_deleteHead(Node** headAddress)
{
    Node* ptr = NULL;
    ListStatusType status = LIST_OK;
    if(*headAddress == NULL){
        status = LIST_EMPTY;
    }else{
        ptr = *headAddress;
        *headAddress = (*headAddress)->pNext;
        free(ptr);
    }
    return status;
}

// List_deleteTail()
ListStatusType List_deleteTail(Node** headAddress)
{
    size_t len = List_getLength(*headAddress);
    Node* pTemp = NULL;
    ListStatusType status = LIST_OK;

    if(*headAddress == NULL){
        status = LIST_EMPTY;
    }else{
        pTemp = *headAddress;
        // find the (len-1)th Node
        while (pTemp->pNext->pNext != NULL)
        {
            pTemp = pTemp->pNext;
        }
        
        Node* pTemp1 = pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp1);
    }
    return status;
}

// List_deleteAt()
ListStatusType List_deleteAtNth(Node** headAddress, int32_t k)       // k = 1, 2, 3, ...
{
    size_t len = List_getLength(*headAddress);
    ListStatusType status = LIST_OK;
    Node* pTemp = NULL, *pTemp1 = NULL;
    int32_t i;
    if(*headAddress == NULL){
        status = LIST_EMPTY;
    }else{
        if(k == 1){
            status = List_deleteHead(headAddress);
        }else if(k > 1 && k <= len){
            pTemp = *headAddress;
            for(i = 1; i < k-1; i++){
                pTemp = pTemp->pNext;
            }
            pTemp1 = pTemp->pNext;
            pTemp->pNext = pTemp1->pNext;
            free(pTemp1);
        }else{
            status = LIST_OUT_OF_RANGE;
        }
    }
    return status;
}


