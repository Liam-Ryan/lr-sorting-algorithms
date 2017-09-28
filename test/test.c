#include <check.h>
#include <stdlib.h>
#include <library.h>

//global for tests
int arr[15] = {8, 2, 3, 6, 125125, 123, 12541, 12, 1, 5, 21, 5, 1, 2, 4};
int sorted_arr[15] = {1, 1, 2, 2, 3, 4, 5, 5, 6, 8, 12, 21, 123, 12541, 125125};
int arr2[15] = {8, 2, 3, 6, 125125, 123, 12541, 12, 1, 5, 21, 5, 1, 2, 4};
int arr3[15] = {8, 2, 3, 6, 125125, 123, 12541, 12, 1, 5, 21, 5, 1, 2, 4};

void setup(void)
{

}

void teardown(void)
{

}

START_TEST(insertion_sort)
	{
		lrsortal_insertion_sort(arr, 15);
		for (int i = 0; i < 15; i++) {
			if (arr[i] != sorted_arr[i]) {
				ck_abort_msg("Error %i should be %i at index %i", arr[i], sorted_arr[i], i);
			}
		}
	}
END_TEST

START_TEST(merge_sort)
	{
		lrsortal_merge_sort(arr2, 0, 14);
		for (int i = 0; i < 15; i++) {
			if (arr2[i] != sorted_arr[i]) {
				ck_abort_msg("Error %i should be %i at index %i", arr[i], sorted_arr[i], i);
			}
		}
	}
END_TEST

START_TEST(bubble_sort)
	{
		lrsortal_bubble_sort(arr3, 15);
		for (int i = 0; i < 15; i++) {
			if (arr3[i] != sorted_arr[i]) {
				ck_abort_msg("Error %i should be %i at index %i", arr[i], sorted_arr[i], i);
			}
		}
	}
END_TEST

Suite *unit_tests(void)
{
	Suite *s = suite_create("Sample Unit Tests");

	TCase *tc_core = tcase_create("Core Test Case");
	//associate the setup and teardown functions with the test case
	tcase_add_checked_fixture(tc_core, setup, teardown);
	tcase_add_test(tc_core, insertion_sort);
	tcase_add_test(tc_core, merge_sort);
	tcase_add_test(tc_core, bubble_sort);
	suite_add_tcase(s, tc_core);

	return s;
}


int main()
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = unit_tests();
	sr = srunner_create(s);

	//Uncomment if you wish to debug unit tests or run valgrind on this file
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return number_failed < 1 ? EXIT_SUCCESS : EXIT_FAILURE;
}