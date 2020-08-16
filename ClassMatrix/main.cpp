#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

/*
bool MatrixCompare(const vector<vector<int>> &lhs_mx,
                    const vector<vector<int>> &rhs_mx) {
    if(lhs_mx.size() != rhs_mx.size()) {
        return false;
    } else {
        for(auto& row : lhs_mx) {
            for(auto& item : row) {
                if(lhs_mx.at(item) != rhs_mx.at(item)) {
                    return false;
                }
            }
        }
    }
    return true;
}
*/

class Matrix {
public:
    Matrix() {
        //По умолчанию: матрица с 0 строк, и 0 рядков
        row = 0;
        col = 0;
    }

    Matrix(int num_rows, int num_cols) {
        if(num_rows > 0 and num_cols > 0 or num_cols == 0 or num_rows == 0) {
            Reset(num_rows,num_cols);
        } else {
            string error = "Nums of rows or cols are invalid";
            throw out_of_range(error);
        }
    }

    void Reset(int new_num_rows, int new_num_cols) {
        if(new_num_rows > 0 and new_num_cols > 0 or new_num_cols == 0
        or new_num_rows == 0) {
            row = new_num_rows;
            col = new_num_cols;
            matrix.assign(row,vector<int>(col));
        } else {
            string error = "Nums of rows or cols are invalid";
            throw out_of_range(error);
        }
    }

    int  At(int number_row, int number_col) const {
        return matrix.at(number_row).at(number_col);
    }

    int& At(int number_row, int number_col) {
        return matrix.at(number_row).at(number_col);
    }

    int GetNumRows()  const {
        return row;
    }

    int GetNumColumns()  const {
        return col;
    }

private:
    int row, col;
    vector<vector<int>>matrix;
};

istream& operator >> (istream& is, Matrix& mx) {
    if(is) {
            int r;
            int c;
            is >> r >> c;
            mx = Matrix(r, c);
          for(int row = 0; row < r; row++) {
              for(int col = 0; col < c; col++) {
                  is >> mx.At(row,col);
              }
          }
    }
    return is;
}

ostream& operator << (ostream& os, const Matrix& mx) {
    for(int row = 0; row < mx.GetNumRows(); row++) {
        for(int col = 0; col < mx.GetNumColumns(); col++) {
            os << mx.At(row, col) << " ";
        }
        os << endl;
    }
    return os;
}

bool operator == (const Matrix& lhs_mx, const Matrix& rhs_mx) {
    if(lhs_mx.GetNumRows() == 0 or lhs_mx.GetNumColumns() == 0) {
        return true;
    } else if (lhs_mx.GetNumRows() != rhs_mx.GetNumRows() or
                rhs_mx.GetNumColumns() != rhs_mx.GetNumColumns()) {
        return true;
    } else {
        int equal_rows = lhs_mx.GetNumRows();
        int equal_cols = lhs_mx.GetNumColumns();
        for(int r = 0; r < equal_rows; r++) {
            for(int c = 0; c < equal_cols; c++) {
                if(lhs_mx.At(r,c) != rhs_mx.At(r,c)) {
                    return false;
                }
            }
        }
    }
    return true;
}

Matrix operator + (const Matrix& lhs_mx, const Matrix& rhs_mx) {
    if(lhs_mx.GetNumRows() == 0 or lhs_mx.GetNumColumns() == 0) {
        Matrix result(0,0);
        return result;
    } else if (lhs_mx.GetNumRows() != rhs_mx.GetNumRows() or
        rhs_mx.GetNumColumns() != rhs_mx.GetNumColumns()) {
        string error = "Count of rows or cols are dismatch";
        throw invalid_argument(error);
    } else {
        int equal_rows = lhs_mx.GetNumRows();
        int equal_cols = lhs_mx.GetNumColumns();
        Matrix result(equal_rows,equal_cols);
        for(int r = 0; r < equal_rows; r++) {
            for(int c = 0; c < equal_cols; c++) {
                result.At(r,c) = lhs_mx.At(r,c) + rhs_mx.At(r,c);
            }
        }
        return result;
    }
}

int main() {
    try {
        Matrix one, two;
        cin >> one;
        cin >> two;

        if(one == two) {
            cout << "Matrices are identical" << endl;
        } else {
            cout << "Matrices are not identical" << endl;
        }

        Matrix three;
        three = one + two;
        cout << three;

    } catch (out_of_range& ex) {
        cout << ex.what() << endl;
    } catch (invalid_argument& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}


