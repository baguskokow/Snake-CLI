#include <iostream>
#include "koko/assets.hpp"

// To do : 
// Create Random Position for Food in map object

int main() {
	initscr();
	const char gameTitle[] = "[ Snake CLI ]";
	const char scoreTitle[] = "[ Score ]";
	Snake Map(20, 50, 0, 0, gameTitle, scoreTitle);

	Map.render();
	
	return 0;
}
