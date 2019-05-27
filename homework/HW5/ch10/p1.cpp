#include <cstring>
#include <iostream>
using namespace std;

class TwoD {
   public:
    TwoD(int, int);
    TwoD(const TwoD&);
    ~TwoD();

    double& mutator(int row, int column) const { return arr[row][column]; } 
    /*
    * set mutator function to be a const,
    * such that this function cannot modify any value in this funtion area,
    * but the return value can be read/write!!
    */
    inline void setValue(int row, int column, int value) { this->arr[row][column] = value; }
    inline const int getColumn() const { return Max_column; }
    inline const int getRow() const { return Max_row; }

    friend const TwoD& operator+(const TwoD&, const TwoD&);
    TwoD& operator=(const TwoD&);

   private:
    double** arr;
    int Max_row, Max_column;
};

void printTwoD(TwoD& current) {
    for (int i = 0; i < current.getRow(); i++) {
        for (int j = 0; j < current.getColumn(); j++)
            cout << current.mutator(i, j) << " ";
        cout << endl;
    }
}

int main() {
    int row, column;

    cout << "Enter the row and column dimensions of the array" << endl;
    cin >> row >> column;
    TwoD matrix1(row, column);
    cout << "Enter " << row << " rows of " << column << " doubles for each." << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> matrix1.mutator(i, j);

    cout << "Enter the row and column dimensions of the array" << endl;
    cin >> row >> column;
    TwoD matrix2(row, column);
    cout << "Enter " << row << " rows of " << column << " doubles for each." << endl;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            cin >> matrix2.mutator(i, j);

    if (matrix1.getColumn() != matrix2.getColumn() || matrix1.getRow() != matrix2.getRow()) {
        cerr << "Input error!" << endl;
        exit(1);
    }
    cout << "Assigning matrix 2 to matrix 3" << endl;
    TwoD matrix3 = matrix2;
    cout << "Displaying the 2 dim array, matrix3 result from assignment." << endl;
    cout << "Row " << row << "  Cols " << column << endl;
    printTwoD(matrix3);

    TwoD matrix_add = matrix1 + matrix2;
    cout << "Row " << matrix_add.getRow() << "  Cols " << matrix_add.getColumn() << endl;
    printTwoD(matrix_add);

    return 0;
}

double** allocArray(int row, int column) {
    double** arr = new double*[row];
    for (int i = 0; i < row; i++)
        arr[i] = new double[column];
    return arr;
}

TwoD::TwoD(int rol = 2, int column = 2) : Max_row(rol), Max_column(column) {
    arr = allocArray(Max_row, Max_column);
}

TwoD::TwoD(const TwoD& source) {
    this->Max_column = source.Max_column;
    this->Max_row = source.Max_row;
    this->arr = allocArray(this->Max_row, this->Max_column);
    memcpy(this->arr, source.arr, sizeof(double) * (this->Max_column) * (this->Max_row));
}

const TwoD& operator+(const TwoD& a, const TwoD& b) {
    TwoD* result = new TwoD(a);
    for (int i = 0; i < result->Max_row; i++)
        for (int j = 0; j < result->Max_column; j++)
            result->setValue(i, j, a.mutator(i, j) + b.mutator(i, j));
    return *result;
}

TwoD& TwoD::operator=(const TwoD& source) {
    if (this != &source) {
        for (int i = 0; i < this->Max_row; i++)
            delete[] this->arr[i];
        delete[] this->arr;

        this->Max_row = source.Max_row;
        this->Max_column = source.Max_column;
        this->arr = allocArray(this->Max_row, this->Max_row);
        memcpy(this->arr, source.arr, sizeof(double) * (this->Max_column) * (this->Max_row));
    }
    return *this;
}

TwoD::~TwoD() {
    for (int i = 0; i < this->Max_row; i++)
        delete[] this->arr[i];
    delete[] this->arr;
}