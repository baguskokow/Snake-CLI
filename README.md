# Snake-CLI  
Snake CLI is a free and open-source snake game that runs in the terminal, written using C++ and ncurses library; while some people might say, "Working in the terminal is so boring," now there's no more "boring"  
when you're working in the terminal because you can play the snake game on your Linux desktop or Linux server!  
<br>  
  
[<video loop src="docs/demo-video.mp4"></video>](https://github.com/user-attachments/assets/1452071c-eecb-4e1c-97f4-4ff1c8fae35b)  
  
## Installation  
  
### From Package  
###### Ubuntu  (Focal & Jammy)
- Install ncurses library  
```  
$ sudo apt install libncurses5-dev libncursesw5-dev  
```  
- Download package
```  
$ wget https://github.com/baguskokow/Snake-CLI/releases/download/v1.0.0/snake-cli_1.0.0_amd64.deb
```  
- Install  
```  
$ sudo dpkg -i snake-cli_1.0.0.deb  
```  
  
### From Source  
- Install ncurses library  
###### Ubuntu  
```  
$ sudo apt install libncurses5-dev libncursesw5-dev  
```  
###### OpenSUSE  
```  
$ sudo zypper install ncurses-devel  
```  
  
> Note : <br>  
> For other distros, you can install the ncurses library using their package manager.  
  
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
- Clean up build files  
```  
$ make clean  
```  
- Uninstall  
```  
$ make uninstall  
```  
  
  
## Usage  
- Run Game  
```  
$ snake  
```  
  
### Control  
- <kbd>↑</kbd>to move up  
- <kbd>→</kbd> to move right  
- <kbd>↓</kbd> to move down  
- <kbd>←</kbd> to move left  
- <kbd>SPACE</kbd> to pause game or select (skin)  
- <kbd>ENTER</kbd> to select menu  
- <kbd>q</kbd> to quit from menu  
- <kbd>r</kbd> to reset highest score
