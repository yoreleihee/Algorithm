#include <iostream>
using std::cout;

int Count(char *arr, int size, int key)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            count += 1;
        }
    }

    return count;
}

void Print(char arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort(char arr[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        char key = arr[i];
        int j = i;

        for (; j > 0 && arr[j - 1] > key; --j)
        {
            arr[j] = arr[j - 1];

            Print(arr, size);
        }

        arr[j] = key;
        Print(arr, size);
    }
}

int main()
{
    char arr[] = "ababcdfdceegaaafg";
    int n = sizeof(arr) - 1;

    if (n < 1)
    {
        return 0;
    }

    InsertionSort(arr, n);

    char c = arr[0];
    int count = 1;

    std::cout << c;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == c)
        {
            count += 1;
        }
        else
        {
            c = arr[i];
            cout << count << c;
            count = 1;
        }
    }

    std::cout << count;
}
