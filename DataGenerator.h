#ifndef DATAGENERATOR_H_INCLUDED
#define DATAGENERATOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <chrono> //count running time
#include<windows.h>
using namespace std;
using namespace std::chrono;

template <class T>
void HoanVi(T &a, T &b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
void outputData(int *a, int n);


        /* Sort data */
void bubbleSort(int *&a, int n, long long int &cnt_comparison);

//merge sort
void mergeSort(int *a, int l, int r, long long int &cnt_comparison);
void merge(int *a, int p, int q, int r, long long int & cnt_comparison);


#endif // DATAGENERATOR_H_INCLUDED
