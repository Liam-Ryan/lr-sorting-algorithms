#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

void lrsortal_insertion_sort(int *array, int size)
{
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int sort_val = array[i];
		while (j >= 0 && array[j] > sort_val) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = sort_val;
	}
}

void merge(int *array, int strt, int mid, int end)
{
	//temp arrays for lower and higher split of array
	int lowSize = mid - strt + 1;
	int highSize = end - mid;
	int lowArr[lowSize];
	int highArr[highSize];

	for (int i = strt; i <= mid; i++)
		lowArr[i - strt] = array[i];
	for (int i = mid + 1; i <= end; i++)
		highArr[i - (mid + 1)] = array[i];

	//indices to crawl the lower and higher temp arrays
	int i = 0;
	int j = 0;
	int index = i + j + strt;

	while (i < lowSize && j < highSize) {
		array[index] = min(lowArr[i], highArr[j]);
		if (array[index] == lowArr[i])
			i++;
		else
			j++;
		index++;
	}
	//finish adding the rest of the array that still has sorted elements in it
	if (i < lowSize) {
		while (i < lowSize)
			array[index++] = lowArr[i++];
	} else {
		while (j < highSize) {
			array[index++] = highArr[j++];
		}
	}

}

void lrsortal_merge_sort(int *array, int strt, int end)
{
	if (end > strt) {
		int mid = (int)floor((end - strt) / 2) + strt;
		lrsortal_merge_sort(array, strt, mid);
		lrsortal_merge_sort(array, mid + 1, end);
		merge(array, strt, mid, end);
	}
}
