#include "Polynomial.h"

int main()
{
    Polynomial poly1(10);
    poly1.NewTerm(1.0f, 0);
    poly1.NewTerm(1.5f, 1);
    poly1.NewTerm(2.0f, 2);
    poly1.Print();

    cout << poly1.Eval(0.0f) << endl; // 1 + 1.5*0 + 2*0^2 = 1
    cout << poly1.Eval(1.0f) << endl;
    cout << poly1.Eval(2.0f) << endl;

    cout << endl;

    Polynomial poly2(10);
    poly2.NewTerm(1,1);
    poly2.NewTerm(3,2);

    poly2.Print();

    cout << endl;

    cout << "Add()" << endl;

    Polynomial psum = poly1.Add(poly2);
    psum.Print(); // 1 + 2.5*x^1 + 5*x^2

    cout << endl;

    cout << "Mult()" << endl;

    poly1.Print(); // 1 + 1.5*x^1 + 2*x^2
    poly2.Print(); // 1*x^1 + 3*x^2

    Polynomial pmul = poly1.Mult(poly2);
    pmul.Print(); // 1*x^1 + 4.5*x^2 + 6.5*x^3 + 6*x^4

    return 0;
}