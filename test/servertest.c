#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "../src/tcpserver.c"

/*Ali & Kuhan*/


/* Trying to create and connect socket*/
void TestBind(void) {
    /* CU_ASSERT(gatherInfo()); - previous version of the function */
    host_setup();
    socket_create(); //CU_ASSERT(createSocket());
    CU_ASSERT(socket_bind() == 0);
}


int main() {
    /**************************************************************************/
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    /**************************************************************************/
    /* add socket tests */

    CU_pSuite Bind = CU_add_suite("Create and Connect socket", NULL, NULL);
    CU_add_test(Bind, "testing to create a socket", TestBind);
    /**************************************************************************/

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}