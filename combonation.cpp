#include <iostream>
#include <vector>
using namespace std;
void printVec(vector<char> v) {
    if (v.empty())
        cout << "empty";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << '\n';
}
void subset(vector<char>& items, int index, vector<char>& current) {
    // current -> stack
    int n = items.size();
    if (index == n){
        printVec(current);
        return;       
    }
    subset(items, index+1, current);
    current.push_back(items[index]);
    subset(items, index+1, current);
    current.pop_back();
    
}


int main() {
    vector<char> items = {'A', 'B', 'C'};
    vector<char> current;
    subset(items, 0, current);
    return 0;
}
