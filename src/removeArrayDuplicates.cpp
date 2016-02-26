/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int *Arr, int left, int mid, int right)
{
	int i, j, k;
	int leftTemp = mid - left + 1;
	int rightTemp = right - mid;

	/* create temp arrays */
	int *leftTempArray, *rightTempArray;

	leftTempArray = (int*)malloc(sizeof(int)*leftTemp);
	rightTempArray = (int*)malloc(sizeof(int)*rightTemp);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < leftTemp; i++)
		leftTempArray[i] = Arr[left + i];
	for (j = 0; j < rightTemp; j++)
		rightTempArray[j] = Arr[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = left;
	while (i < leftTemp && j < rightTemp)
	{
		if (leftTempArray[i] <= rightTempArray[j])
		{
			Arr[k] = leftTempArray[i];
			i++;
		}
		else
		{
			Arr[k] = rightTempArray[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < leftTemp)
	{
		Arr[k] = leftTempArray[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < rightTemp)
	{
		Arr[k] = rightTempArray[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the sub-array
of arr to be sorted */
void mergeSort(int *Arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2; //Same as (l+r)/2, but avoids overflow for large l and h
		mergeSort(Arr, left, mid);
		mergeSort(Arr, mid + 1, right);
		merge(Arr, left, mid, right);
	}
}

int removeArrayDuplicates(int *Arr, int len)
{
	if ((Arr == NULL) || (len < 0))
		return -1;

	mergeSort(Arr, 0, len - 1);
	int finalLen = 0;

	for (int index = 1; index < len; index++)
	{
		if (Arr[finalLen] != Arr[index])
			Arr[++finalLen] = Arr[index];
	}

	return finalLen+1;
}