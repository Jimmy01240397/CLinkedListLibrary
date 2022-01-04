#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int cmp(int* a, int* b)
{
    return *a - *b;
}

int main()
{
    linkedlist alldata = NULL;
    int cont;
    scanf("%d", &cont);
    for(int i = 0; i < cont; i++)
    {
        int* nowdata = malloc(sizeof(int));
        scanf("%d", nowdata);
        alldata = lnlistadd(&alldata, nowdata);
    }
    alldata = lnlisthead(alldata);
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", *(int *)lnlistget(alldata, i)[1]);
    }
    printf("\n");
    lnlistremove(&alldata, 0);
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
        lnlistinsert(&alldata, nowdata, 0);
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
    printf("\n");
    linkedlist test = lnlistget(alldata, 3);
    for(int i = 0; i >= -3; i--)
    {
        printf("%d ", *(int *)lnlistget(test, i)[1]);
    }
    printf("\n");
    printf("%d %d\n", *(int *)lnlisthead(test)[1], *(int *)lnlistend(test)[1]);
    lnlistloopup(test);
    printf("%d %d\n", *(int *)lnlisthead(test)[1], *(int *)lnlistend(test)[1]);
    cont = lnlistlen(test);
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", *(int *)lnlistget(test, i)[1]);
    }
    printf("%d ", *(int *)lnlistget(test, cont)[1]);
    printf("\n");
    printf("%d ", lnlistlen(alldata));
    printf("\n");
    lnlistdisloopup(test);
    cont = lnlistlen(test);
    for(int i = 0; i < cont; i++)
    {
        printf("%d ", *(int *)lnlistget(test, i)[1]);
    }
    printf("\n");
    printf("%d ", lnlistlen(alldata));
    printf("\n");

    return 0;
}
