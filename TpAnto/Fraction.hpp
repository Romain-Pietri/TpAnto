#include <iostream>
using namespace std;

template <typename T>
class Fraction
{
private:
    T num_ = 0, den_ = 1;

public:
    Fraction();
    Fraction(const Fraction<T>& fraction);
    Fraction(const T& num, const T& den);
    void set_num(const T& num);
    void set_den(const T& deno);
    T get_num() const;
    T get_den() const;

    Fraction<T> operator+(const Fraction<T>& fraction);
    bool operator==(const Fraction<T>& fraction) const;
    bool operator<(const Fraction<T>& fraction) const;

    Fraction<T> operator+(const T& number);
    operator T();
};

template <typename T>
ostream& operator<<(ostream& os, const Fraction<T>& fraction);

template <typename T>
istream& operator>>(istream& os, Fraction<T>& fraction);

struct Student {
    string first_name;
    string last_name;
    float mark;
};
