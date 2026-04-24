#pragma once
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

struct Date {
	int jour;
	int mois;
};

class Manager
{
public:
	Manager();
	~Manager();

	int random(int Minimum, int Maximum);

public:
	// GIVEN INFO
	//Nom
	std::string DestinationName;
	int DnameID;

	//Contenu
	std::string Contenu;
	int CiD;

	//Poids
	int poids;

	//Date
	int jour;
	int mois;

	//Ville
	std::string Ville;
	int ViD;

	// REPONSE
	int SendId;

	Date DateJaouen;
	Date DateYoussef;
	Date DateEtienne;
	Date DateAlex;
	Date DateLine;
	Date DateMaiwen;
	Date DateVincent;
	Date DateChloe;
};

