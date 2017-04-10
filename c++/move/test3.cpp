#include <iostream>
#include <stdio.h>

using namespace std;

class Intvec
{
public:
    explicit Intvec(size_t num = 0)
        : m_size(num), m_data(new int[m_size])
    {
        log("constructor");
        printf("data: %p\n", (void *) m_data);

    }

    ~Intvec()
    {
        log("destructor");

        if (m_data) {
            delete[] m_data;
            m_data = 0;
        }
    }

    Intvec(const Intvec& other)
        : m_size(other.m_size), m_data(new int[m_size])
    {
        log("copy constructor");

        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];
    }

    Intvec& operator=(const Intvec& other)
    {
        log("copy assignment operator");

        Intvec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);

        return *this;
    }

    Intvec& operator=(Intvec&& other) {
        log("move assignment operator");

        std::swap(m_size, other.m_size);
        std::swap(m_data, other.m_data);

        return *this;
    }

    size_t size() const {
      cout << "const size() &\n";
      return m_size;
    }
/*
    size_t size() & {
      cout << "size() &\n";
      return m_size;
    }

    int size() &&
    {
      cout << "size() &&\n";
      return m_size;
    }
*/


    int* data() & {
      cout << "data() &\n";
      return m_data;
    }

    const int* data() const & {
      cout << "const data() &\n";
      return m_data;
    }

    int* data() && {
      cout << "data() &&\n";
      return m_data;
    }

    void log(const char* msg)
    {
        cout << "[" << this << "] " << msg << "\n";
    }

    size_t m_size;
    int* m_data;
};


int main() {

  int *p;

  {
    Intvec v1{3};

    p = v1.data();
  }

  cout << p << "\n\n\n";



  Intvec&& t = Intvec{17};

  int *u = t.data();

  delete u;





  cout << "\n";





  cout << "\n";
  return 0;
}
