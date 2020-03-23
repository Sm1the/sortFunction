#include "library.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//переменные для методов
int M=0,C=0,i;
int heapSize;

///RunNumber
int RunNumber (int num[], int n)
{
    int i,ser=1;
    for (i=1; i<n; i++)
        if (num[i-1]>num[i]) ser++;
    return ser;
}

///CheckSum
int CheckSum (int num[], int n)
{
    int i,summ=0;
    for (i=0; i<n; i++) summ+=num[i];
    return summ;
}

///PrintMas
void PrintMas(int num[], int n)
{   int o;
    printf("|");
    for (o=0;o<n;o++)
        printf("%2d|",num[o]);
    printf("\n");
}

///FillInc
void FillInc (int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=o+1;
    //printf("FillInc\n");
}

///FillDec
void FillDec (int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=n-o;
    //printf("FillDec\n");
}

///FillRand
void FillRand(int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=rand()%100+1;
    //printf("FillRand\n");
}

///BubbleSort
void BubbleSort(int num[], int n)
{
    int j,b;
    C=0;M=0;
    for(i=0; i<n-1;i++) {
        for(j=n-1;j>i;j--) {
            C+=1;
            if (num[j]<num[j-1])
            {
                M+=3;
                b=num[j];
                num[j]=num[j-1];
                num[j-1]=b;
            }
        }
    }
}

///SelectSort
void SelectSort(int num[], int n)
{
    int k,b,j ;
    M=0;C=0;
    for (i=0;i<n-1;i++) {
        k=i;
        for(j=i+1;j<n;j++) {
            C+=1;
            if (num[j]<num[k]) k=j;
        }
        M+=3;
        b=num[i], num[i]=num[k], num[k]=b;
    }
}

///ShakerSort
void ShakerSort(int num[], int n)
{
    int j,L,R,K,b;
    L=0,R=n-1,K=n-1,C=0,M=0;
    do {
        for(j=R;j>=L+1;j--) {
            C+=1;
            if(num[j]<num[j-1])
            {
                M+=3; b=num[j]; num[j]=num[j-1]; num[j-1]=b; K=j;
            }
        }
        L=K;
        for(j=L;j<=R-1;j++) {
            C+=1;
            if(num[j]>num[j+1])
            {
                M+=3; b=num[j]; num[j]=num[j+1]; num[j+1]=b; K=j;
            }
        }
        R=K;
    } while(L<R);
}
///InsertSort
void InsertSort(int num[], int n)
{
    int b,j;
    M=0;C=0;
    for(i=1;i<n;i++) {
        C++;M++;b=num[i]; j=i-1;
        for(;j>=0&&b<num[j];)
        {
            C++;
            num[j+1]=num[j];M++;
            j=j-1;
        }
        num[j+1]=b,M++;
    }
}

///ShellSort
void ShellSort(int num[], int n)
{
    int k,h,t,j,o,p;
    M=0;C=0;
    h=n/2;
    for(k=h;k>=1;)
    {
        for(o=k;o<n;o++)
        {
            C++;M++;t=num[o]; j=o-k;
            for(;j>=0&&t<num[j];)
            {
                C++;
                num[j+k]=num[j];M++;
                j=j-k;
            }
            num[j+k]=t;M++;
        }
        //printf("%d\n",k);
        k=k/2;
    }
}

///ShellSortKnut
void ShellSortKnut(int num[], int n)
{
    int k,h=0,t,j,o,p,u,y;
    float m;
    M=0;C=0;
    m=(log(n)/log(2))-1;
    for (y=1;y<=m;y++) h=2*h+1;
    for(k=h;k>=1;)
    {
        for(o=k;o<n;o++)
        {
            C++;M++;t=num[o]; j=o-k;
            for(;j>=0&&t<num[j];)
            {
                C++;
                num[j+k]=num[j];M++;
                j=j-k;
            }
            num[j+k]=t;M++;
        }
        m--;
        //printf("%d\n",k);
        k-=pow(2,(int)m);

    }

}

///Knut
int Knut(int n)
{
    int m;
    m=(log(n)/log(2))-1;
    return m;
}

///neKnut
int neKnut(int n)
{
    int u=0;
    while (n>1)
    {n=n/2;u++;}
    return u;
}

///ShellSortKnutdem
void ShellSortKnutdem(int num[], int n)
{
    int k,h=0,t,j,o,p,u,y;
    float m;
    M=0;C=0;
    m=(log(n)/log(2))-1; p=m;
    printf("|-Количество шагов = %d\n",Knut(n));
    for (y=1;y<=m;y++) h=2*h+1;
    for(k=h;k>=1;)
    {
        for(o=k;o<n;o++)
        {
            C++;M++;t=num[o]; j=o-k;
            for(;j>=0&&t<num[j];)
            {
                C++;
                num[j+k]=num[j];M++;
                j=j-k;
            }
            num[j+k]=t;M++;
        }
        m--;
        printf("|-h%d=%d\n",p,k);p--;
        k-=pow(2,(int)m);
    }
}

///HeapSorting
void Heapify(int* A, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;
    C++;
    if(l <= heapSize && A[l] > A[i])
    {largest = l;}
    else
    {largest = i;
        C++;
        if(r <= heapSize && A[r] > A[largest])
            largest = r;}

    if(largest != i)
    {
        int temp = A[i]; M++;
        A[i] = A[largest]; M++;
        A[largest] = temp; M++;
        Heapify(A, largest);
    }
}

void BuildHeap(int* A,int n)
{
    heapSize = n - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; i--)
        Heapify(A, i);
}

void HeapSort(int* A,int n)
{ C=0; M=0;
    BuildHeap(A,n);
    int i;
    for(i = n - 1; i > 0; i--)
    {
        int temp = A[heapSize];M++;
        A[heapSize] = A[0];M++;
        A[0] = temp;M++;
        heapSize--;
        Heapify(A, 0);
    }
}

