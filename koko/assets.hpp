class Screen {
	public:
		char screenSize[20][50];

		void renderScreen() {
			for(int i = 0; i < 20; i++) {
				for(int j = 0; j < 1; j++) {
					screenSize[i][j] = '#';
					std::cout << screenSize[i][j];
				}

				if(i == 0){ 
					for(int j = 0; j < 48; j++) {
						screenSize[0][j] = '#';
						std::cout << screenSize[i][j];
					}
				}
				
				if(i > 0 && i < 19) {
					for(int j = 1; j < 48; j++) {
						screenSize[i][j] = ' ';
						std::cout << screenSize[i][j];
					
						if(screenSize[i][j] == screenSize[i][47]) {
							screenSize[i][47] = '#';
							std::cout << screenSize[i][j];
						} 
					}
				}

				if (i == 19) {
					for(int j = 0; j < 48; j++) {
						screenSize[19][j] = '#';
						std::cout << screenSize[i][j];
					}
				}	


				std::cout << "\n";
			}
		}
};


//class Position {
//	public:
//	Screen map;
//	map
//		void
//};









