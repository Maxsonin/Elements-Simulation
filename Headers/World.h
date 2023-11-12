#pragma once

#include <SFML/Graphics.hpp>

#include "Sand.h"
#include "Water.h"
#include "Stone.h"
#include "Lava.h"

class World
{
private:
	static const size_t sizeOfElement = 5; // You can change this values whatever you want

	const sf::Vector2u sizeOfWindow = { 800, 800 }; // You can change this values too
	const size_t WIDTH = sizeOfWindow.x / sizeOfElement + 1;
	const size_t HEIGHT = sizeOfWindow.y / sizeOfElement + 1;
	const sf::Vector2i SIZEOFGRID;
	std::vector<std::vector<char>> worldGrid;

    static const char voidSign = 'v';

public:

	World() : SIZEOFGRID(WIDTH, HEIGHT), worldGrid(WIDTH, std::vector<char>(HEIGHT, voidSign)) {}

	sf::Vector2u GetSizeOfWindow() { return  sizeOfWindow; }
	static const size_t GetSizeOfElement() { return sizeOfElement; }
	std::vector<std::vector<char>>& GetWorldGrid() { return worldGrid; }
	sf::Vector2i GetGridSize() { return SIZEOFGRID; }
	static const char GetSign() { return voidSign; }

	void ClearWorld() { worldGrid.assign(WIDTH, std::vector<char>(HEIGHT, voidSign)); }

	// Methods to work with blocks
	void PlaceElement(int x, int y, char element) {	if (y < HEIGHT && x < WIDTH) worldGrid[x][y] = element; }
	sf::RectangleShape CreateSand(int x, int y);
	sf::RectangleShape CreateWater(int x, int y);
	sf::RectangleShape CreateLava(int x, int y);
	sf::RectangleShape CreateStone(int x, int y);
	void Draw(sf::RenderWindow& window);
};