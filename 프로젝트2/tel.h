#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct MEMBER{
        char name[30];
        char phone[20];
        char memo[40];
} MEMBER;

int tel_srch(MEMBER *list, int *count);
void tel_add(MEMBER *list, int *count);
void tel_delt(MEMBER *list, int *count);
void tel_list(MEMBER *list, int *count);

