#include <iostream>
#include "TP4.hpp"
using namespace std;



int decalage(const int& lettre, const int& nb_decal) {
		return (lettre - 'A' + nb_decal) % 26 + 'A';
}

int decalage_inverse(const int& lettre, const int& nb_decal) {
	return (lettre - 'A' - nb_decal + 26) % 26 + 'A';
}

void verify_letter(string &s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' || s[i] <='z') {
			s[i]=toupper(s[i]);
		}
		if (s[i] < 'A' || s[i] > 'Z') {
			cout << "Error: " << s[i] << " is not a letter" << endl;
			exit(1);
		}
	}
}

void cesar(string& s, const int& nb_decal) {
	verify_letter(s);
	for (int i = 0; i < s.size(); i++) {
		s[i] = decalage(s[i], nb_decal);
	}
}

void cesar_inverse(string& s, const int& nb_decal) {
	verify_letter(s);
	for (int i = 0; i < s.size(); i++) {
		s[i] = decalage_inverse(s[i], nb_decal);
	}
}
void verify_decal(const int& nb_decal) {
	if (nb_decal < 0 || nb_decal > 25) {
		cout << "Error: " << nb_decal << " is not a valid decalage" << endl;
		exit(1);
	}
}

int main4() {
	string s;
	int nb_decal;
	cout << "Entrez une chaine de caractere : ";
	cin >> s;
	cout << "Entrez un nombre de decalage : ";
	
	cin >> nb_decal;
	verify_decal(nb_decal);
	cesar(s, nb_decal);
	cout << "Chaine de caractere cryptee : " << s << endl;
	cesar_inverse(s, nb_decal);
	cout << "Chaine de caractere decryptee : " << s << endl;
	return 0;
}

