#OBJS specifies which files to compile as part of the project
OBJS = main.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -g -w -std=c++11

#CCF combines CC and COMPILER_FLAGS
CCF = $(CC) $(COMPILER_FLAGS)

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable
# all : $(OBJS)
# 	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

main: main.o SDLHelper.o SpriteSheet.o Player.o GrapplingHook.o \
			GrapplingPoints.o GrapplingPoint.o Obstacles.o Obstacle.o Map.o \
			InputHandler.o FireGrapple.o Vec2D.o Detach.o Text.o Star.o Entity.o \
			Jetpack.o Background.o Menu.o MenuInputHandler.o MenuSelect.o \
			MenuUp.o MenuDown.o Controls.o Camera.o FuelDisplay.o
	$(CCF) -o $(OBJ_NAME) main.o SDLHelper.o SpriteSheet.o \
			Player.o GrapplingHook.o GrapplingPoints.o GrapplingPoint.o Obstacles.o \
			Obstacle.o Map.o InputHandler.o FireGrapple.o Vec2D.o Detach.o Text.o \
			Star.o Entity.o Jetpack.o Background.o Menu.o MenuInputHandler.o \
			MenuSelect.o MenuUp.o MenuDown.o Controls.o Camera.o FuelDisplay.o \
			$(LINKER_FLAGS)

main.o: main.cpp SDLHelper.hpp SpriteSheet.hpp GrapplingPoints.hpp Player.hpp Vec2D.hpp Text.hpp
	$(CCF) -c main.cpp

SDLHelper.o: SDLHelper.cpp SDLHelper.hpp
	$(CCF) -c SDLHelper.cpp

SpriteSheet.o: SpriteSheet.cpp SpriteSheet.hpp
	$(CCF) -c SpriteSheet.cpp

Player.o: Player.cpp Player.hpp GrapplingHook.hpp Vec2D.hpp
	$(CCF) -c Player.cpp

GrapplingHook.o: GrapplingHook.cpp GrapplingHook.hpp Vec2D.hpp Obstacles.hpp Map.hpp
	$(CCF) -c GrapplingHook.cpp

GrapplingPoints.o: GrapplingPoints.cpp GrapplingPoints.hpp GrapplingPoint.hpp SpriteSheet.hpp
	$(CCF) -c GrapplingPoints.cpp

GrapplingPoint.o: GrapplingPoint.cpp GrapplingPoint.hpp
	$(CCF) -c GrapplingPoint.cpp

InputHandler.o: InputHandler.cpp InputHandler.hpp FireGrapple.hpp
	$(CCF) -c InputHandler.cpp

FireGrapple.o: FireGrapple.cpp FireGrapple.hpp Player.hpp
	$(CCF) -c FireGrapple.cpp

Detach.o: Detach.cpp Detach.hpp Player.hpp
	$(CCF) -c Detach.cpp

Obstacles.o: Obstacles.cpp Obstacles.hpp Obstacle.hpp
	$(CCF) -c Obstacles.cpp

Obstacle.o: Obstacle.cpp Obstacle.hpp
	$(CCF) -c Obstacle.cpp

Map.o: Map.cpp Map.hpp
	$(CCF) -c Map.cpp

Vec2D.o: Vec2D.cpp Vec2D.hpp
	$(CCF) -c Vec2D.cpp

Text.o: Text.cpp Text.hpp Entity.hpp
	$(CCF) -c Text.cpp

Star.o: Star.cpp Star.hpp
	$(CCF) -c Star.cpp

Entity.o: Entity.cpp Entity.hpp
	$(CCF) -c Entity.cpp

Jetpack.o: Jetpack.cpp Jetpack.hpp
	$(CCF) -c Jetpack.cpp

Background.o: Background.cpp Background.hpp Star.hpp
	$(CCF) -c Background.cpp

Menu.o: Menu.cpp Menu.hpp
	$(CCF) -c Menu.cpp

MenuInputHandler.o: MenuInputHandler.cpp MenuInputHandler.hpp MenuSelect.hpp
	$(CCF) -c MenuInputHandler.cpp

MenuSelect.o: MenuSelect.cpp MenuSelect.hpp
	$(CCF) -c MenuSelect.cpp

MenuUp.o: MenuUp.cpp MenuUp.hpp
	$(CCF) -c MenuUp.cpp

MenuDown.o: MenuDown.cpp MenuDown.hpp
	$(CCF) -c MenuDown.cpp

Controls.o: Controls.cpp Controls.hpp
	$(CCF) -c Controls.cpp

Camera.o: Camera.cpp Camera.hpp
	$(CCF) -c Camera.cpp

FuelDisplay.o: FuelDisplay.cpp FuelDisplay.hpp
	$(CCF) -c FuelDisplay.cpp

clean:
	rm *.o $(OBJ_NAME)
