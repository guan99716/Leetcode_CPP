#include <iostream>
#include <vector>
using namespace std;

void test(int n, vector<char> &current) {
    if (n == 0) {
        if(current.empty()) cout<< "empty";
        for (char c : current) {
                cout << c;
        }
        cout << endl;
        return;
    }

    current.push_back('A' + n - 1);
    test(n - 1, current);
    current.pop_back();
    test(n - 1, current);
}

int main() {
    vector<char> current;
    test(2, current);
}