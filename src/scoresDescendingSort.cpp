/*
OVERVIEW:  You are given scores for students of a class in alphabetical order.
Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] 
(three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct student {
	char name[10];
	int score;
};

void merge(struct student *students, int left, int mid, int right)
{
	int i, j, k;
	int leftTemp = mid - left + 1;
	int rightTemp = right - mid;

	struct student *leftTempArray, *rightTempArray;

	leftTempArray = (struct student *)malloc(sizeof(struct student)*leftTemp);
	rightTempArray = (struct student *)malloc(sizeof(struct student)*rightTemp);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < leftTemp; i++)
		leftTempArray[i] = students[left + i];
	for (j = 0; j < rightTemp; j++)
		rightTempArray[j] = students[mid + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = left;
	while (i < leftTemp && j < rightTemp)
	{
		if (leftTempArray[i].score >= rightTempArray[j].score)
		{
			students[k] = leftTempArray[i];
			i++;
		}
		else
		{
			students[k] = rightTempArray[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < leftTemp)
	{
		students[k] = leftTempArray[i];
		i++;
		k++;
	}

	while (j < rightTemp)
	{
		students[k] = rightTempArray[j];
		j++;
		k++;
	}
}

void mergeSort(struct student *students, int left, int right)
{
	if (left < right)
	{
		int mid = (right + left) / 2;
		mergeSort(students, left, mid);
		mergeSort(students, mid + 1, right);
		merge(students, left, mid, right);
	}
}

void * scoresDescendingSort(struct student *students, int len) {
	if ((students == NULL) || (len < 0))
	{
		return NULL;
	}

	mergeSort(students, 0, len);
	return NULL;

}