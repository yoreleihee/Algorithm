#ifndef MYSTRING_H
#define MYSTRING_H
#include <assert.h>
#include <iostream>

using namespace std;

class MyString
{
public:
    MyString()
    {
        str_ = nullptr;
        size_ = 0;
    }

    MyString(const char* init)
    {
        size_ = 0;
        while (init[size_] != '\0')
            size_++;

        str_ = new char[size_];
        memcpy(str_, init, size_);
    }

    MyString(const MyString& str) // MyString의 다른 instance로부터 초기화
    {
        size_ = str.size_;
        str_ = new char[size_];
        memcpy(str_, str.str_, size_);
    }

    ~MyString()
    {
        if (str_ != nullptr)
        {
            delete[] str_;
            // 생략 가능
            str_ = nullptr;
            size_ = 0;
        }
    }

    bool IsEmpty()
    {
        return size_ <= 0;
    }

    bool IsEqual(const MyString& str)
    {
        // 오답
        // return str.str_ == str_;
        // 위 코드는 같은 객체인지 비교하는 것. 문자열이 같음을 검사하는 것이 아님.

        if (str.size_ != size_)
            return false;

        for (int i = 0; i < size_; ++i)
        {
            if (str.str_[i] != str_[i])
                return false;
        }

        return true;
    }

    int Length()
    {
        return size_;
    }

    void Resize(int new_size)
    {
        if (new_size == size_)
            return;

        char* newStr = new char[new_size];

        memcpy(newStr, str_, size_ < new_size ? size_ : new_size);
        delete[] str_;
        str_ = newStr;
        size_ = new_size;
    }

    MyString Substr(int start, int num)
    {
        assert(start + num - 1 < this->size_);

        // refactor
        MyString temp;
        temp.Resize(num);

        for (int i = 0; i < num; ++i)
        {
            temp.str_[i] = str_[i + start];
        }

        return temp;

        // legacy
        char* substr = nullptr;
        substr = new char[num + 1];

        for (int i = 0; i < num; ++i)
        {
            substr[i] = str_[start + i];
        }

        substr[num] = '\0';

        return MyString(substr);
    }

    MyString Concat(const MyString& app_str)
    {
        MyString temp;
        temp.Resize(size_ + app_str.size_);

        memcpy(temp.str_, str_, size_);
        memcpy(&temp.str_[size_], app_str.str_, app_str.size_);

        return temp;
    }

    void Print()
    {
        for (int i = 0; i < size_; ++i)
        {
            cout << str_[i];
        }

        cout << endl;
    }

    MyString Insert(const MyString& insertStr, int insertIdx)
    {
        // refactor
        MyString temp;
        temp.Resize(size_ + insertStr.size_);

        for (int i = 0; i < insertIdx; ++i)
        {
            temp.str_[i] = str_[i];
        }

        for (int i = 0; i < insertStr.size_; ++i)
        {
            temp.str_[i + insertIdx] = insertStr.str_[i];
        }

        for (int i = insertIdx + insertStr.size_; i < size_ + insertStr.size_; ++i)
        {
            temp.str_[i] = str_[i - insertStr.size_];
        }

        return temp;
        // legacy
        // char* newStr = new char[size_ + insertStr.size_ + 1];
        //
        // int saveIdx = 0;
        // for (int i = 0; i < insertIdx; ++i)
        // {
        //     newStr[i] = str_[i];
        //     ++saveIdx;
        // }
        //
        // // 삽입할 문자열을 복사
        // for (int i = 0; i < insertStr.size_; ++i)
        // {
        //     newStr[insertIdx + i] = insertStr.str_[i];
        // }
        //
        // // InsertIdx 이후의 문자열을 복사
        // for (int i = 0; i < size_ - saveIdx; ++i)
        // {
        //     newStr[insertStr.size_ + saveIdx + i] = str_[saveIdx + i];
        // }
        //
        // newStr[size_ + insertStr.size_] = '\0';
        //
        // return {newStr};
    }

    int Find(MyString pat)
    {
        // 찾으려는 문자열의 사이즈보다 검사할 문자열의 사이즈가 적게 남아있다면 검사할 필요 없음
        for (int i = 0; i <= size_ - pat.size_; ++i)
        {
            for (int j = 0; j < pat.size_; ++j)
            {
                if (str_[i + j] != pat.str_[j])
                    break;

                if (j == pat.size_ - 1)
                    return i;
            }
        }

        return -1;
    }

private:
    char* str_ = nullptr;
    int size_ = 0; // 글자 수
};



#endif //MYSTRING_H
