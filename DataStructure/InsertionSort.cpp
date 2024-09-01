#include <iostream>

using namespace std;

void Print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort(int arr[], int size){
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i;

        for (; j > 0 && arr[j - 1] > key ; --j) {
            arr[j] = arr[j - 1];

            Print(arr, size);
        }

        arr[j] = key;
        Print(arr, size);
    }
}

int main(){
    int arr[] = {1,2,4,5,3,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(arr, size);
}