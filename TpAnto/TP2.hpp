#include "Fraction.hpp"
#include <fstream>
#include <vector>
#include <iostream>



template <typename T>
void lire_fractions(const string& file_name, vector<Fraction<T>>& fractions);

template <typename T>
void print_somme_fractions(const vector<Fraction<T>>& fractions);

template <typename T>
void print_only_positive_fractions(const vector<Fraction<T>>& fractions);

template <typename T>
void print_max_fraction(const vector<Fraction<T>>& fractions);

template <typename T>
void print_min_fraction(const vector<Fraction<T>>& fractions);

template <typename T>
void remove_negative_fractions(vector<Fraction<T>>& fractions);

template <typename T>
void print_first_last_negative_fractions(const vector<Fraction<T>>& fractions);

int main2();