#include <iostream>

using namespace std;

int RecurSum(int* arr, int n){
    
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return RecurSum(arr, n - 1) + arr[n - 1];
    }
}

int main(){
    int arr[] = {1,2,3};
    int count = sizeof(arr) / sizeof(arr[0]);

    int result = RecurSum(arr, count);
    cout << result << endl;
}
