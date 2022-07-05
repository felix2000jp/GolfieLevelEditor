# Name of the executable 
NAME = game.exe 

# The source files
SRCS = main.c source/ball/ball.c source/line/line.c source/hole/hole.c source/block/block.c

# Setup complier
CC     = gcc
CFLAGS = -O1 -Wall -std=c99 -Wno-missing-braces

# Setup include directory
IDIR = -I include/

# Setup lib directory and libraries
LDIR = -L lib/
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

compile:
	$(CC) $(SRCS) -o $(NAME) $(CFLAGS) $(IDIR) $(LDIR) $(LIBS)

clean:
	rm -f $(NAME)

# This is the raw command 
# gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm