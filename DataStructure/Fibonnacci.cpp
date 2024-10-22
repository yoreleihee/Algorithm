#include <iomanip>
#include <iostream>

using namespace std;

int RecurFibonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }
    return RecurFibonacci(n - 1) + RecurFibonacci(n - 2);
}

int Fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        int fn = 0;
        int prev1 = 0;
        int prev2 = 1;
        for (int i = 2; i <= n; i++) {
            fn = prev1 + prev2;

            prev1 = prev2;
            prev2 = fn;
        }

        return fn;
    }
}

int main() {
    cout << "Input      : ";
    for (int i = 0; i < 15; i++) {
        cout << setw(3) << i << " ";
    }
    cout << endl;

    cout << "Fibonnacci : ";
    for (int i = 0; i < 15; i++) {
        cout << setw(3) << RecurFibonacci(i) << " ";
    }
    cout << endl;

    cout << "Fibonnacci : ";
    for (int i = 0; i < 15; i++) {
        cout << setw(3) << Fibonacci(i) << " ";
    }
    cout << endl;
}