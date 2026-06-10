//reverse.h
//Include guards
#define _POSIX_C_SOURCE 200809L
#ifndef REVERSE_H
#define REVERSE_H
//Linked list data structure
typedef struct linked_list {
    char *pLine;
    struct linked_list *pNext;
    struct linked_list *pPrev;
} LINKED_LIST;

void reverse(FILE *input_stream, FILE *output_stream);
void free_list(LINKED_LIST *pHead);
#endif