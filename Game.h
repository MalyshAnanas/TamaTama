#pragma once
#include <SFML/Graphics.hpp>

const int size = 4;	// ������ �������� ���� � �������
const int ASize = size * size;	// ������ �������
const int FSize = 750;// ������ �������� ���� � ��������
const int CSize = 162; // ������ ����� ������

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 }; // ���������� ����������� ����������� ������

class Game : public sf::Drawable, public sf::Transformable {
protected:
	int elements[ASize];
	int empty_index;
	bool solved; //���� ����, ��� ���� ��������
	sf::Font font;
public:
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};