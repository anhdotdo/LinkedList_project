#ifndef _IO_LIST_H_
#define _IO_LIST_H_

#include<stdint.h>
#include<stdio.h>
#include"List.h"

void IO_showMessage(ListStatusType status);
void IO_showFullList(Node* head, uint32_t size_of_element);

#endif