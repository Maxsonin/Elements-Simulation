#include "../Headers/World.h"

void World::Draw(sf::RenderWindow & window)
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if (worldGrid[x][y] == 's')	window.draw(CreateSand(x, y));
			else if (worldGrid[x][y] == 'w') window.draw(CreateWater(x, y));
			else if (worldGrid[x][y] == 'r') window.draw(CreateStone(x, y));
			else if (worldGrid[x][y] == 'l') window.draw(CreateLava(x, y));
		}
	}
}

sf::RectangleShape World::CreateSand(int x, int y)
{
	size_t ElementSize = World::GetSizeOfElement();

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(ElementSize, ElementSize));
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(x * ElementSize, y * ElementSize);
	return shape;
}

sf::RectangleShape World::CreateWater(int x, int y)
{
	size_t ElementSize = World::GetSizeOfElement();

	// To make the Water simulation more realistic,
	// we will use constant color updating
	sf::Color elementColor;
	int randNum = rand() % 3;
	switch (randNum)
	{
	case 0:
		elementColor = sf::Color(116, 193, 252);
		break;
	case 1:
		elementColor = sf::Color(82, 177, 250);
		break;
	case 2:
		elementColor = sf::Color(157, 211, 252);
		break;
	}

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(ElementSize, ElementSize));
	shape.setFillColor(elementColor);
	shape.setPosition(x * ElementSize, y * ElementSize);
	return shape;
}

sf::RectangleShape World::CreateLava(int x, int y)
{
	size_t ElementSize = World::GetSizeOfElement();

	sf::Color elementColor;
	int randNum = rand() % 3;
	switch (randNum)
	{
	case 0:
		elementColor = sf::Color(240, 87, 31); // Light Orange
		break;
	case 1:
		elementColor = sf::Color(224, 64, 4); // Darker Orange
		break;
	case 2:
		elementColor = sf::Color(201, 57, 4); // More Darker Orangr
		break;
	}

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(ElementSize, ElementSize));
	shape.setFillColor(elementColor);
	shape.setPosition(x * ElementSize, y * ElementSize);
	return shape;
}

sf::RectangleShape World::CreateStone(int x, int y)
{
	size_t ElementSize = World::GetSizeOfElement();

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(ElementSize, ElementSize));
	shape.setFillColor(sf::Color(90, 90, 90)); // Gray
	shape.setPosition(x * ElementSize, y * ElementSize);
	return shape;
}
