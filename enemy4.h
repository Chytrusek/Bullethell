#pragma once
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "enemy.h"

class enemy4 : public enemy
{
  float ktore_dzialo;

  void strzal(std::vector<bullets> &pociski)
  {
    sf::Time czas = zegar_strzalu.getElapsedTime();
    if (czas.asMilliseconds() > 30)
    {
      bullets pocisk;
      switch((int)trunc(ktore_dzialo))
      {
        case 1:
          pocisk.polozenie.x = wrog.at(0).getPosition().x+wymiary.x/3.f;
          pocisk.polozenie.y = wrog.at(0).getPosition().y-wymiary.y/2;
          pocisk.vector.x = 2 * okno.skalaX;
          pocisk.vector.y = -4.7 * okno.skalaY;
          break;
        case 3:
          pocisk.polozenie.x = wrog.at(0).getPosition().x;
		  pocisk.polozenie.y = wrog.at(0).getPosition().y-wymiary.y/2;
          pocisk.vector.x = 0 * okno.skalaX;
          pocisk.vector.y = -4.7f * okno.skalaY;
          break;
        case 6:
          pocisk.polozenie.x = wrog.at(0).getPosition().x - wymiary.x / 3.f;
		  pocisk.polozenie.y = wrog.at(0).getPosition().y-wymiary.y/2;
          pocisk.vector.x = -2 * okno.skalaX;
          pocisk.vector.y = -4.7f * okno.skalaY;
          break;
        case 4:
          pocisk.polozenie.x = wrog.at(0).getPosition().x;
		  pocisk.polozenie.y = wrog.at(0).getPosition().y+wymiary.y/2;
          pocisk.vector.x = 0 * okno.skalaX;
          pocisk.vector.y = 4.7f * okno.skalaY;
          break;
        case 2:
          pocisk.polozenie.x = wrog.at(0).getPosition().x + wymiary.x / 2.4;
		  pocisk.polozenie.y = wrog.at(0).getPosition().y + wymiary.y / 18;
          pocisk.vector.x = 5.13f * okno.skalaX;
          pocisk.vector.y = 1 * okno.skalaY;

          break;
        case 5:
          pocisk.polozenie.x = wrog.at(0).getPosition().x - wymiary.x / 2.4;
		  pocisk.polozenie.y = wrog.at(0).getPosition().y + wymiary.y / 18;
          pocisk.vector.x = -5.13f * okno.skalaX;
          pocisk.vector.y = 1 * okno.skalaY;
          break;

      }
      ktore_dzialo+=0.1f;
      if(ktore_dzialo>7)
        ktore_dzialo=1;
      pociski.push_back(pocisk);
      zegar_strzalu.restart();

    }
  }
  public:
  enemy4(std::vector<sf::Texture*> enemytexture)
  {
    nr_typu_wroga = 3;
	for (int i = 0;i<6;i++)
	{
		sf::Sprite klatka_wroga;
		klatka_wroga.setOrigin(127.5, 127.5);
		klatka_wroga.setScale(0.3f, 0.3f);

		klatka_wroga.setPosition(okno.szerokosc_okna / 2, okno.wysokosc_okna / 8);
		klatka_wroga.setTexture(*enemytexture[4]);
		klatka_wroga.setTextureRect(sf::IntRect(i * 255, 0, 255, 255));
		wrog.push_back(klatka_wroga);

	}
	for (sf::Sprite &przeciwnik : wrog)
	{
		przeciwnik.setScale(0.3f*okno.skalaX, 0.3f*okno.skalaY);
		przeciwnik.setOrigin(255 / 2, 255 / 2);
	}
	wymiary.x = 255 * 0.3f*okno.skalaX;
	wymiary.y = 255 * 0.3f*okno.skalaY;
	int losowa_pozycja_x = std::rand() % (int)(okno.szerokosc_okna - (wymiary.x / 2)) + (int)wymiary.x / 2;
	for (sf::Sprite &przeciwnik : wrog)
		przeciwnik.setPosition(losowa_pozycja_x, 0 - wymiary.y);


    HP_bar.setSize(sf::Vector2f(wymiary.x, 3));
    HP_bar.setOrigin(sf::Vector2f(wymiary.x / 2, 1.5));
    HP_bar.setFillColor(sf::Color::Red);
    HP_bar_tlo.setSize(sf::Vector2f(wymiary.x + 2, 5));
    HP_bar_tlo.setOrigin(sf::Vector2f(wymiary.x / 2 + 1, 2.5));
    HP_bar_tlo.setFillColor(sf::Color::White);

    ktore_dzialo=1;

    HP_max = 12;
    HP = HP_max;
  }
};
