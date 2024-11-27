#include "Vector.cpp"
using namespace amir;
int main() {
    amir::Vector<int> vec(4, 19);
    vec.push_back(20);
    vec.push_back(21);

    try {
        for (int i = 0; i < 6; ++i) {
            cout<<vec.at(i)<<endl;

        }

    } catch (const out_of_range &e) {
        cout << e.what() << endl;
    }
}