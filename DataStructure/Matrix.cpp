#include "Matrix.h"

#include <assert.h>
#include <iostream>

using namespace std;

// c + num_cols * r

Matrix::Matrix(int num_rows, int num_cols)
{
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    values = new float[num_rows_ * num_cols_];
    // 0으로 초기화
    for (int i = 0; i < num_rows_ * num_cols_; ++i)
    {
        values[i] = 0.0f;
    }
}

Matrix::Matrix(const Matrix &b)
{
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;
    values = new float[num_rows_ * num_cols_];

    for (int i = 0 ; i < num_rows_ * num_cols_; ++i)
    {
        values[i] = b.values[i];
    }
}

Matrix::~Matrix()
{
    delete[] values;
    values = nullptr;
}


void Matrix::SetValue(int row, int col, float value)
{
    int idx = col + num_cols_ * row;
    values[idx] = value;
}


float Matrix::GetValue(int row, int col) const
{
    int idx = col + num_cols_ * row;
    return values[idx];
}


Matrix Matrix::Transpose()
{
    Matrix temp(num_cols_, num_rows_);

    for (int r = 0; r < num_rows_; ++r)
        for (int c = 0; c < num_cols_; ++c)
            temp.SetValue(c, r, GetValue(r, c));

    // Legacy
    // for (int r = 0; r < num_rows_; ++r)
    // {
    //     for (int c = 0; c < num_cols_; ++c)
    //     {
    //         int idx = c + num_cols_ * r;
    //         // 0, 0 -> 0, 0
    //         // 0, 1 -> 1, 0
    //         // 0, 2 -> 2, 0
    //         int transposeIdx = r + num_rows_ * c;
    //         temp.values[transposeIdx] = values[idx];
    //     }
    // }

    return temp;
}

Matrix Matrix::Add(const Matrix &b)
{
    assert(b.num_cols_ == num_cols_);
    assert(b.num_rows_ == num_rows_);

    Matrix temp(num_rows_, num_cols_);

    for (int r = 0; r < num_rows_; ++r)
        for (int c = 0; c < num_cols_; ++c)
            temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

    return temp;
}

void Matrix::Print()
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
    Matrix m1(3, 4);
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
    Matrix add = m1.Add(m1);
    add.Print();

    cout << endl;

    cout << "Transpose m1" << endl;
    Matrix tr = m1.Transpose();
    tr.Print();

    return 0;
}





