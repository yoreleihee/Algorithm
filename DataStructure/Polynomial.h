#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <assert.h>
#include <iostream>
#include <math.h>

using namespace std;

class Polynomial
{
public:
    Polynomial()
    {
        capacity_ = 0;
        coeffs_ = nullptr;
    }
    Polynomial(int max_degree)
    {
        assert(max_degree > 0);

        // 상수항 포함
        capacity_ = max_degree + 1;

        // 동적 메모리 할당
        coeffs_ = new float[capacity_];

        // 0으로 초기화
        for (int i = 0; i < capacity_; ++i)
        {
            coeffs_[i] = 0.0f;
        }
    }

    Polynomial(const Polynomial&  poly)
    {
        this->capacity_ = poly.capacity_;
        coeffs_ = new float[capacity_];
        for (int i = 0; i < capacity_; ++i)
        {
            coeffs_[i] = poly.coeffs_[i];
        }
    }
    ~Polynomial()
    {
        if (coeffs_)
            delete[] coeffs_;
    }

    int MaxDegree()
    {
        return capacity_ - 1;
    }

    void NewTerm(const float coef, const int exp)
    {
        assert(exp < capacity_);

        coeffs_[exp] = coef;
    }

    Polynomial Add(const Polynomial& poly)
    {
        assert(poly.capacity_ == this->capacity_);

        Polynomial temp(this->MaxDegree());

        for (int i = 0; i < capacity_; ++i)
        {
            temp.coeffs_[i] = this->coeffs_[i] + poly.coeffs_[i];
        }

        return temp;
    }

    Polynomial Mult(const Polynomial& poly)
    {
        assert(poly.capacity_ == this->capacity_);

        // coeff_[i]가 0.0f가 아닌 경우에 대해서만 계산 (곱하면 0이 되기 때문)

        Polynomial temp(this->MaxDegree() * 2);

        for (int i = 0; i < capacity_; ++i)
        {
            if (coeffs_[i] == 0)
                continue;

            for (int j = 0; j < capacity_; ++j)
            {
                if (poly.coeffs_[j] == 0)
                    continue;

                temp.coeffs_[i + j] += coeffs_[i] * poly.coeffs_[j];
            }
        }

        return temp;
    }

    float Eval(float x)
    {
        float temp = 0.0f;

        for (int i = 0; i < capacity_; ++i)
        {
            temp += coeffs_[i] * powf(x, float(i));
        }

        return temp;
    }

    void Print()
    {
        bool is_first = true; // 더하기 출력시 확인용

        for (int i = 0; i < capacity_; ++i)
        {
            if (coeffs_[i] != 0.0f)
            {
                if (!is_first)
                    cout << " + ";

                cout << coeffs_[i];

                if (i != 0)
                    cout << "*" << "x^" << i;

                is_first = false;
            }
        }

        cout << endl;
    }

private:
    int capacity_ = 0;
    float* coeffs_ = nullptr;
};


#endif //POLYNOMIAL_H
