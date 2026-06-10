#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

int main(void) {
    CU_initialize_registry();
    CU_pSuite suiteReverse= CU_add_suite("Binary Tree Test Suite", 0, 0);
    //CU_add_test(suiteBST, "test_dfsTraversal",test_dfsTraversal);
    //CU_add_test(suiteBST, "test_lueTiedostoBinValmiiksitasapainossa", test_lueTiedostoBinValmiiksiTasapainossa);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}