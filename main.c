#include<stdint.h>
#include<stdio.h>
#include"List.h"
#include"IO_List.h"

uint8_t main()
{
    Node* head = NULL;
    ListStatusType status; 

    status = List_addTail(&head, 10);
    status = List_addTail(&head, 20);
    status = List_addTail(&head, 30);
    status = List_addHead(&head, 0);
    status = List_addAtNth(&head, 15, 3);
    status = List_deleteTail(&head);
    status = List_deleteTail(&head);
    status = List_deleteAtNth(&head, 1);
    status = List_deleteAtNth(&head, 2);
    IO_showFullList(head);
    IO_showMessage(status);

    return 0;

}