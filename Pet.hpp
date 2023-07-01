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
	int AnimateCount = 0;
	int AnimateCount1 = 0;
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
			BathTam.setTextureRect(sf::IntRect(420, 0, 420, 455));
			BathTam.setPosition(50, 83);
			return BathTam;
		}
		if (TypeOfTam == TypeOfPet::GOOSE)
		{
			TextureBath.loadFromFile("content/GooseBath.png");
			BathTam.setTexture(TextureBath);
			BathTam.setTextureRect(sf::IntRect(420, 0, 420, 455));
			BathTam.setPosition(50, 83);
			return BathTam;
		}
	}
	void ChangeTamaSprite(int Code = 0)
	{
		if (Code == 0)
		{
			if (TypeOfTam == TypeOfPet::RACOON)
			{
				if (AnimateCount1 < 5)
				{
					if (AnimateCount < 4)
					{
						SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 0, 256, 350));
						AnimateCount += 1;
					}
					else
					{
						AnimateCount = 0;
						SpriteTam.setTextureRect(sf::IntRect(0, 0, 256, 350));
					}
					if (AnimateCount == 0)
					{
						AnimateCount1++;
					}
				}
				else
				{
					if (AnimateCount < 5)
					{
						SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 350, 256, 350));
						AnimateCount += 1;
					}
					if (AnimateCount >= 5 && AnimateCount < 10)
					{
						SpriteTam.setTextureRect(sf::IntRect((256 * (9 - AnimateCount)), 350, 256, 350));
						AnimateCount += 1;
					}
					if (AnimateCount == 9)
					{
						AnimateCount = 0;
						AnimateCount1 = 0;
					}
				}
			}

			if (TypeOfTam == TypeOfPet::GOOSE)
			{
				if (AnimateCount1 < 5)
				{
					if (AnimateCount < 2)
					{
						SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 0, 256, 350));
						AnimateCount += 1;
					}
					else
					{
						AnimateCount = 0;
						SpriteTam.setTextureRect(sf::IntRect(0, 0, 256, 350));
					}
					if (AnimateCount == 0)
					{
						AnimateCount1++;
					}
				}
				else
				{
					if (AnimateCount < 6)
					{
						SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 350, 256, 350));
						AnimateCount += 1;
					}
					if (AnimateCount >= 6 && AnimateCount < 11)
					{
						SpriteTam.setTextureRect(sf::IntRect((256 * (11 - AnimateCount)), 350, 256, 350));
						AnimateCount += 1;
					}
					if (AnimateCount == 11)
					{
						AnimateCount = 0;
						AnimateCount1 = 0;
					}
				}
			}

		}

		if (Code == 1)
		{
			if (TypeOfTam == TypeOfPet::RACOON)
			{

				if (AnimateCount < 8)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 700, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount >= 8 && AnimateCount < 11)
				{
					SpriteTam.setTextureRect(sf::IntRect((256 * (7 - (AnimateCount % 8))), 700, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount == 11)
				{
					AnimateCount = 8;
				}
			}
			if (TypeOfTam == TypeOfPet::GOOSE)
			{

				if (AnimateCount < 5)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 700, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount >= 5 && AnimateCount < 7)
				{
					SpriteTam.setTextureRect(sf::IntRect((256 * (4 - (AnimateCount % 5))), 700, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount == 7)
				{
					AnimateCount = 5;
				}
			}
		}
		if (Code == 2)
		{
			if (TypeOfTam == TypeOfPet::RACOON)
			{

				if (AnimateCount < 4)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 1050, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount == 4)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * 3, 1050, 256, 350));
				}
			}
			if (TypeOfTam == TypeOfPet::GOOSE)
			{
				if (AnimateCount < 3)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 1050, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount == 3)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * 2, 1050, 256, 350));
				}
			}
		}

		if (Code == 3)
		{
			if (TypeOfTam == TypeOfPet::RACOON)
			{

				if (AnimateCount < 7)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 1400, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount == 7)
				{
					SpriteTam.setTextureRect(sf::IntRect(0, 1400, 256, 350));
					AnimateCount == 0;
				}
			}
			if (TypeOfTam == TypeOfPet::GOOSE)
			{
				if (AnimateCount < 8)
				{
					SpriteTam.setTextureRect(sf::IntRect(256 * AnimateCount, 1400, 256, 350));
					AnimateCount += 1;
				}
				if (AnimateCount == 8)
				{
					SpriteTam.setTextureRect(sf::IntRect(0, 1400, 256, 350));
					AnimateCount == 0;
				}
			}
		}
	}
};