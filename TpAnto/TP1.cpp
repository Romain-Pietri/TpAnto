#include "TP1.hpp"



void Polynome::ajouter_un_monome(const int& degree, const float& coeff) {
	while (degree >= polynome_.size()) {
		polynome_.push_back(0);
	}
	polynome_[degree] += coeff;
}

int Polynome::max_degre() {
	return polynome_.size() - 1;
}
float Polynome::operator()(const float& val) {
	double res = 0;
	for (int i = 0; i < polynome_.size(); i++) {
		res += polynome_[i] * pow(val, i);
	}
	return res;
}

Polynome Polynome::operator+(const Polynome& other) {
	Polynome res;
	float tmp;
	for (int i = 0; i < std::max(polynome_.size(), other.polynome_.size()); i++) {
		tmp = 0;
		if (i < polynome_.size()) {
			tmp += polynome_[i];
		}
		if (i < other.polynome_.size()) {
			tmp += other.polynome_[i];
		}
		res.ajouter_un_monome(i, tmp);
	}
	return res;
}

Polynome Polynome::operator*(const Polynome& other) {
	Polynome res;
	for (int i = 0; i < polynome_.size(); i++) {
		for (int j = 0; j < other.polynome_.size(); j++) {
			res.ajouter_un_monome(i + j, polynome_[i] * other.polynome_[j]);
		}
	}
	return res;
}

void Polynome::ecrire(std::ostream& os) {
	int first = 1;
	for (int i = 0; i < polynome_.size(); i++) {
		if (polynome_[polynome_.size() - i - 1] != 0) {// si le coef est non nul 
			if (polynome_[polynome_.size() - i - 1] > 0 and first != 1) os << "+"; // si le coef est positif ( négatif sera mis d'office)
			// on affiche le coef
			os << polynome_[polynome_.size() - i - 1];
			// on affiche le degre
			switch (polynome_.size() - i - 1) {
			case 0:
				break;
			case 1:
				os << "X";
				break
					;
			default:
				os << "X^" << polynome_.size() - i - 1;
				break;
			}
			first = 0;
		}
	}
	os << std::endl;
}

void Polynome::lire(std::istream& is) {
	float tmp;
	while (is >> tmp) {
		ajouter_un_monome(polynome_.size(), tmp);
	}

}

int main1()
{
	Polynome poly1, poly2;
	poly1.ajouter_un_monome(2, 5);
	poly1.ajouter_un_monome(1, 4);
	std::cout << "max degre poly1 :" << poly1.max_degre() << std::endl;
	std::cout << "poly1 : ";
	poly1.ecrire(std::cout);
	poly1.ajouter_un_monome(1, 2);
	std::cout << "poly1 après \"ajouter_un_monome(1, 2)\" : ";
	poly1.ecrire(std::cout);
	std::cout << "poly1(2) :" << poly1(2) << std::endl;
	poly2.ajouter_un_monome(5, 5);
	poly2.ajouter_un_monome(0, 4);
	std::cout << "max degre poly2 :" << poly2.max_degre() << std::endl;
	std::cout << "poly2 : ";
	poly2.ecrire(std::cout);
	auto poly3 = poly1 + poly2;
	std::cout << "max degre (poly1 + poly2) :" << poly3.max_degre() <<
		std::endl;
	std::cout << "poly3 (poly1 + poly2) : ";
	poly3.ecrire(std::cout);
	auto poly4 = poly1 * poly2;
	std::cout << "max degre (poly1 * poly2) :" << poly4.max_degre() <<
		std::endl;
	std::cout << "poly4 (poly1 * poly2) : ";
	poly4.ecrire(std::cout);
	std::ifstream file("test.txt");
	if (file.is_open())
	{
		std::cout << "file opened" << std::endl;
		Polynome poly5;
		poly5.lire(file);
		std::cout << "poly5 : ";
		poly5.ecrire(std::cout);
	}
	return 0;
}
