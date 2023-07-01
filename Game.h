#pragma once
#include <SFML/Graphics.hpp>

const int size = 4;	// Размер игрового поля в плашках
const int ASize = size * size;	// Размер массива
const int FSize = 750;// Размер игрового поля в пикселях
const int CSize = 162; // Размер одной плашки

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 }; // определяет направление перемещения плашки

class Game : public sf::Drawable, public sf::Transformable {
protected:
	int elements[ASize];
	int empty_index;
	bool solved; //флаг того, что игра пройдена
	sf::Font font;
public:
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};