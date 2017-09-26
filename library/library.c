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
	int lowSize = mid - strt + 1;
	int highSize = end - mid;
	int lowArr[lowSize];
	int highArr[highSize];
	for (int i = strt; i <= end; i++) {
		if (i <= mid)
			lowArr[i] = array[i];
		else
			highArr[i - mid] = array[i];
	}

	int i = 0;
	int j = 0;
	while( i < lowSize && j < highSize) {
		int index = i + j;
		array[index] = min(lowArr[i], highArr[j]);
		if (array[index] == lowArr[i])
			i++;
		else
			j++;
	}
	if( i < lowSize) {
		while( i < lowSize )
			array[j + i] = lowArr[i++];
	} else {
		while (j < highSize) {
			array[j + i] = highArr[j++];
		}
	}

}

void lrsortal_merge_sort(int *array, int strt, int end)
{
	if (end > strt) {
		int mid = floor((end - strt) / 2) + strt;
		lrsortal_merge_sort(array, strt, mid);
		lrsortal_merge_sort(array, mid + 1, end);
		merge(array, strt, mid, end);
	}
}
