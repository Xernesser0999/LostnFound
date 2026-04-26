#include "Liste.h"
#include "Manager.h"

Liste::Liste() {
	Pos = { 1920 - 500, 100 };
	Size = { 210 * 2, 300 * 2 };

	rect.setPosition(Pos);
	rect.setSize(Size);
	rect.setFillColor(sf::Color::White);

	font.openFromFile("font/Pixellettersfull-BnJ5.ttf");

	Text = new sf::Text(font, "Destinataire : ", 30);
	Text->setFillColor(sf::Color::Black);
	Text->setPosition({ Pos.x + 10, Pos.y + 5 });

	Text->setString("Dernier Envois :\n\n- Youssef\n- Jaouen\n- Etienne\n- Alex\n- Line\n- Chloe\n- Vincent\n- Maiwen");

	Date = new sf::Text(font, "Destinataire : ", 30);
	Date->setFillColor(sf::Color::Black);
	Date->setPosition({ Pos.x + 125, Pos.y + 5 });

	note = new sf::Text(font, "NOTE : Les colis mettent environ 2 semaine \na arriver", 27);
	note->setFillColor(sf::Color::Black);
	note->setPosition({ Pos.x + 10, Pos.y + 525 });
}

Liste::~Liste() {
	delete Text;
	delete Date;
	delete note;
	Text = nullptr;
	Date = nullptr;
	note = nullptr;
}

void Liste::GetInfo(Manager& manage) {
	Date->setString(
		"\n \n " +
		std::to_string(manage.DateYoussef.jour) + "/" + std::to_string(manage.DateYoussef.mois) + "\n " +
		std::to_string(manage.DateJaouen.jour) + "/" + std::to_string(manage.DateJaouen.mois) + "\n " +
		std::to_string(manage.DateEtienne.jour) + "/" + std::to_string(manage.DateEtienne.mois) + "\n " +
		std::to_string(manage.DateAlex.jour) + "/" + std::to_string(manage.DateAlex.mois) + "\n " +
		std::to_string(manage.DateLine.jour) + "/" + std::to_string(manage.DateLine.mois) + "\n " +
		std::to_string(manage.DateChloe.jour) + "/" + std::to_string(manage.DateChloe.mois) + "\n " +
		std::to_string(manage.DateVincent.jour) + "/" + std::to_string(manage.DateVincent.mois) + "\n " +
		std::to_string(manage.DateMaiwen.jour) + "/" + std::to_string(manage.DateMaiwen.mois)
	);
}

void Liste::render(sf::RenderWindow& window) {
	window.draw(rect);
	window.draw(*Text);
	window.draw(*Date);
	window.draw(*note);
}