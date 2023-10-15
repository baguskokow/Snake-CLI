#include <iostream>
#include "koko/assets.hpp"

// To do : 
// Render for Score Window
// Create Random Position for Food in map object

int main() {
	Screen Map(20, 50, 0, 0, std::string("[ Snake CLI ]").c_str());
   
	Map.render();

	return 0;
}
