#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "TP3.hpp"
using namespace std;

//remplir la map
void init_map(map<string, string>& map)
{
	//lit le fichier acro.txt
	ifstream file("acro.txt");
	//format du fichier : key value (value peut contenir des espaces)
	if (file.is_open())
	{
		string key, value;
		while (file >> key)
		{
			getline(file, value);
			map[key] = value;
		}
		file.close();
	}
	else
	{
		cout << "Error opening file" << endl;
	}

}


int main3() {
	map<string, string> acro;
	init_map(acro);
	//afficher la map
	for (const auto& pair : acro)
	{
		cout << pair.first << " : " << pair.second << endl;
	}
	string entree;
	do {
		cout << "Entrez une acronyme (ou 'fin' pour quitter) : ";
		cin >> entree;
		if (entree != "fin")
		{
			//chercher l'acronyme dans la map
			auto it = acro.find(entree);
			if (it != acro.end())
			{
				cout << it->second << endl;
			}
			else
			{
				cout << "Inconnu" << endl;
			}
		}
	} while (entree != "fin");

	
	return 0;


}
