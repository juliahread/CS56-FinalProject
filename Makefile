#OBJS specifies which files to compile as part of the project
OBJS = main.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++11

#CCF combines CC and COMPILER_FLAGS
CCF = $(CC) $(COMPILER_FLAGS)

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
# all : $(OBJS)
# 	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

main: main.o SDLHelper.o SpriteSheet.o Player.o GrapplingHook.o GrapplingPoints.o GrapplingPoint.o Obstacles.o Obstacle.o Map.o Text.o
	$(CC) $(COMPILER_FLAGS) -o $(OBJ_NAME) main.o SDLHelper.o SpriteSheet.o Player.o GrapplingHook.o GrapplingPoints.o GrapplingPoint.o Obstacles.o Obstacle.o Map.o Text.o $(LINKER_FLAGS)

main.o: main.cpp SDLHelper.hpp SpriteSheet.hpp GrapplingPoints.hpp Player.hpp
	$(CCF) -c main.cpp

SDLHelper.o: SDLHelper.cpp SDLHelper.hpp
	$(CCF) -c SDLHelper.cpp

SpriteSheet.o: SpriteSheet.cpp SpriteSheet.hpp
	$(CCF) -c SpriteSheet.cpp

Player.o: Player.cpp Player.hpp GrapplingHook.hpp
	$(CCF) -c Player.cpp

GrapplingHook.o: GrapplingHook.cpp GrapplingHook.hpp
	$(CCF) -c GrapplingHook.cpp

GrapplingPoints.o: GrapplingPoints.cpp GrapplingPoints.hpp GrapplingPoint.hpp SpriteSheet.hpp
	$(CCF) -c GrapplingPoints.cpp

GrapplingPoint.o: GrapplingPoint.cpp GrapplingPoint.hpp
	$(CCF) -c GrapplingPoint.cpp

Obstacles.o: Obstacles.cpp Obstacles.hpp
	$(CCF) -c Obstacles.cpp

Obstacle.o: Obstacle.cpp Obstacle.hpp
	$(CCF) -c Obstacle.cpp

Map.o: Map.cpp Map.hpp
	$(CCF) -c Map.cpp

Text.o: Text.cpp Text.hpp
	$(CCF) -c Text.cpp

clean:
	rm *.o $(OBJ_NAME)
