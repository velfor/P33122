#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

void initBat(sf::RectangleShape& bat, const sf::Color batColor, const sf::Vector2f batPosition) 
{
	bat.setSize(batSize);
	bat.setFillColor(batColor);
	bat.setPosition(batPosition);
}