#include<stdint.h>
#include<stdio.h>
// #include"Device.h"
#include"List.h"
#include"IO_List.h"

uint8_t main()
{
    Node* head = NULL;
    ListStatusType status; 

    DeviceType d_temp = {.name = "button", .power = 10, .unit_price = 100};
    DeviceType d_temp1 = {.name = "led", .power = 1, .unit_price = 10};
    StudentType s_temp = {.name = "anh", .id = "100", .age = 23, .math_point = 7};
    StudentType s_temp1 = {.name = "thang", .id = "101", .age = 24, .math_point = 8};

    // status = List_addTail(&head, (uint8_t*)&d_temp, sizeof(DeviceType));
    // status = List_addTail(&head, (uint8_t*)&d_temp1, sizeof(DeviceType));
    // status = List_addHead(&head, (uint8_t*)&d_temp1, sizeof(DeviceType));
    // status = List_addAtNth(&head, (uint8_t*)&d_temp, sizeof(DeviceType), 0);

    status = List_addTail(&head, (uint8_t*)&s_temp, sizeof(StudentType));
    status = List_addTail(&head, (uint8_t*)&s_temp1, sizeof(StudentType));
    IO_showFullList(head, sizeof(StudentType));
    IO_showMessage(status);

    // status = List_addTail(&head, 10);
    // status = List_addTail(&head, 20);
    // status = List_addTail(&head, 30);
    // status = List_addHead(&head, 0);
    // status = List_addAtNth(&head, 15, 3);
    // status = List_deleteTail(&head);
    // status = List_deleteTail(&head);
    // status = List_deleteAtNth(&head, 1);
    // status = List_deleteAtNth(&head, 2);
    // IO_showFullList(head);
    // IO_showMessage(status);

    return 0;

}