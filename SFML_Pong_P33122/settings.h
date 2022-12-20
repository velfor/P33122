#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float BAT_WIDTH = 20.f;
const float BAT_HEIGHT = 80.f;
const float BAT_OFFSET = 10.f;
const sf::Vector2f BAT_SIZE(20.f, 80.f);
const sf::Color LEFT_BAT_COLOR{ 158,20,37 };
const sf::Color RIGHT_BAT_COLOR{ 20,158,49 };
const float BAT_SPEED = 5.f;
const sf::Vector2f LEFT_BAT_START_POS{ 
	BAT_OFFSET, 
	(WINDOW_HEIGHT - BAT_HEIGHT) / 2 
};
const sf::Vector2f RIGHT_BAT_START_POS{ 
	WINDOW_WIDTH - BAT_OFFSET- BAT_WIDTH, 
	(WINDOW_HEIGHT - BAT_HEIGHT) / 2 
};

const float BALL_RADIUS = 15.f;
const sf::Color BALL_COLOR{ sf::Color::Yellow };
const sf::Vector2f BALL_START_POS{ 
	(WINDOW_WIDTH - 2 * BALL_RADIUS) / 2, 
	(WINDOW_HEIGHT - 2 * BALL_RADIUS) / 2 
};

const int CHAR_SIZE = 64;
const sf::Vector2f LEFT_TEXT_START_POS{ 200.f, 10.f };
const sf::Vector2f RIGHT_TEXT_START_POS{ 550.f, 10.f };