#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <gtest/gtest.h>
using namespace std;

pair<string, int>askSaman(const string& brand,const string& price){
    return {brand, stoi(price)};
}

template<typename ...Args>
pair<string, int> askSaman(const string& brand, const string& price, Args...args){
    int maxPrice = stoi(price);
    pair<string, int> brandPricePair = askSaman(args...);
    if (maxPrice > brandPricePair.second) {
        return {brand, maxPrice};
    } else {
        return brandPricePair;
    }
}

TEST(single_var, _sv1){
    pair<string, int> res = askSaman("Asus", "1200");
    EXPECT_EQ(res.first, "Asus");
}
TEST(single_var, _sv2){
    pair<string, int> res = askSaman("Lenevo", "5200");
    EXPECT_EQ(res.first, "Lenevo");
}


TEST(multi_var, _mv1){
    pair<string, int> res = askSaman("Asus", "1200", "Lenevo", "5200", "MacBook", "4500");
    EXPECT_EQ(res.first, "Lenevo");
}

TEST(multi_var, _mv2){
    pair<string, int> res = askSaman("Asus", "1200", "Lenevo", "5200", "MacBook", "4500", "HP", "5500");
    EXPECT_EQ(res.first, "HP");
}



int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

