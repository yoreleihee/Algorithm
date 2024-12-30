#include "Array2D.h"

#include <assert.h>
#include <iostream>

using namespace std;

Array2D::Array2D(int num_rows, int num_cols)
{
    arrays_ = new float *[num_rows];

    for (int r = 0; r < num_rows; ++r)
    {
        arrays_[r] = new float[num_cols];

        for (int c = 0; c < num_cols; ++c)
        {

            arrays_[r][c] = 0.0f;
        }
    }

    num_rows_ = num_rows;
    num_cols_ = num_cols;
}

Array2D::Array2D(const Array2D &b)
{
    arrays_ = new float *[b.num_rows_];

    for (int r = 0; r < b.num_rows_; ++r)
    {
        arrays_[r] = new float[b.num_cols_];
        for (int c = 0; c < b.num_cols_; ++c)
        {
            SetValue(r, c, b.GetValue(r, c));
        }
    }

    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;
}

Array2D::~Array2D()
{
    if (arrays_)
    {
        for (int r = 0; r < num_rows_; ++r)
            delete[] arrays_[r];

        delete[] arrays_;
    }
}

float Array2D::GetValue(int row, int col) const
{
    return arrays_[row][col];
}

void Array2D::SetValue(int row, int col, float value)
{
    arrays_[row][col] = value;
}

Array2D Array2D::Transpose()
{
    Array2D temp(num_cols_, num_rows_);

    for (int r = 0; r < num_rows_; ++r)
        for (int c = 0; c < num_cols_; ++c)
            temp.SetValue(c, r, GetValue(r, c));

    return temp;
}

Array2D Array2D::Add(const Array2D &b)
{
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Array2D temp(num_rows_, num_cols_);

    for (int r = 0; r < num_rows_; ++r)
        for (int c = 0; c < num_cols_; ++c)
            temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

    return temp;
}

void Array2D::Print()
{
    for (int r = 0; r < num_rows_; r++)
    {
        for (int c = 0; c < num_cols_; c++)
        {
            cout << GetValue(r, c) << " ";
        }
        cout << endl;
    }
}

int main()
{
    Array2D m1(3, 4);
    m1.SetValue(0, 0, 1.0f);
    m1.SetValue(0, 1, 2.0f);
    m1.SetValue(0, 2, 3.0f);
    m1.SetValue(1, 0, 0.0f);
    m1.SetValue(1, 1, 4.0f);
    m1.SetValue(1, 2, 5.0f);
    m1.SetValue(2, 3, 7.0f);

    m1.Print();

    cout << endl;

    cout << "m1 + m1" << endl;
    Array2D add = m1.Add(m1);
    add.Print();

    cout << endl;

    cout << "Transpose m1" << endl;
    Array2D tr = m1.Transpose();
    tr.Print();
    return 0;
}


