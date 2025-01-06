/*
declare all functions for printing, sorting, and swapping
declare srand function with time as null and declare all arrays
assign values for arrays and print them output
call sort function and sort pointerArray
keep using swap function inside the sort function to swap a value if it is more than the next value
transfer value of pointer back to original
print out both of the following
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> // contains prototype for function time
using namespace std;

#define SIZE 150

void printArray(int randArray[]);	// Function prototype
void bubbleSort(int* pointerArray[]);		// Function prototype
void printPointerArray(int* ptrArray[]);	// Function prototype
void swapIntPtr(int** xptr, int** yptr);	// Function prototype

int main()
{

	srand(time(NULL));  // gives srand value

	int dataArray[SIZE] = { 0 };  // declares arrays
	int* pointerArray[SIZE];

	// Initializing values in Data Array
	for (int index = 0; index < SIZE; index++)
	{
		dataArray[index] = rand() % 3000;   // gives value from 0 - 2999
	}

	// Printing four different data sets
	printf("Before Sorting, values in Data Array: \n");
	printArray(dataArray);
	printf("\n");

	// Initializing Pointer array with the address of each element in data array

    for (int index = 0; index < SIZE; index++)
    {
        pointerArray[index] = &dataArray[index];   // gives all the values of the original to pointer
    }

	printf("Before Sorting, values in Pointer Array and the value it is pointing at: \n");
	printPointerArray(pointerArray);
	printf("\n");

	// Calling function Bubble SOrt
	bubbleSort(pointerArray);

	// After Sorting printing the values
	printf("\n");
	printf("After Sorting, values in Pointer Array and the value it is pointing at:  \n");
	printPointerArray(pointerArray);
	printf("\n");

	// transfer values of pointer back to original
	for (int index = 0; index < SIZE; index++)
    {
        dataArray[index] = *pointerArray[index];
    }


	printf("\n");
	printf("After Sorting, values in Data Array: \n");
	printArray(dataArray);
	printf("\n");
   return 0;
}

void printArray(int randArray[])
{
    for (int i = 0; i < SIZE; i++)
    {
    cout << left << setw(6) << randArray[i];  // print in proper format
    if ((i+1)%10 == 0)
    {
        cout << endl;  // outputs a new line every 10 values outputed
    }
    }
    cout << endl;
}


void bubbleSort(int* pointerArray[])
{
    // loop to do it repeat inner loop
    for (int j = 0; j < SIZE-1; j++)
    {
        //loop to redo the swap however many times in array
        for (int i = 0; i < SIZE -j -1; i++)
        {
            if (*pointerArray[i] > *pointerArray[i + 1])
            {

                swapIntPtr(&pointerArray[i], &pointerArray[i+1]);
            }
        }

    }


}

void printPointerArray(int* ptrArray[])
{
    for (int i = 0; i < SIZE; i++)
    {
    cout << left << setw(6) << *ptrArray[i];   // prints in proper format
    if ((i+1)%10 == 0)
    {
        cout << endl;    // outputs a new line every 10 values outputed
    }
    }
}

void swapIntPtr(int** xptr, int** yptr)
{
    int* temp = *xptr;    // gives temp value of xptr
    *xptr = *yptr;       // gives xptr value of yptr
    *yptr = temp;       // gives yptr value of xptr
}



/* output
Before Sorting, values in Data Array:
2333  2499  790   2249  2520  1919  1473  2677  2962  1697
2274  1981  2070  10    1383  511   809   180   1986  1862
2256  1068  547   1627  41    1391  2012  1454  1512  1423
1778  845   1275  2569  94    795   1840  1567  824   1802
264   450   783   2687  461   2518  198   1622  2698  2536
485   2307  604   1384  934   998   127   298   2452  1640
2074  1582  2837  349   1151  2932  1496  343   1851  2320
2145  2468  122   281   2155  583   2799  2705  2558  2850
2593  395   2157  549   2131  443   1547  2259  1093  1351
1251  167   2934  1088  516   1437  1372  2364  1781  224
2036  1278  44    2159  1559  2199  94    1711  2256  2652
1561  2201  47    1070  2750  2179  1513  1298  1790  2958
1     41    126   287   1129  994   1725  2854  359   858
78    2395  2136  474   1906  1048  2673  2001  2759  2281
1653  1320  1482  2053  2390  1584  1584  1255  234   374


Before Sorting, values in Pointer Array and the value it is pointing at:
2333  2499  790   2249  2520  1919  1473  2677  2962  1697
2274  1981  2070  10    1383  511   809   180   1986  1862
2256  1068  547   1627  41    1391  2012  1454  1512  1423
1778  845   1275  2569  94    795   1840  1567  824   1802
264   450   783   2687  461   2518  198   1622  2698  2536
485   2307  604   1384  934   998   127   298   2452  1640
2074  1582  2837  349   1151  2932  1496  343   1851  2320
2145  2468  122   281   2155  583   2799  2705  2558  2850
2593  395   2157  549   2131  443   1547  2259  1093  1351
1251  167   2934  1088  516   1437  1372  2364  1781  224
2036  1278  44    2159  1559  2199  94    1711  2256  2652
1561  2201  47    1070  2750  2179  1513  1298  1790  2958
1     41    126   287   1129  994   1725  2854  359   858
78    2395  2136  474   1906  1048  2673  2001  2759  2281
1653  1320  1482  2053  2390  1584  1584  1255  234   374


After Sorting, values in Pointer Array and the value it is pointing at:
1     10    41    41    44    47    78    94    94    122
126   127   167   180   198   224   234   264   281   287
298   343   349   359   374   395   443   450   461   474
485   511   516   547   549   583   604   783   790   795
809   824   845   858   934   994   998   1048  1068  1070
1088  1093  1129  1151  1251  1255  1275  1278  1298  1320
1351  1372  1383  1384  1391  1423  1437  1454  1473  1482
1496  1512  1513  1547  1559  1561  1567  1582  1584  1584
1622  1627  1640  1653  1697  1711  1725  1778  1781  1790
1802  1840  1851  1862  1906  1919  1981  1986  2001  2012
2036  2053  2070  2074  2131  2136  2145  2155  2157  2159
2179  2199  2201  2249  2256  2256  2259  2274  2281  2307
2320  2333  2364  2390  2395  2452  2468  2499  2518  2520
2536  2558  2569  2593  2652  2673  2677  2687  2698  2705
2750  2759  2799  2837  2850  2854  2932  2934  2958  2962


After Sorting, values in Data Array:
1     10    41    41    44    47    78    94    94    122
126   127   167   180   198   224   234   264   281   287
298   343   349   359   374   395   443   450   461   474
485   224   516   349   549   583   604   783   41    583
234   41    224   858   934   994   998   1048  343   1070
1088  1093  1129  1151  1251  1255  516   1278  1298  1320
1351  1372  198   1151  395   474   1437  450   78    1482
1437  461   1513  1547  1559  1561  783   1372  1584  1584
1048  359   1320  1653  122   1711  1725  485   1781  1790
583   604   78    287   1906  47    127   281   2001  443
2036  2053  167   1351  122   2136  1437  1559  1320  1351
2179  2136  2136  41    298   1320  485   126   2281  1093
1482  1     281   2390  2395  1298  461   10    994   44
1070  1584  349   1048  1351  2673  94    858   343   1372
298   343   783   198   1584  10    474   78    1093  94

*/
