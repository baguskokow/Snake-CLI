
# Snake-CLI
Snake CLI is a free and open-source snake game that runs in the terminal, written using C++ and ncurses library; while some people might say, "Working in the terminal is so boring," now there's no more "boring" when you're working in the terminal because you can play the snake game on your Linux desktop or Linux server!

// video game

## Installation

### From Package
#### Ubuntu
- Install ncurses library
```
$ sudo apt install libncurses5-dev libncursesw5-dev
```
- Download package snake-cli.deb
```
$ wget ....
```
- Install 
```
$ sudo dpkg -i snake-cli.deb
```

### From Source
- Install ncurses library
##### Ubuntu
```
$ sudo apt install libncurses5-dev libncursesw5-dev
```
##### OpenSUSE
```
$ sudo zypper install ncurses-devel
```

- Clone the repository
```
$ git clone https://github.com/baguskokow/Snake-CLI.git
```
- Compile
```
$ cd Snake-CLI
$ make
```
- Install
```
$ make install
```

## Usage
- Run Game
```
$ snake
```

### Control
-  <kbd>↑</kbd>to move up
- <kbd>→</kbd> to move right
- <kbd>↓</kbd> to move down
- <kbd>←</kbd> to move left
- <kbd>SPACE</kbd> to pause game or select (skin)
- <kbd>ENTER</kbd> to select menu
- <kbd>q</kbd> to quit from menu
- <kbd>r</kbd> to reset highest score

