#ifndef SPARSEPOLYNOMIAL_H
#define SPARSEPOLYNOMIAL_H

#include <assert.h>
#include <iostream>

#include "Polynomial.h"

using namespace std;

struct Term
{
    float coef;
    int exp;
};

class SparsePolynomial {
public:
    SparsePolynomial()
    {
        num_terms_ = 0;
        capacity_ = 0;
        terms_ = nullptr;
    }

    ~SparsePolynomial()
    {
        if (terms_)
            delete[] terms_;
    }

    void NewTerm(float coef, int exp)
    {
        if (coef == 0.0f) return; // 0이면 추가하지 않음

        if (num_terms_ >= capacity_)
        {
            // capacity 증가
            capacity_ = capacity_ > 0 ? capacity_ * 2 : 1;
            Term* new_term = new Term[capacity_];

            // 원래 데이터 복사
            memcpy(new_term, terms_, sizeof(Term) * num_terms_);

            // 메모리 교체
            if (terms_) delete[] terms_;
            terms_ = new_term;
        }

        terms_[num_terms_].coef = coef;
        terms_[num_terms_].exp = exp;
        num_terms_++;
    }

    float Eval(float x)
    {
        float temp = 0.0f;

        // TODO:
        for (int i = 0; i < num_terms_; ++i)
        {
            temp += terms_[i].coef * powf(x, float(terms_[i].exp));
        }

        return temp;
    }

    SparsePolynomial Add(const SparsePolynomial& poly)
    {
        SparsePolynomial temp;

        int i = 0, j = 0;

        while (i < this->num_terms_ && j < poly.num_terms_)
        {
            int exp1 = this->terms_[i].exp;
            int exp2 = poly.terms_[j].exp;

            if (exp1 == exp2)
            {
                temp.NewTerm(this->terms_[i].coef + poly.terms_[j].coef, terms_[i].exp);
                ++i;
                ++j;
            }
            else if (this->terms_[i].exp > poly.terms_[j].exp)
            {
                temp.NewTerm(poly.terms_[j].coef, poly.terms_[j].exp);
                ++j;
            }
            else
            {
                temp.NewTerm(terms_[j].coef, terms_[j].exp);
                ++i;
            }

            if (i >= this->num_terms_)
            {
                if (j < poly.num_terms_)
                {
                    temp.NewTerm(poly.terms_[j].coef, poly.terms_[j].exp);
                    ++j;
                }
            }
            else if (j >= poly.num_terms_)
            {
                if (i < num_terms_)
                {
                    temp.NewTerm(terms_[i].coef, terms_[i].exp);
                    ++i;
                }
            }
        }

        return temp;
    }

    void Print()
    {
        bool is_first = true; // 더하기 출력시 확인용

        for (int i = 0; i < num_terms_; ++i)
        {
            if (!is_first)
                cout << " + ";

            cout << terms_[i].coef;

            if (terms_[i].exp != 0)
                cout << "*" << "x^" << terms_[i].exp;

            is_first = false;
        }

        cout << endl;
    }

private:
    Term* terms_ = nullptr;
    int num_terms_ = 0;
    int capacity_ = 0;
};



#endif //SPARSEPOLYNOMIAL_H
