#include "Vector.cpp"
using namespace amir;
int main() {
    amir::Vector<int> vec(4, 19);
    vec.push_back(20);
    vec.push_back(21);

    try {
        cout << vec.at(3) << endl;
    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}