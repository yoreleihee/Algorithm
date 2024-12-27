#include "MyString.h"
#include <iostream>

using namespace std;

int main() {
    MyString* str = new MyString("Hello");

    MyString str2 = *str;

    cout << boolalpha;
    cout << "str is Empty : " << str->IsEmpty() << endl;
    cout << "str, str2 is Equal : " << str->IsEqual(str2) << endl;

    MyString* resizeStr = new MyString("he");
    resizeStr->Resize(3);

    MyString substr = str->Substr(2, 3);
    cout << "substr : ";
    substr.Print();

    MyString concatStr = str->Concat(("Add"));
    cout << "concatStr : ";
    concatStr.Print();

    cout << "Found at " << str->Find(("lloo")) << endl;


    MyString str4("ABCDE");
    for (int i = 0; i <= str4.Length(); i++)
    {
        MyString str5 = str4.Insert(MyString("123"), i);
        str5.Print();
    }
}
