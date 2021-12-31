#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int cmp(int* a, int* b)
{
    return *a - *b;
}

int main()
{
    linkedlist alldata = newlinkedlist();
    int cont;
    scanf("%d", &cont);
    for(int i = 0; i < cont; i++)
    {
        int* nowdata = malloc(sizeof(int));
        scanf("%d", nowdata);
        lnlistadd(alldata, nowdata);
    }
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", *(int *)lnlistget(alldata, i)[1]);
    }
    printf("\n");
    lnlistremove(alldata, 1);
    cont = lnlistlen(alldata);
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", *(int *)lnlistget(alldata, i)[1]);
    }
    printf("\n");
    scanf("%d", &cont);
    for(int i = 0; i < cont; i++)
    {
        int* nowdata = malloc(sizeof(int));
        scanf("%d", nowdata);
        lnlistinsert(alldata, nowdata, 1);
    }
    cont = lnlistlen(alldata);
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", *(int *)lnlistget(alldata, i)[1]);
    }
    printf("\n");
    lnlistqsort(alldata, cont, cmp);
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", *(int *)lnlistget(alldata, i)[1]);
    }
    return 0;
}
