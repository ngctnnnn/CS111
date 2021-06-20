#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void normal_multiply(int n){
    auto start = high_resolution_clock::now();
    long long mul = 1;
    for (int i = 1; i <= n; ++i){ 
        mul *= 4;
    }
    cout << "Normal mul: " << mul << endl;
    auto stop = high_resolution_clock::now();
    cout << "Time: " << duration_cast<microseconds>(stop-start).count() << "ms" << endl;
}
void shift_left(int n){
    auto start = high_resolution_clock::now();
    long long mul = 1;
    for (int i = 1; i <= n; ++i)
        mul <<= 2;
    cout << "\nShift left mul: " << mul << endl;
    auto stop = high_resolution_clock::now();
    cout << "Time: " << duration_cast<microseconds>(stop-start).count()<<"ms" << endl;
}
int main () {
    freopen("DEBUG.OUT", "w", stdout);
    int n = 20;
    normal_multiply(n);
    shift_left(n);
    return 0;
}
