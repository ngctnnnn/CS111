#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
int main () {
    freopen("DEBUG.INP", "r", stdin);
    freopen("DEBUG.OUT", "w", stdout);
    clock_t start, end;
	double cpu_time_used;
    
    int size;
    cin >> size;
    vector<int> a(size);
    // cin >> key;
    for (int i = 0; i < size;++i) 
        cin >> a[i];

    int key = a[0];
    cout << "Key: " << key << "\n\n";

    start = clock();
    cout << "std::find() value is ";
    cout << *find(a.begin(), a.end(), key) << endl;
    end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "time: " << cpu_time_used << " ms" << endl;

    start = clock();
    cout << "\nstd::binary_search() value is ";
    cout << (binary_search(a.begin(), a.end(), key) ? "True" : "False") << endl;
    end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << " ms" << endl;

    start = clock();
    cout << "\nstd::equal_range()'s range is [";
    cout << equal_range(a.begin(), a.end(), key).first - a.begin() << ";" <<
    equal_range(a.begin(), a.end(), key).second - a.begin() << ")" << endl;
    end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << " ms" << endl;

    start = clock();
    cout << "\nstd::upper_bound()'s range is ";
    cout << *upper_bound(a.begin(), a.end(), key) << endl;
    end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << " ms" << endl;

    start = clock();
    cout << "std::lower_bound()'s range is ";
    cout << *lower_bound(a.begin(), a.end(), key) << endl;
    end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "Time: " << cpu_time_used << " ms" << endl;
    return 0;
}

