#include <iostream>

template <typename T, std::size_t R, std::size_t C>
class Matrix_A {

public:
  Matrix_A() {
    std::cout << "Rows: " << R << " Columns: " << C << "\n";
  }

};

template <typename T>
class Matrix_B {

private:
  std::size_t rows, columns;

public:
  Matrix_B(std::size_t r, std::size_t c) : rows{r}, columns{c} {
    std::cout << "Rows: " << rows << " Columns: " << columns << "\n";
  }


};


int main()
{
  Matrix_A<int, 3, 5> m1;

  Matrix_B<int> m2(3, 5);

}
