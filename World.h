#pragma once

#include <SFML/Graphics.hpp>
#include "Sand.h"
#include "Water.h"
#include "Stone.h"

class World
{
private:
    static const size_t WIDTH = 163; static const size_t HEIGHT = 161;
	std::vector<std::vector<char>> worldGrid;
    char voidElement = 'v';
public:

	const sf::Vector2i SIZEOFGRID;

	sf::Vector2i GetGridSize() { return SIZEOFGRID; }

	std::vector<std::vector<char>>& GetWorldGrid() { return worldGrid; }

	World() : SIZEOFGRID(WIDTH, HEIGHT)	{ worldGrid.resize(WIDTH, std::vector<char>(HEIGHT, voidElement)); }

	void PlaceElement(int x, int y, char element) { worldGrid[x][y] = element; }

	char getVoidElement() const { return voidElement; }

	void ClearWorld() { worldGrid.assign(WIDTH, std::vector<char>(HEIGHT, voidElement)); }

	void Draw(sf::RenderWindow& window)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			for (int j = 0; j < HEIGHT; j++)
			{
				if (worldGrid[i][j] == 's')
				{
					window.draw(CreateSand(i, j));
				}
				else if (worldGrid[i][j] == 'w')
				{
					window.draw(CreateWater(i, j));
				}
				else if (worldGrid[i][j] == 'r')
				{
					window.draw(CreateStone(i, j));
				}
			}
		}
	}

	sf::RectangleShape CreateSand(int x, int y)
	{
		size_t ElementSize = Sand::GetSize();

		sf::Color elementColor = sf::Color::Yellow;
		//int randNum = rand() % 3;
		//switch (randNum)
		//{
		//case 0:
		//	elementColor = sf::Color(139, 69, 19); // Brown
		//	break;
		//case 1:
		//	elementColor = sf::Color(255, 165, 0); // Orange
		//	break;
		//case 2:
		//	elementColor = sf::Color::Yellow;
		//	break;
		//}

		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(ElementSize, ElementSize));
		shape.setFillColor(elementColor);
		shape.setPosition(x * ElementSize, y * ElementSize);
		return shape;
	}

	sf::RectangleShape CreateWater(int x, int y)
	{
		size_t ElementSize = Sand::GetSize();

		sf::Color elementColor;
		int randNum = rand() % 3;
		switch (randNum)
		{
		case 0:
			elementColor = sf::Color(116, 193, 252, 200);
			break;
		case 1:
			elementColor = sf::Color(82, 177, 250, 200);
			break;
		case 2:
			elementColor = sf::Color(157, 211, 252, 200);
			break;
		}

		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(ElementSize, ElementSize));
		shape.setFillColor(elementColor);
		shape.setPosition(x * ElementSize, y * ElementSize);
		return shape;
	}

	sf::RectangleShape CreateStone(int x, int y)
	{
		size_t ElementSize = Stone::GetSize();

		sf::Color elementColor = sf::Color(90, 90, 90); // Gray
		//int randNum = rand() % 3;
		//switch (randNum)
		//{
		//case 0:
		//	elementColor = sf::Color(26, 69, 138); // Dark Blue
		//	break;
		//case 1:
		//	elementColor = sf::Color(87, 147, 242); // Cyan
		//	break;
		//case 2:
		//	elementColor = sf::Color(41, 117, 240); // Blue
		//	break;
		//}

		sf::RectangleShape shape;
		shape.setSize(sf::Vector2f(ElementSize, ElementSize));
		shape.setFillColor(elementColor);
		shape.setPosition(x * ElementSize, y * ElementSize);
		return shape;
	}

};