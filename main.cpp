#include <iostream>
#include "koko/assets.hpp"

#define HEIGHT 20
#define WIDTH 50
#define VERTICALPOSITION 0
#define HORIZONTALPOSITION 0

// To do : 
// Random Position Start for Python and Food already done, but only support for horizontal at Python Character
// Create Mechanism to Python Character support start position as vertical

int main() {
	initscr();
	const char gameTitle[] = "[ Snake CLI ]";
	const char scoreTitle[] = "[ Score ]";
	Snake Map(HEIGHT, WIDTH, VERTICALPOSITION, HORIZONTALPOSITION, gameTitle, scoreTitle);

	//Map.randomPositionCharacters();
	Map.render();
	//Map.print();
	
	return 0;
}
