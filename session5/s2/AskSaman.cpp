#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>
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

int main(){
    pair<string, int> res = askSaman("Asus", "1200", "Lenevo", "5200", "MacBook", "4500");
    cout<<"the most expensive brand: "<<res.first<<endl<<"the brand's price: "<<res.second<<endl;
    return 0;
}

