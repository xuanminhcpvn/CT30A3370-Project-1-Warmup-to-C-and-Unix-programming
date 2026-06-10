#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include "reverse.h"
#include <stdlib.h>
//input_stream could be stdin/.txt file, output_stream could be stdout/.txt file
void reverse(FILE *pInput_stream, FILE *pOutput_stream)
{
    LINKED_LIST *pHead = NULL;
    LINKED_LIST *pTail = NULL;
    char *pLine = NULL;
    size_t iLen = 0; //needed by getline
    while (getline(&pLine, &iLen, pInput_stream) != -1){
        /* create node + malloc node */
        if (strcmp(pLine, ":quit\n") == 0){
            printf("Given string in reversed order: \n");
            break;
        }
        LINKED_LIST *pNode = malloc(sizeof(LINKED_LIST));
        if (pNode == NULL){
            fprintf(stderr, "malloc failed\n");
            free(pNode);
            free(pLine);
            free_list(pHead);
            exit(1);
        }
        pNode->pLine = malloc(strlen(pLine)+1);
        if (pNode->pLine == NULL){
            fprintf(stderr, "malloc failed\n");
            free(pLine);
            free_list(pHead);
            exit(1);
        }
        strcpy(pNode->pLine, pLine);
        /* Linked list insert algorithm (doubly version)*/
        pNode->pNext = NULL;
        pNode->pPrev = pTail;//null in first node
        if (pTail != NULL){
            pTail->pNext = pNode;
        } else {
            pHead = pNode;
        }
        pTail = pNode;   
    }
    /* print reversed */
    LINKED_LIST *pCurrent= pTail;
    while (pCurrent != NULL)
    {
        fprintf(pOutput_stream, "%s", pCurrent->pLine);
        pCurrent = pCurrent->pPrev;
    }
    /* free list */
    free_list(pHead);
    free(pLine);
}

void free_list(LINKED_LIST *pHead){
    LINKED_LIST *pCurrent = pHead;
    while (pCurrent != NULL)
    {
        LINKED_LIST *pNext = pCurrent->pNext;
        free(pCurrent->pLine);
        free(pCurrent);
        pCurrent = pNext;
    }
}