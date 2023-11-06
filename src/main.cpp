#include <iostream>
#include "../include/snake.hpp"

#define HEIGHT 20
#define WIDTH 50
#define WINDOWVERTICALPOSITION 0
#define WINDOWHORIZONTALPOSITION 0

int main() {
	initscr();
	const char gameTitle[] = "[ Snake CLI ]";
	const char scoreTitle[] = "[ Score ]";
	Game* Map = new Game(HEIGHT, WIDTH, WINDOWVERTICALPOSITION, WINDOWHORIZONTALPOSITION, gameTitle, scoreTitle);

	Map->render();

	//Characters Food;
	//std::cout << getFood(Food);
	
	delete Map;
	return 0;
}
