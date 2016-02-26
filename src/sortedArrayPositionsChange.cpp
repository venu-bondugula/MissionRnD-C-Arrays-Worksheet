/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position,
			please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if ((Arr == NULL) || (len < 0))
	{
		return NULL;
	}
	
	int left = 0;
	int right = len - 1;

	while ((left < right) && (Arr[left] <= Arr[left + 1]))
	{
			left++;
	}
	while ((left < right) && (Arr[right] >= Arr[right - 1]))
	{
		right--;
	}
	int temp;

	temp = Arr[left];
	Arr[left] = Arr[right];
	Arr[right] = temp;
	
	return Arr;
}