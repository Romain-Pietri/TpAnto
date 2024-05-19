#include <iostream>
#include "Fraction.hpp"

using namespace std;

template <typename T>
Fraction<T>::Fraction() : num_(0), den_(1) {}

template <typename T>
Fraction<T>::Fraction(const T& num, const T& den)
{
    if (den > 1.e-15)
    {
        this->num_ = num;
        this->den_ = den;
    }
    else {
        cout << "Error denominator" << endl;
    }
}

template <typename T>
Fraction<T>::Fraction(const Fraction<T>& other) : num_(other.num_), den_(other.den_) {}

template <typename T>
Fraction<T> Fraction<T>::operator+(const Fraction<T>& fraction)
{
    return Fraction<T>(num_ * fraction.get_den() + fraction.get_num() * den_, den_ * fraction.get_den());
}

template <typename T>
bool Fraction<T>::operator==(const Fraction<T>& fraction) const
{
    return (this->num_ * fraction.get_den() == this->den_ * fraction.get_num());
}

template <typename T>
void Fraction<T>::set_num(const T& num)
{
    this->num_ = num;
}

template <typename T>
void Fraction<T>::set_den(const T& den)
{
    if (den > 1.e-15)
    {
        this->den_ = den;
    }
    else {
        cout << "Error denominator" << endl;
    }
}

template <typename T>
T Fraction<T>::get_num() const
{
    return this->num_;
}

template <typename T>
T Fraction<T>::get_den() const
{
    return this->den_;
}

template <typename T>
bool Fraction<T>::operator<(const Fraction<T>& fraction) const
{
    return (this->num_ * fraction.get_den() < this->den_ * fraction.get_num());
}

template <typename T>
ostream& operator<<(ostream& os, const Fraction<T>& fraction)
{
    os << "numerator = " << fraction.get_num() << " denumerator = " << fraction.get_den();
    return os;
}

template <typename T>
istream& operator>>(istream& os, Fraction<T>& fraction)
{
    T num, den;
    os >> num >> den;
    fraction.set_num(num);
    fraction.set_den(den);
    return os;
}

template <typename T>
Fraction<T> Fraction<T>::operator+(const T& number)
{
    cout << "operator+" << endl;
    return Fraction<T>(num_ + number * num_, den_);
}

template <typename T>
Fraction<T>::operator T()
{
    cout << "operator T" << endl;
    return static_cast<T>(num_ / den_);
}

template class Fraction<int>;
template ostream& operator<<(ostream& os, const Fraction<int>& fraction);
template istream& operator>>(istream& os, Fraction<int>& fraction);