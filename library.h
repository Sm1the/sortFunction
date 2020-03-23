#ifndef SORTFUNCTION_LIBRARY_H
#define SORTFUNCTION_LIBRARY_H

///RunNumber
int RunNumber (int num[], int n);

///CheckSum
int CheckSum (int num[], int n);

///PrintMas
void PrintMas (int num[], int n);

///FillInc
void FillInc (int num[], int n);

///FillDec
void FillDec (int num[], int n);

///FillRand
void FillRand (int num[], int n);

///BubbleSort
void BubbleSort( int A[], int n);

///SelectSort
void SelectSort( int A[], int n);

///InsertSort
void InsertSort( int A[], int n);

///ShakerSort
void ShakerSort(int A[], int n);

///ShellSort
void ShellSort(int A[], int n);

///ShellSortKnut
void ShellSortKnut(int num[], int n);

///Knut
int Knut(int n);

///neKnut
int neKnut(int n);

///ShellSortKnutdem
void ShellSortKnutdem(int num[], int n);

void Heapify(int* A, int i);
void BuildHeap(int* A,int n);
void HeapSort(int* A,int n);

#endif //SORTFUNCTION_LIBRARY_H
