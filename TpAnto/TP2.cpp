#include "TP2.hpp"

using namespace std;


template <typename T>
void lire_fractions(const string& file_name, vector<Fraction<T>>& fractions)
{
	ifstream file(file_name);
	if (file.is_open())
	{
		T num, den;
		while (file >> num >> den)
		{
			Fraction<T> fraction(num, den);
			fractions.push_back(fraction);
		}
		file.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}
}

template <typename T>
void print_somme_fractions(const vector<Fraction<T>>& fractions)
{
	Fraction<T> somme;
	for (const auto& fraction : fractions)
	{
		somme = somme + fraction;
	}
	cout << "Somme des fractions : " << somme << endl;
}

template <typename T>
void print_only_positive_fractions(const vector<Fraction<T>>& fractions)
{
	for (const auto& fraction : fractions)
	{
		if (fraction.get_den()>0 && fraction.get_num()>0)
		{
			cout << fraction << " | ";
		}
	}
	cout << endl;
}
template <typename T>
void print_max_fraction(const vector<Fraction<T>>& fractions)
{
	Fraction<T> max_fraction = fractions[0];
	for (const auto& fraction : fractions)
	{
		if (max_fraction < fraction)
		{
			max_fraction = fraction;
		}
	}
	cout << "Max fraction : " << max_fraction << endl;
}

template <typename T>
void print_min_fraction(const vector<Fraction<T>>& fractions)
{
	Fraction<T> min_fraction = fractions[0];
	for (const auto& fraction : fractions)
	{
		if (fraction < min_fraction)
		{
			min_fraction = fraction;
		}
	}
	cout << "Min fraction : " << min_fraction << endl;
}

template <typename T>
void remove_negative_fractions(vector<Fraction<T>>& fractions)
{
	for (auto it = fractions.begin(); it != fractions.end();)
	{
		if (it->get_den() < 0 || it->get_num() < 0)
		{
			it = fractions.erase(it);
		}
		else
		{
			++it;
		}
	}
}

template <typename T>
void remove_reapeted_values(vector<Fraction<T>>& fractions)
{
	for (auto it = fractions.begin(); it != fractions.end();)
	{
		if (find(fractions.begin(), fractions.end(), *it) != it)
		{
			it = fractions.erase(it);
		}
		else
		{
			++it;
		}
	}
}	

template <typename T>
void print_first_last_negative_fractions(const vector<Fraction<T>>& fractions)
{
	cout << "First negative fraction : ";
	int find_first = 0;
	for (const auto& fraction : fractions)
	{
		if (fraction.get_den() < 0 || fraction.get_num() < 0)
		{
			cout << fraction << " | ";
			find_first = 1;
			break;
			
		}
	}
	if (find_first == 0)
	{
		cout << "No negative fractions" << endl;
	}
	//parcours inversé
	int find_last = 0;
	cout << "Last negative fraction : ";
	for (auto it = fractions.rbegin(); it != fractions.rend(); ++it)
	{
		if (it->get_den() < 0 || it->get_num() < 0)
		{
			cout << *it << " | ";
			find_last = 1;
			break;
			
		}
	}
	if (find_last == 0)
	{
		cout << "No negative fractions" << endl;
	}

}

int main2()
{
	cout << "TP2" << endl;
	vector<Fraction<int>> fractions;
	lire_fractions("fractions.txt", fractions);
	print_somme_fractions<int>(fractions);
	print_only_positive_fractions(fractions);
	print_max_fraction(fractions);
	print_min_fraction(fractions);
	//remove_negative_fractions(fractions);
	remove_reapeted_values(fractions);
	print_first_last_negative_fractions(fractions);
	return 0;
}