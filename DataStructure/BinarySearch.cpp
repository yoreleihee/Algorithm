#include <iostream>
#include <iomanip>
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

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    // int arr[] = {2,4,5,5,7,8,9,10,11};

    int n = sizeof(arr) / sizeof(arr[0]);

    BinarySearch(arr, n, 3);
    return 0;
}