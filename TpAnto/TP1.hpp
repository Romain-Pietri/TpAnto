#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
class Polynome
{
private:
	std::vector<float> polynome_;
public:
	Polynome() {};
	int max_degre();
	float get_val(const float& val);
	void ajouter_un_monome(const int& degre, const float& coeff);
	float operator()(const float& val);
	Polynome operator+(const Polynome& other);
	Polynome operator*(const Polynome& other);
	void ecrire(std::ostream& os);
	void lire(std::istream& os);
};

int main1();

