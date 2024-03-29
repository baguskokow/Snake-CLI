CXX := g++
CXX_FLAGS := -std=c++17
LDLIBS := ncurses
OBJECT := build/objects
BIN := build/bin

all: build main.o snake.o characters.o control.o score.o
	$(CXX) $(CXX_FLAGS) $(OBJECT)/main.o $(OBJECT)/snake.o $(OBJECT)/characters.o $(OBJECT)/control.o $(OBJECT)/score.o -L include/ncurses -l$(LDLIBS) -o $(BIN)/snake

build:
	if [ ! -d build/objects ] && [ ! -d build/bin ]; then \
		mkdir -p build/objects; \
		mkdir -p build/bin; \
	fi 

main.o:
	$(CXX) -c src/main.cpp $(CXX_FLAGS) -o $(OBJECT)/main.o

snake.o:
	$(CXX) -c src/snake.cpp $(CXX_FLAGS) -o $(OBJECT)/snake.o

characters.o:
	$(CXX) -c src/characters.cpp $(CXX_FLAGS) -o $(OBJECT)/characters.o

control.o:
	$(CXX) -c src/control.cpp $(CXX_FLAGS) -o $(OBJECT)/control.o

score.o:
	$(CXX) -c src/score.cpp $(CXX_FLAGS) -o $(OBJECT)/score.o

clean:
	@echo "Clearing..."
	@rm -rf build
