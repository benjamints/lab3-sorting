#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void outputData(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void bubbleSort(int *&a, int n, long long int &cnt_comparison)
{
    int i = 1;
    while (++cnt_comparison && i < n)
    {
        int j = n - 1;
        while (++cnt_comparison && j >= i)
        {
            if (a[j] < a[j-1])
                HoanVi(a[j], a[j-1]);

            j--;
        }
        i++;
    }
}

void merge(int *a, int p, int q, int r, long long int &cnt_comparison)
{
        // Create L ← A[p..q] and M ← A[q+1..r]
      int n1 = q - p + 1;
      int n2 = r - q;

      int L[n1], M[n2];

      int i = 0, j = 0;
      while (++cnt_comparison && i < n1)
      {
          L[i] = a[p + i];
          i++;
      }
      while (++cnt_comparison && j < n2)
      {
          M[j] = a[q + 1 + j];
          j++;
      }

      // Maintain current index of sub-arrays and main array
      i = 0;
      j = 0;
      int  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
        while (++cnt_comparison && ++cnt_comparison && i < n1 && j < n2)
        {
            if (++cnt_comparison && L[i] <= M[j])
            {
                a[k] = L[i];
                i++;
            }
            else
            {
                a[k] = M[j];
                j++;
            }
            k++;
        }

      // When we run out of elements in either L or M,
      // pick up the remaining elements and put in A[p..r]
        while (++cnt_comparison && i < n1)
        {
            a[k] = L[i];
            i++;
            k++;
        }

        while (++cnt_comparison && j < n2)
        {
            a[k] = M[j];
            j++;
            k++;
        }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int *a, int l, int r, long long int &cnt_comparison)
{
    if (++cnt_comparison && l < r)
    {
    // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(a, l, m, cnt_comparison);
        mergeSort(a, m + 1, r, cnt_comparison);

        // Merge the sorted subarrays
        merge(a, l, m, r, cnt_comparison);
    }
}
