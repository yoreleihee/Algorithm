#include <iomanip>
#include <iostream>

using namespace std;

void PrintHelper(int* arr, int left, int right)
{
    cout << "[" << left << "," << right << "]" << endl;

    cout << "Indices: ";
    for (int i = left; i <= right; i++)
    {
        cout << setw(2) << i << " ";
    }
    cout << endl;

    cout << "Values : " << setw(2);
    for (int i = left; i <= right; i++)
    {
        cout << setw(2) << arr[i] << " ";
    }
    cout << endl;
}

int BinarySearch(int* arr, int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        PrintHelper(arr, left, right);

        int middle = left + right / 2;
        cout << "middle : " << middle << endl;

        if (arr[middle] > x)
        {
            right = middle - 1;
            cout << "right : " << right << endl;
            continue;
        }
        else if (arr[middle] < x)
        {
            left = middle + 1;
            cout << "left : " << left << endl;
        }
        else
        {
            cout << "Found " << middle << endl;
            return middle;
        }
    }

    cout << "Not found" << endl;
    return -1;
}

int RecurBinarySearch(int * arr, int start, int end, int target) {
    int middle = (end + start) / 2;

    if (arr[middle] == target)
        return middle;

    if (start > end) {
        cout << "Not found" << endl;
        return -1;
    }
    if (arr[middle] > target)
        return RecurBinarySearch(arr, start, middle - 1, target);

    if (arr[middle] < target)
        return RecurBinarySearch(arr, middle + 1, end, target);
    return -1 ;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << BinarySearch(arr, n, -2) << endl;
    cout << RecurBinarySearch(arr, 0, n - 1, 1) << endl;
}
