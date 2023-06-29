#include "Game.h"

Game::Game(){
	font.loadFromFile("ArialRegular.ttf");// ���������� ����� ��� ��������� ���������
	Init();
}

void Game::Init(){
	for (int i = 0; i < ASize - 1; i++) { // ��������� ������ ������
		elements[i] = i + 1;
		empty_index = ASize - 1;// ������ ������ ������ � ������ ������ �������
		elements[empty_index] = 0;	// ������ ������ ����� �������� = 0
		solved = true;
	}
}

bool Game::Check(){
	for (unsigned int i = 0; i < ASize; i++){ // �������� ����������� �����������
		if (elements[i] > 0 && elements[i] != i + 1) return false;
	}
	return true;
}

void Game::Move(Direction direction)
{
	int col = empty_index % size;// ��������� ������ � ������� ������ ������
	int row = empty_index / size;

	int move_index = -1;// �������� �� ����������� ����������� � ���������� ������� ������������ ������
	if (direction == Direction::Left && col < (size - 1)) move_index = empty_index + 1;
	if (direction == Direction::Right && col > 0) move_index = empty_index - 1;
	if (direction == Direction::Up && row < (size - 1)) move_index = empty_index + size;
	if (direction == Direction::Down && row > 0) move_index = empty_index - size;

	if (empty_index >= 0 && move_index >= 0){ // ����������� ������ �� ����� ������
		int tmp = elements[empty_index];
		elements[empty_index] = elements[move_index];
		elements[move_index] = tmp;
		empty_index = move_index;
	}
	solved = Check();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();
	sf::Color color = sf::Color(46, 139, 87);

	sf::RectangleShape shape(sf::Vector2f(FSize, FSize)); // ������ ����� �������� ����
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color(255, 248, 220));
	target.draw(shape, states);

	shape.setSize(sf::Vector2f(CSize - 2, CSize - 2)); // �������������� ����� ��� ��������� ���� ������
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color(255, 248, 220));

	sf::Text text("", font, 52); // �������������� ��������� ��������� ��� ��������� ������� ������

	for (unsigned int i = 0; i < ASize; i++){
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		if (solved){
			shape.setOutlineColor(sf::Color(46, 139, 87)); // �������� ����������� �������� ������ ������
			text.setFillColor(sf::Color(46, 139, 87));
		}
		else if (elements[i] == i + 1){
			text.setFillColor(sf::Color(139, 69, 19)); // ������ ������ �� ����� ������ �������� ������
		}

		if (elements[i] > 0){ // ������ ��� ������, ����� ������
			sf::Vector2f position(i % size * CSize + 10.f, i / size * CSize + 10.f);// ���������� ������� ������ ��� ���������
			shape.setPosition(position);
			text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f); 
			target.draw(shape, states);
			target.draw(text, states);
		}
	}
}