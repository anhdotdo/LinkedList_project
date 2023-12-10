#include"IO_List.h"

static uint8_t *LIST_MESSAGE[] = {
                                "List is empty", 
                                "List's out of range",
                                "List's over memory",
                                "List's ok",
                                "Invalid value"
                                };

void IO_showFullList(Node* head, uint32_t size_of_element)
{
    Node* ptr = head;
    DeviceType* pD = NULL;
    StudentType*pS = NULL;

    while (ptr != NULL)
    {
        // => show data
        switch (size_of_element)
        {
        case sizeof(DeviceType):
            pD = (DeviceType*)ptr->pData;
            printf("%s, ", pD->name);
            printf("%d, ", pD->power);
            printf("%d\n", pD->unit_price);
            break;
        case sizeof(StudentType):
            pS = (StudentType*)ptr->pData;
            printf("%s, ", pS->name);
            printf("%s, ", pS->id);
            printf("%d, ", pS->age);
            printf("%d\n", pS->math_point);
            break;
        default:
            break;
        }

        ptr = ptr->pNext;        
    }
}

void IO_showMessage(ListStatusType status)
{
    printf("%s\n", LIST_MESSAGE[status]);
}