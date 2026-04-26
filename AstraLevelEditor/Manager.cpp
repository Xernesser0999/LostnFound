#include "Manager.h"

Manager::Manager() {
	switch (random(1, 8)) {
	case 1: DestinationName = "Destinataire : Youssef"; DnameID = 1; break;
	case 2: DestinationName = "Destinataire : Jaouen";  DnameID = 2; break;
	case 3: DestinationName = "Destinataire : Etienne"; DnameID = 3; break;
	case 4: DestinationName = "Destinataire : Alex";    DnameID = 4; break;
	case 5: DestinationName = "Destinataire : Line";    DnameID = 5; break;
	case 6: DestinationName = "Destinataire : Chloe";   DnameID = 6; break;
	case 7: DestinationName = "Destinataire : Vincent"; DnameID = 7; break;
	case 8: DestinationName = "Destinataire : Maiwen";  DnameID = 8; break;
	}

	switch (random(1, 5)) {
	case 1: Contenu = "Contenu : Switch"; CiD = 1; break;
	case 2: Contenu = "Contenu : Casque"; CiD = 2; break;
	case 3: Contenu = "Contenu : Peluche metamorph"; CiD = 3; break;
	case 4: Contenu = "Contenu : PC"; CiD = 4; break;
	case 5: Contenu = "Contenu : Vide?"; CiD = 5; break;
	}

	jour = random(1, 31);
	mois = random(1, 11);

	SendId = random(1, 8);
	if (SendId == DnameID) {
		SendId += 1;
	}

	DateJaouen = {random(1, 31), random(2, 12)};
	DateAlex = { random(1, 31), random(2, 12) };
	DateEtienne = { random(1, 31), random(2, 12) };
	DateVincent = { random(1, 31), random(2, 12) };
	DateChloe = { random(1, 31), random(2, 12) };
	DateLine = { random(1, 31), random(2, 12) };
	DateMaiwen = { random(1, 31), random(2, 12) };
	DateYoussef = { random(1, 31), random(2, 12) };

	switch (SendId) {
	case 1:
		DateYoussef.jour = jour - 14;
		DateYoussef.mois = mois;

		if (DateYoussef.jour < 1) {
			DateYoussef.jour += 31;
			DateYoussef.mois -= 1;
		}
		break;
	case 2:
		DateJaouen.jour = jour - 14;
		DateJaouen.mois = mois;

		if (DateJaouen.jour < 1) {
			DateJaouen.jour += 31;
			DateJaouen.mois -= 1;
		}
		break;
	case 3:
		DateEtienne.jour = jour - 14;
		DateEtienne.mois = mois;

		if (DateEtienne.jour < 1) {
			DateEtienne.jour += 31;
			DateEtienne.mois -= 1;
		}
		break;
	case 4:
		DateAlex.jour = jour - 14;
		DateAlex.mois = mois;

		if (DateAlex.jour < 1) {
			DateAlex.jour += 31;
			DateAlex.mois -= 1;
		}
		break;
	case 5:
		DateLine.jour = jour - 14;
		DateLine.mois = mois;

		if (DateLine.jour < 1) {
			DateLine.jour += 31;
			DateLine.mois -= 1;
		}
		break;
	case 6:
		DateChloe.jour = jour - 14;
		DateChloe.mois = mois;

		if (DateChloe.jour < 1) {
			DateChloe.jour += 31;
			DateChloe.mois -= 1;
		}
		break;
	case 7:
		DateVincent.jour = jour - 14;
		DateVincent.mois = mois;

		if (DateVincent.jour < 1) {
			DateVincent.jour += 31;
			DateVincent.mois -= 1;
		}
		break;
	case 8:
		DateMaiwen.jour = jour - 14;
		DateMaiwen.mois = mois;

		if (DateMaiwen.jour < 1) {
			DateMaiwen.jour += 31;
			DateMaiwen.mois -= 1;
		}
		break;
	}
}

Manager::~Manager() {

}

int Manager::random(int Minimum, int Maximum) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(Minimum, Maximum);
	return dist(gen);
}