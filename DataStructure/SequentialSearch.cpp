#include <iostream>

using namespace std;

void Print(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort(int* arr, int size){
    int i, key, j;
    for (i = 1; i < size ; ++i) {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j= j - 1;
        }

        arr[j + 1] = key;
    }
}

int Count(int* arr, int size, int key){
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key){
            count += 1;
        }
    }

    return count;
}

int SequentialSearch(int* arr, int size, int key){
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key){
            return i;
        }
    }

    return -1;
}

int SortedCountHelper(int* arr, int size, int key, int start){
    int count = 0;

    for (int i = start; i < size; ++i) {
        if (arr[i] == key){
            count += 1;
        } else{
            break; // 조기 종료
        }
    }

    return count;
}

int SortedCount(int* arr, int size, int key){
    // 처음 인덱스
    int i = SequentialSearch(arr, size, key);

    if (i >= 0){
        return SortedCountHelper(arr, size, key, i + 1) + 1;
    } else{
        return 0;
    }
}

int main(){
    int arr[] = {8, 1, 1, 3, 2, 5, 1, 2, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Count 9 = " << Count(arr, size, 9) << endl;
    cout << "Count 2 = " << Count(arr, size, 2) << endl;
    cout << "Count 8 = " << Count(arr, size, 8) << endl;
    cout << "Count 1 = " << Count(arr, size, 1) << endl;
    cout << endl;

    cout << "Search 2 = " << SequentialSearch(arr, size, 2) << endl;
    cout << "Search 5 = " << SequentialSearch(arr, size, 5) << endl;
    cout << "Search 9 = " << SequentialSearch(arr, size, 9) << endl;
    cout << endl;

    InsertionSort(arr, size);

    Print(arr, size);

    cout << "Sorted Count 9 = " << SortedCount(arr, size, 9) << endl;
    cout << "Sorted Count 2 = " << SortedCount(arr, size, 2) << endl;
    cout << "Sorted Count 8 = " << SortedCount(arr, size, 8) << endl;
    cout << "Sorted Count 1 = " << SortedCount(arr, size, 1) << endl;

    return 0;
}