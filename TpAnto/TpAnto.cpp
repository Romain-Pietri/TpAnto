#include <iostream>
#include "TP1.hpp"
#include "TP2.hpp"
#include "TP3.hpp"
#include "TP4.hpp"

using namespace std;

int main() {
	int tmp1 = 1;
	do {
		cout << "Bonjour, Quel Tp voulez-vous tester ?" << endl;
		cout << "1. TP1" << endl;
		cout << "2. TP2" << endl;
		cout << "3. TP3" << endl;
		cout << "4. TP4" << endl;

		int tmp = 0;
		cin >> tmp;
		switch (tmp) {
		case 1:
			cout << "TP1" << endl;
			main1();
			break;
		case 2:
			cout << "TP2" << endl;
			main2();
			break;
		case 3:
			cout << "TP3" << endl;
			main3();
			break;
		case 4:
			cout << "TP4" << endl;
			main4();
			break;
		default:
			cout << "Invalid input" << endl;
			break;
		}
		cout << "Fin d'execution de votre programme voulez vous executer un nouveau programme ?"<<endl;
		cout << "1. Oui"<<endl;
		cout << "2. Non"<<endl;
		cin >> tmp1;
		if (tmp1 != 1) {
			cout << "Merci au revoir ! " << endl;
		}

	} while (tmp1 == 1);

}