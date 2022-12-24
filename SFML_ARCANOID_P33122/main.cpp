#include "settings.h"
#include "functions.h"
#include "bat.h"

using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		WINDOW_TITLE
	);
	Bat bat;
	batInit(bat);

	while (window.isOpen()){
		checkEvents(window);
		updateGame(bat);
		checkCollisions();
		drawGame(window, bat);
		
	}
	return 0;
}