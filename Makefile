#OBJS specifies which files to compile as part of the project
OBJS = main.cpp

#CC specifies which compiler we're using
CC = clang++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
# all : $(OBJS)
# 	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

main: main.o SDLHelper.o SpriteSheet.o Player.o GrapplingHook.o
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) main.o SDLHelper.o SpriteSheet.o Player.o GrapplingHook.o

main.o: main.cpp SDLHelper.hpp SpriteSheet.hpp
	$(CC) -c main.cpp

SDLHelper.o: SDLHelper.cpp SDLHelper.hpp
	$(CC) -c SDLHelper.cpp

SpriteSheet.o: SpriteSheet.cpp SpriteSheet.hpp
	$(CC) -c SpriteSheet.cpp

Player.o: Player.cpp Player.hpp GrapplingHook.hpp
	$(CC) -c Player.cpp

GrapplingHook.o: GrapplingHook.cpp GrapplingHook.hpp
	$(CC) -c GrapplingHook.cpp
