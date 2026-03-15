#include <iostream>
#include <chrono>

using namespace std;

void shellSort(int a[], int n){
    auto start = chrono::high_resolution_clock::now();
    int compare = 0;

    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int temp = a[i];
            int j;

            for (j = i; j >= gap; j -= gap){
                compare++; 
                if (a[j - gap] > temp){
                    a[j] = a[j - gap];
                }
                else{
                    break;
                }
            }
            a[j] = temp;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    std::cout << "Running time (if required): " << duration.count() << " ms\n";
    std::cout << "Comparisions (if required): " << compare << '\n';
}

int main()
{
    int arr[] = {45, 23, 53, 11, 62, 34, 18, 99, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    return 0;
}