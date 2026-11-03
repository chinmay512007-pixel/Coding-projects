#include <gtest/gtest.h>
#include <limits>
extern "C"{
    #include "Trains.h"
    #include "ETA.h"

}
//Tests for calculate_travel_time
TEST(TravelTimeTest, CalculatesCorrectTime){//TEST CASE 1
    EXPECT_DOUBLE_EQ(calculate_travel_time(75,25),3.0);
}
TEST(TravelTimeTest, ZeroDistanceReturnsZero){
    EXPECT_DOUBLE_EQ(calculate_travel_time(0,25),0.0);//TEST CASE 2
}
TEST(TravelTimeTest, ZeroSpeedReturnsError){
    EXPECT_DOUBLE_EQ(calculate_travel_time(75,0),-1.0);//TEST CASE 3
}
TEST(TravelTimeTest, NegativeDistanceReturnsError){
    EXPECT_DOUBLE_EQ(calculate_travel_time(-75,25),-1.0);//TEST CASE 5
}
TEST(TravelTimeTest, NegativeSpeedReturnsError){
    EXPECT_DOUBLE_EQ(calculate_travel_time(75,-25),-1.0);//TEST CASE 6
}
TEST(TravelTimeTest, BothNegativeReturnsError){
    EXPECT_DOUBLE_EQ(calculate_travel_time(-75,-25),-1.0);//TEST CASE 7
}
TEST(TravelTimeTest, InfiniteSpeedReturnsError){//TEST CASE 8
    EXPECT_DOUBLE_EQ(calculate_travel_time(75, std::numeric_limits<double>::infinity()),-1.0);
}
TEST(TravelTimeTest, VeryLargeDistance){
    EXPECT_DOUBLE_EQ(calculate_travel_time(7500000,25),300000.0);//TEST CASE 9
}
TEST(TravelTimeTest, VeryLargeSpeed){
    EXPECT_DOUBLE_EQ(calculate_travel_time(75,2500000),0.00003);//TEST CASE 10
}

// Tests for calculate_arrival_time
TEST(ArrivalTimeTest, ZeroDelay){
    EXPECT_DOUBLE_EQ(calculate_arrival_time(10,0),600.0);//TEST CASE 1
}
TEST(ArrivalTimeTest, OnlyDelay){
    EXPECT_DOUBLE_EQ(calculate_arrival_time(0,10),10.0);//TEST CASE 2
}
TEST(ArrivalTimeTest, BothTravelTimeAndDelay){
    EXPECT_DOUBLE_EQ(calculate_arrival_time(10,10),610.0);//TEST CASE 3
}
TEST(ArrivalTimeTest, ZeroTravelTimeAndZeroDelay){
    EXPECT_DOUBLE_EQ(calculate_arrival_time(0,0),0.0);//TEST CASE 4
}
TEST(ArrivalTimeTest, NegativeDelayReturnsError){
    EXPECT_DOUBLE_EQ(calculate_arrival_time(10,-10),-1.0);//TEST CASE 5
}
TEST(ArrivalTimeTest, NegativeTravelTimeReturnsError){
    EXPECT_DOUBLE_EQ(calculate_arrival_time(-10,10),-1.0);//TEST CASE 6
}
TEST(ArrivalTimeTest, NegativeDelayAndNegativeTravelTimeReturnsError){
    EXPECT_DOUBLE_EQ(calculate_arrival_time(-10,-10),-1.0);//TEST CASE 7
}

//Tests For find_train_using_id
struct TrainTest : public ::testing::Test {
    struct Train trains[2] = {
        {11008, "Deccan Express", "Pune", "Mumbai", 15, DELAYED},
        {17613, "Panvel Nanded Express", "Parbhani", "Nanded", 0, ON_TIME}
    };
};

TEST_F(TrainTest, FindsFirstTrain) {
    EXPECT_EQ(find_train_using_id(trains, 2, 11008), 0);
}

TEST_F(TrainTest, FindsSecondTrain) {
    EXPECT_EQ(find_train_using_id(trains, 2, 17613), 1);
}

TEST_F(TrainTest, ReturnsMinusOneForMissingTrain) {
    EXPECT_EQ(find_train_using_id(trains, 2, 99999), -1);
}

TEST_F(TrainTest, ReturnsMinusOneForEmptyTrainList) {
    EXPECT_EQ(find_train_using_id(trains, 0, 11008), -1);
}