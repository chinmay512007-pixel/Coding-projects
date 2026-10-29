#include <gtest/gtest.h>
#include "minfinder.h"
TEST(min_find,all_positive_numbers){
    int min;
    int arr[]={5,2,8,1,9};
    EXPECT_EQ(minfinder(arr,5,&min),1);
}
TEST(min_find,only_one_number){
    int min;
    int arr[]={10};
    EXPECT_EQ(minfinder(arr,1,&min),10);
}
TEST(min_find,all_negative_numbers){
    int min;
    int arr[]={-5,-2,-9,-1};
    EXPECT_EQ(minfinder(arr,4,&min),-9);
}
TEST(min_find,all_same_numbers){
    int min;
    int arr[]={100,100,100};
    EXPECT_EQ(minfinder(arr,3,&min),100);
}
TEST(min_find,empty_array){
    int min;
    int arr[]={};
    EXPECT_EQ(minfinder(arr,0,&min),-1);
}

TEST(min_find,null_output_pointer){
    int min;
    int arr[]={5,2,8,1,9};
    EXPECT_EQ(minfinder(arr,5,NULL),-1);
}