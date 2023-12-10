#include"List.h"

/*
DeviceType, StudentType    
*/
ListStatusType List_CreateNewNode(Node** pTemp, uint8_t *pData, uint32_t size_of_element)
{
    ListStatusType status = LIST_OVER_MEMORY;
    Node *ptr = (Node*)malloc(sizeof(Node));
    DeviceType *pDevice = NULL;
    StudentType *pSt = NULL;
    DeviceType *pD = NULL;
    StudentType *pS = NULL;
    uint8_t mem_alloc_ok = 0;           // default  = 0: allocation is fail

    if(ptr != NULL){
            switch (size_of_element)
            {
            case sizeof(DeviceType):
                ptr->pData = (uint8_t*)malloc(size_of_element);
                if(ptr->pData == NULL){
                    break;
                }
                mem_alloc_ok = 1;
                // => assign data from *pData to ptr->pData
                pDevice = (DeviceType*)pData;
                pD = (DeviceType*)ptr->pData;
                strcpy(pD->name, pDevice->name);
                pD->power = pDevice->power;
                pD->unit_price = pDevice->unit_price;
                break;
            case sizeof(StudentType):
                ptr->pData = (uint8_t*)malloc(size_of_element);
                if(ptr->pData == NULL){
                    break;
                }
                mem_alloc_ok = 1;
                // => assign data from *pData to ptr->pData
                pSt = (StudentType*)pData;
                pS = (StudentType*)ptr->pData;
                strcpy(pS->name, pSt->name);
                strcpy(pS->id, pSt->id);
                pS->age = pSt->age;
                pS->math_point = pSt->math_point;
                break;
            default:
                break;
            }
            if(mem_alloc_ok){
                ptr->pNext = NULL;
                *pTemp = ptr;
                status = LIST_OK;        // overflowed heap memory
            }
    }
    return status;
}

ListStatusType List_addHead(Node** headAddress, uint8_t *pData, uint32_t size_of_element)
{
    ListStatusType status = LIST_OK;
    Node* ptr = NULL;
    status = List_CreateNewNode(&ptr, pData, size_of_element);
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

ListStatusType List_addTail(Node** headAddress, uint8_t *pData, uint32_t size_of_element)
{
    ListStatusType status = LIST_OK;
    Node* ptr = NULL; 
    Node* pTemp = NULL;
    status = List_CreateNewNode(&ptr, pData, size_of_element);
    if(status == LIST_OK){
        if(*headAddress == NULL){           // function isEmpty()???
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

ListStatusType List_addAtNth(Node** headAddress, uint8_t *pData, uint32_t size_of_element, int32_t k)     // k = 1, 2, 3...
{
    ListStatusType status = LIST_OK;
    size_t len = List_getLength(*headAddress);

    if(k == 1){
        status = List_addHead(headAddress, pData, size_of_element);
    }else if(k > 1 && k < len + 1){
        int32_t i;
        Node *ptr = NULL, *pTemp = NULL;
        status = List_CreateNewNode(&ptr, pData, size_of_element);
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
        status = List_addTail(headAddress, pData, size_of_element);
    }
    else{   // k < 1
        status = LIST_INVALID_VALID;
    }
    return status;
}

// // List_deleteHead()
// ListStatusType List_deleteHead(Node** headAddress)
// {
//     Node* ptr = NULL;
//     ListStatusType status = LIST_OK;
//     if(*headAddress == NULL){
//         status = LIST_EMPTY;
//     }else{
//         ptr = *headAddress;
//         *headAddress = (*headAddress)->pNext;
//         free(ptr);
//     }
//     return status;
// }

// // List_deleteTail()
// ListStatusType List_deleteTail(Node** headAddress)
// {
//     size_t len = List_getLength(*headAddress);
//     Node* pTemp = NULL;
//     ListStatusType status = LIST_OK;

//     if(*headAddress == NULL){
//         status = LIST_EMPTY;
//     }else{
//         pTemp = *headAddress;
//         // find the (len-1)th Node
//         while (pTemp->pNext->pNext != NULL)
//         {
//             pTemp = pTemp->pNext;
//         }
        
//         Node* pTemp1 = pTemp->pNext;
//         pTemp->pNext = NULL;
//         free(pTemp1);
//     }
//     return status;
// }

// // List_deleteAt()
// ListStatusType List_deleteAtNth(Node** headAddress, int32_t k)       // k = 1, 2, 3, ...
// {
//     size_t len = List_getLength(*headAddress);
//     ListStatusType status = LIST_OK;
//     Node* pTemp = NULL, *pTemp1 = NULL;
//     int32_t i;
//     if(*headAddress == NULL){
//         status = LIST_EMPTY;
//     }else{
//         if(k == 1){
//             status = List_deleteHead(headAddress);
//         }else if(k > 1 && k <= len){
//             pTemp = *headAddress;
//             for(i = 1; i < k-1; i++){
//                 pTemp = pTemp->pNext;
//             }
//             pTemp1 = pTemp->pNext;
//             pTemp->pNext = pTemp1->pNext;
//             free(pTemp1);
//         }else{
//             status = LIST_OUT_OF_RANGE;
//         }
//     }
//     return status;
// }


