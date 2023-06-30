#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

enum class TypeOfPet
{
	RACOON,
	GOOSE
};
class Tam
{
private:
	std::string NameOfTam;
	TypeOfPet TypeOfTam;
	sf::Texture TextureTam;
	sf::Sprite SpriteTam;
	sf::Texture TextureBath;
	sf::Sprite BathTam;
public:
	Tam(std::string name, int NumberOfType) : NameOfTam(name)
	{
		if (NumberOfType == 1)
		{
			TypeOfTam = TypeOfPet::RACOON;
			TextureTam.loadFromFile("content/Racoon.png");
		}
		else if (NumberOfType == 2)
		{
			TypeOfTam = TypeOfPet::GOOSE;
			TextureTam.loadFromFile("content/Goose.png");
		}
		SpriteTam.setTexture(TextureTam);
		SpriteTam.setTextureRect(sf::IntRect(0, 0, 256, 350));
		SpriteTam.setPosition(155, 185);
	}
	~Tam() {}

	sf::Sprite TamaSprite() { return SpriteTam;}
	sf::Sprite BathSprite()
	{
		if (TypeOfTam == TypeOfPet::RACOON) 
		{
			TextureBath.loadFromFile("content/RacoonBath.png");
			BathTam.setTexture(TextureBath);
			BathTam.setTextureRect(sf::IntRect(0, 0, 420, 455));
			BathTam.setPosition(96, 163);
			return BathTam;
		}
		if (TypeOfTam == TypeOfPet::GOOSE)
		{
			TextureBath.loadFromFile("content/GooseBath.png");
			BathTam.setTexture(TextureBath);
			BathTam.setTextureRect(sf::IntRect(0, 0, 420, 455));
			BathTam.setPosition(96, 163);
			return BathTam;
		}
	}
};