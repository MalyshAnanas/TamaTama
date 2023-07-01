#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Food
{
private:
	sf::Texture TextureFood;
	sf::Sprite SpriteFood;
	float dX = 0;//корректировка нажатия по х
	float dY = 0;//по у
public:
	Food(std::string Adress, int x, int y)
	{
		TextureFood.loadFromFile(Adress);
		SpriteFood.setTexture(TextureFood);
		SpriteFood.setTextureRect(sf::IntRect(0, 0, 70, 53));
		SpriteFood.setPosition(x, y);
	}
	~Food() {}
	sf::Sprite FoodSprite() { return SpriteFood; }
	void ChangePosition(int X, int Y)
	{
		SpriteFood.setPosition(X, Y);
	}
	void CalculatedX(int Posx)
	{
		dX = Posx - SpriteFood.getPosition().x;
	}
	float ReturndX()
	{
		return dX; }
	void CalculatedY(int Posy)
	{
		dX = Posy - SpriteFood.getPosition().y;
	}
	float ReturndY()
	{
		return dY;
	}

};