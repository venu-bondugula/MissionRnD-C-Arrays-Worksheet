/*
OVERVIEW:  You are given scores for students of a class in alphabetical order.
Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] 
(three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <stdio.h>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

void mergeDesc(struct student *students, int left, int mid, int right)
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

void mergeSortDesc(struct student *students, int left, int right)
{
	if (left < right)
	{
		int mid = (right + left) / 2;
		mergeSortDesc(students, left, mid);
		mergeSortDesc(students, mid + 1, right);
		mergeDesc(students, left, mid, right);
	}
}


struct student ** topKStudents(struct student *students, int len, int K) {
	if ((students == NULL) || (len < 0) || (K <= 0))
		return NULL;

	struct student ** result = (struct student **)malloc(sizeof(struct student *)*K);

	mergeSortDesc(students, 0, len - 1);
	for (int i = 0; i < K; i++)
	{
		result[i] = &students[i];
	}

	return result;
}