#include <iostream>

using namespace std;

bool CheckSorted(int* arr, int size){
    for (int i = 0; i < size -1; ++i) {
        if (arr[i] > arr[i + 1]){
            return false;
        }
    }

    return true;
}

void SelectionSort(int* arr, int size){
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j) {
            if (arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < 3; ++j) {
            for (int i = 0; i < 3; ++i) {
                int arr[3] = {i, j, k};

                int size = sizeof(arr) / sizeof(arr[0]);

                for (int e = 0; e < size; ++e) {
                    cout << arr[e] << " " << flush;
                }

                cout << " -> " << flush;

                SelectionSort(arr, size);

                for (int e = 0; e < size; ++e) {
                    cout << arr[e] << " " << flush;
                }

                cout << boolalpha;
                cout << CheckSorted(arr, size);
                cout << endl;
            }
        }
    }

    return 0;
}
