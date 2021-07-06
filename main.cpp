
int main()
{
    cout << "data type: random data" << endl;
    cout << "when size = 20" << endl;
    int sizeofData = 20, dataType = 1;
    for (int i = 0; i < 2; i++)
    {

        int *a;
        a = new int [sizeofData];
        GenerateData(a, sizeofData, dataType);
        outputData(a, sizeofData);

        //cout << endl << "after sorting: ";
        long long int cnt_comparison = 0;

        if (i == 0)
            {
                auto start = high_resolution_clock::now();

                bubbleSort(a, sizeofData, cnt_comparison);

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << endl << "comparison bubble sort: "; separateNumber(cnt_comparison); cout << endl;
                cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
            }
     /*  else if (i == 1)
            {
                auto start = high_resolution_clock::now();

                selectionSort (a, sizeofData, cnt_comparison);

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << endl << "comparison selection sort: "; separateNumber(cnt_comparison); cout << endl;
                cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
            }*/
        /*else if (i == 2)
            {
                auto start = high_resolution_clock::now();

                insertionSort(a, sizeofData, cnt_comparison);

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << endl << "comparison insertion sort: "; separateNumber(cnt_comparison); cout << endl;
                cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
            }*/
         else if (i == 1)
            {
                auto start = high_resolution_clock::now();

                mergeSort(a, 0, sizeofData - 1, cnt_comparison);

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << endl << "comparison merge sort: "; separateNumber(cnt_comparison); cout << endl;
                cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
            }

      /*     else if (i==1)
            {
                auto start = high_resolution_clock::now();

                heapSort(a, sizeofData , cnt_comparison);

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << endl << "comparison heap sort: "; separateNumber(cnt_comparison); cout << endl;
                cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
            }
            else
            {
                auto start = high_resolution_clock::now();

                quickSort(a, 0 , sizeofData - 1, cnt_comparison);

                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<milliseconds>(stop - start);

                cout << endl << "comparison quick sort: "; separateNumber(cnt_comparison); cout << endl;
                cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
            }
*/
             outputData(a, sizeofData);
        Sleep(2000);
        cout << endl << endl;
        delete [] a;
        a  = nullptr;
    }
    return 0;
}
