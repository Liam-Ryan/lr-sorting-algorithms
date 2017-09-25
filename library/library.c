#include "library.h"

int *lrsortal_insertion_sort(int *array, int size)
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