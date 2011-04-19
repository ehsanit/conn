#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "../src/tcpserver.c"

/*! 
    @author Ali, Kuhan, Mihail, Eugene
*/


/* Test 1: creating a socket */
void test1_create(void) {
    CU_ASSERT(socket_create() == 0);	
}

/* Test 2: binding address to a socket`*/
void test2_bind(void) {
    /* CU_ASSERT(gatherInfo()); - previous version of the function */
//    host_setup();
    CU_ASSERT(socket_bind() == 0);
}


int main() {
    /**************************************************************************/
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    /**************************************************************************/
    /* add socket tests */

    CU_pSuite Bind = CU_add_suite("Create and Connect socket", NULL, NULL);
    
    CU_add_test(Bind, "Creating a socket", test1_create);    
    CU_add_test(Bind, "Binding address to a socket", test2_bind);
    
    /**************************************************************************/

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();

}