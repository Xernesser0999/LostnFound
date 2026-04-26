#include "Fiche.h"
#include "Manager.h"

Fiche::Fiche() {
	pos = { 300, 100 };
	size = {210*2, 300*2};

	rect.setPosition(pos);
	rect.setSize(size);
	rect.setFillColor(sf::Color::White);

	font.openFromFile("font/Pixellettersfull-BnJ5.ttf");

	name = new sf::Text(font, "Destinataire : ", 30);
	name->setFillColor(sf::Color::Black);
	name->setPosition({ pos.x+10, pos.y+10 });

	ContenuName = new sf::Text(font, "Destinataire : ", 30);
	ContenuName->setFillColor(sf::Color::Black);
	ContenuName->setPosition({ pos.x + 10, pos.y + 35 });

	TXTville = new sf::Text(font, "Ville d'envois : ", 30);
	TXTville->setFillColor(sf::Color::Black);
	TXTville->setPosition({ pos.x + 10, pos.y + 60 });

	TXTdate = new sf::Text(font, "Date d'envois ", 30);
	TXTdate->setFillColor(sf::Color::Black);
	TXTdate->setPosition({ pos.x + 10, pos.y + 85 });

	TXRpoid = new sf::Text(font, "Poid ", 30);
	TXRpoid->setFillColor(sf::Color::Black);
	TXRpoid->setPosition({ pos.x + 10, pos.y + 110 });
}

Fiche::~Fiche() {
	delete name;
	delete ContenuName;
	delete TXTville;
	delete TXTdate;
	delete TXRpoid;
	
	name = nullptr;
	ContenuName = nullptr;
	TXTville = nullptr;
	TXTdate = nullptr;
	TXRpoid = nullptr;
}

void Fiche::GetInformation(Manager& manage) {
	DisplayedName = manage.DestinationName;
	DisplayedContenu = manage.Contenu;

	name->setString(DisplayedName);
	ContenuName->setString(DisplayedContenu);

	TXTdate->setString("Date de reception: " + std::to_string(manage.jour) +"/"+ std::to_string(manage.mois));
}

void Fiche::Update(float dt) {

}

void Fiche::Render(sf::RenderWindow& window) {
	window.draw(rect);
	window.draw(*name);
	window.draw(*ContenuName);
	window.draw(*TXTville);
	window.draw(*TXTdate);
	window.draw(*TXRpoid);
}
