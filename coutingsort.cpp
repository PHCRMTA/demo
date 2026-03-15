#include <iostream>
#include <chrono>
#include <vector> 
using namespace std;

void countingSort(int a[], int n){
    auto start = chrono::high_resolution_clock::now();
    int compare = 0;

    int max_val = a[0];
    for (int i = 1; i < n; i++){
        compare++; 
        if (a[i] > max_val)
        {
            max_val = a[i];
        }
    }

    vector<int> count(max_val + 1, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++){
        count[a[i]]++;
    }

    for (int i = 1; i <= max_val; i++){
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--){
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++){
        a[i] = output[i];
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    std::cout << "Running time (if required): " << duration.count() << " ms\n";
    std::cout << "Comparisions (if required): " << compare << '\n';
}

int main(){
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 9, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    return 0;
}