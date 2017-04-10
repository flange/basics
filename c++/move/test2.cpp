#include <iostream>
#include <vector>

struct Noisy
{
    Noisy() { std::cout << "constructed\n"; }
    Noisy(const Noisy&) { std::cout << "copy-constructed\n"; }
    Noisy(Noisy&&) { std::cout << "move-constructed\n"; }
    ~Noisy() { std::cout << "destructed\n"; }
};

std::vector<Noisy> f()
{
    std::vector<Noisy> v = std::vector<Noisy>(3); // copy elision when initializing
                                                  // v from a temporary
                                                  // (guaranteed in C++17)
    return v; // NRVO from v to the returned nameless temporary (not guaranteed in C++17)
}             // or the move constructor is called if optimizations are disabled

void g(std::vector<Noisy> arg)
{
    std::cout << "arg.size() = " << arg.size() << '\n';
}

int main()
{
    std::vector<Noisy> v = f(); // copy elision in initialization of v
                                // from the result of f() (guaranteed in C++17)
    g(f());                     // copy elision in initialization of the
                                // parameter of g() from the result of f()
                                // (guaranteed in C++17)
}
