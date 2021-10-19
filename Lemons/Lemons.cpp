#include <iostream>

using namespace std;

int main() {
    int pumps, m , s , x;
    cin >> pumps >> m >> s;
    int i = 1, total = 0;
    while (i != pumps){
        x = (i+pumps)/2 + (i+pumps)%2;
        total += (x-i)*m + s;
        i = x;
    }
    cout << total;
}
