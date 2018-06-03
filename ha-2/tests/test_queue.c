#include <check.h>
#include "priority_queue.h"

START_TEST (test_insert)
    {
        insert(5, 5);
        insert(10, 10);
        insert(3, 111);
        insert(1, -3);
        insert(0, 0);
        ck_assert(1 == extract_min());
    }
END_TEST

START_TEST (test_min)
    {
        ck_assert(0 == extract_min());
        ck_assert(5 == extract_min());
    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("priority queue");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_insert);
    tcase_add_test(tcase, test_min);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;

}