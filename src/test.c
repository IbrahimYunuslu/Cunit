#include"header.h"

#include<CUnit/CUnit.h>
#include<CUnit/Basic.h>

int init(void){return 0;}

int clean(void){return 0;}

void test1(void){

    CU_ASSERT(1);
    CU_ASSERT_FALSE( 0 );
    CU_ASSERT(sum(5,6)==11);
    CU_ASSERT(diff(5,6)==-1);
    
}

void test2(void){
    CU_ASSERT_DOUBLE_NOT_EQUAL(2.011,2.01,0.0); CU_ASSERT_DOUBLE_EQUAL(2.01,2.00,0.01); CU_ASSERT_NSTRING_EQUAL("ibo","ibocuk",3);
    CU_ASSERT_NSTRING_NOT_EQUAL("ibo","ibocuk",4);
    //cu_assert    
}

int main(void){
    CU_pSuite s1=NULL, s2=NULL; 
    
    if( CUE_SUCCESS != CU_initialize_registry() )
        return CU_get_error();

    s1 = CU_add_suite( "Test_S1",init,clean);
    if(s1==NULL){       
        CU_cleanup_registry();
        return CU_get_error();
    }

    s2 = CU_add_suite( "Test_S2",init,clean);
    if(s2==NULL){
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(s1,"\n problem cixsa ibo gehbedi  \n",test1))){
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((  NULL == CU_add_test(s2,"\n problem cixmasa ibo gehbedi  \n",test2))){
        CU_cleanup_registry();
        return CU_get_error();
    }
     
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_basic_show_failures(CU_get_failure_list());
    return CU_get_number_of_failures();


    return 0;
}
