CC = g++
CFLAGS = -w -g 
LFLAGS = -lSDL2 -lSDL2_image
SRC = src/main.cpp src/init.cpp src/RenderWindow.cpp
HPP = src/init.hpp src/RenderWindow.hpp

main: $(SRC) $(HPP)
	$(CC) $(CFLAGS) $(LFLAGS) $(SRC) -o main
