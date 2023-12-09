#include"IO_List.h"

static uint8_t *LIST_MESSAGE[] = {
                                "List is empty", 
                                "List's out of range",
                                "List's over memory",
                                "List's ok"
                                };

void IO_showFullList(Node* head)
{
    Node* ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->pNext;        
    }
    printf("\n");
}

void IO_showMessage(ListStatusType status)
{
    printf("%s\n", LIST_MESSAGE[status]);
}