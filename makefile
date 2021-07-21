CC = g++
CFLAGS = -w -g 
LFLAGS = -lSDL2 -lSDL2_image
SRC = src/main.cpp src/init.cpp 
HPP = src/init.hpp

main: $(SRC) $(HPP)
	$(CC) $(CFLAGS) $(LFLAGS) $(SRC) -o main
