#include<stdio.h>
#include<stdlib.h>

typedef void* linkedlist;
typedef void** linkedlistdata;

linkedlist newlinkedlist()
{
    void** ans = malloc(sizeof(void*));
    *ans = NULL;
    return ans;
}

linkedlistdata lnlistget(linkedlist alldata, int index)
{
    if(index < 0) return alldata;
    alldata = *(void**)alldata;
    for(int i = 0; i < index; i++)
    {
        if(!alldata) return NULL;
        alldata = ((void**)alldata)[0];
    }
    return alldata;
}

int lnlistlen(linkedlist alldata)
{
    int len;
    alldata = *(void**)alldata;
    for(len = 0; alldata; alldata = ((void**)alldata)[0], len++){}
    return len;
}

void lnlistadd(linkedlist alldata, void* data)
{
    void** nowdata = malloc(sizeof(void*) * 2);
    nowdata[0] = NULL;
    nowdata[1] = data;
    for(; ((void**)alldata)[0]; alldata = ((void**)alldata)[0]){}
    ((void**)alldata)[0] = nowdata;
}

void lnlistremove(linkedlist alldata, int index)
{
    void *a = lnlistget(alldata, index - 1), *b = a ? ((void**)a)[0] : NULL, *c = b ? ((void**)b)[0] : NULL;
    ((void**)a)[0] = c;
    if(b) free(b);
}

void lnlistinsert(linkedlist alldata, void* data, int index)
{
    void *a = lnlistget(alldata, index - 1), *b = a ? ((void**)a)[0] : NULL;
    void** nowdata = malloc(sizeof(void*) * 2);
    nowdata[0] = b;
    nowdata[1] = data;
    ((void**)a)[0] = nowdata;
}

void lnlistswap(linkedlistdata a, linkedlistdata b)
{
    void* tmp = a[1];
    a[1] = b[1];
    b[1] = tmp;
}

void lnlistqsort(linkedlist alldata, int cont, int (*cmp)(const void*, const void*)) {
    if(cont <= 1) return;
    int s = 0;
    linkedlistdata nows = lnlistget(alldata, s), nowhigh = lnlistget(alldata, cont - 1);
    for(linkedlistdata a = nows; a; a = lnlistget(a, 0))
    {
        if(cmp(a[1], nowhigh[1]) < 0)
        {
            lnlistswap(a, nows);
            nows = lnlistget(nows, 0);
            s++;
        }
    }
    lnlistswap(nowhigh, nows);
    lnlistqsort(alldata, s, cmp);
    lnlistqsort(nows, cont - (s + 1), cmp);
}
