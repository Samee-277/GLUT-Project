# GLUT-Project
Glut project description

Hiiiiiii!!! 

This is my GLUT project. I will explain you how I make this project.

A simple 2D Racing Car Game developed using C++ and OpenGL GLUT as a Computer Graphics project.
The player controls a red racing car and tries to avoid incoming obstacles. The obstacles continuously move toward the player, and the score increases whenever an obstacle passes the bottom of the screen. As the score increases, the game becomes faster and more challenging.

----Setup Instruction-----

	Firstly I attached a ong file to share my idea of this project
	
	<img width="602" height="637" alt="image" src="https://github.com/user-attachments/assets/9b3dbe0e-0f8e-422d-99f2-530103c2db60" />
	

Expected Game Appearance:
	
	🟦 Blue roadside areas(River Side)
	
	⬛ Dark road(main road)
	
	⬜ White center lane markings
	
	🔴 Red player car(user's car)
	
	🟣 Purple cars(opposition car)
	
	🏆 Score display

Features:
     
		:2D racing game using OpenGL and GLUT
		:Player-controlled red car
		:Left/right movement
		:Three moving obstacles
		:Collision detection
		:Animated road markings
		:Score system
		:Increasing difficulty
		:Maximum speed limit
		:Game Over screen
		:Restart functionality
		:Random obstacle respawning
		:Double buffering for smoother animation

How to play---(Keyboard)
		
		arrow(←)-Move left
		arrow(→)-move right
		R/r      Restart game
How to build the game:

	Player Car
		
		The player is represented by a red rectangle near the bottom of the screen.
		Its horizontal position is controlled using:
		float playerX = -0.2f;
		Pressing the left or right arrow changes the player's horizontal position.

	Road

		The road is drawn in the center of the screen.
		The two blue areas represent the roadside, while the dark area represents the road.
		White lane markings continuously move downward to create the illusion of forward movement.

	Obstacles

		The game contains three obstacles:
		float obstacles[3][2] = {
		    {-0.2f, 1.2f},
		    { 0.2f, 1.8f},
		    { 0.2f, 2.4f}
		};
		Each obstacle has:
		X position
		Y position
		The obstacles move downward using:
		obstacles[i][1] -= speed;
		When an obstacle leaves the screen, it is randomly repositioned:
		obstacles[i][1] = 1.2f + (rand() % 4) * 0.2f;
		This provides variation in the obstacle positions.

	Collision Detection

		The game checks whether the player's rectangle overlaps with an obstacle.
		If a collision occurs:
		gameOver = true;
		The game then displays:
		GAME OVER!
		Press 'R' to Restart
	
	Score
	
		The score increases whenever an obstacle passes the bottom of the screen.
		score++;
		The current score is displayed in the upper-right portion of the game window.

	Increasing Difficulty
	
		The initial speed is:
		float speed = 0.015f;
		Every 3 points, the game increases the speed:
		if (score % 3 == 0 && speed < MAX_SPEED) {
		    speed += 0.003f;
		}
		The maximum speed is:
		const float MAX_SPEED = 0.04f;
		Therefore, the longer the player survives, the faster the obstacles move.

Technologies Used:
			
			Programming Language: C++
			Graphics Library: OpenGL
			Window/Input Library: GLUT
			Graphics: 2D OpenGL
			Animation: GLUT Timer
			Rendering: Immediate Mode OpenGL
			Buffering: Double Buffering
			Window Size: 600 × 600 pixels

Dependencies


		C++ compiler
		OpenGL
		GLUT or FreeGLUT
		OpenGL development libraries
		Code::Blocks + MinGW

The program uses:
	#include <GL/glut.h>
	Therefore, GLUT/FreeGLUT must be installed and configured correctly.

Main Functions:

display()
	Draws the complete game:
	Roadside
	Road
	Lane markings
	Player car
	Obstacles
	Score
	Game Over message

update()

The main game update function.

It handles:

	Road animation
	Obstacle movement
	Obstacle respawning
	Score updates
	Speed increases
	Collision detection
	
specialKeys()

	Handles:
	
		Left Arrow
		Right Arrow
	
	keyboard()
		Handles normal keyboard input, especially:
		R / r


for restarting the game.
	
	resetGame()
		Restores:
		Score = 0
		Speed = 0.015
		Player = Starting Position
		Obstacles = Starting Positions
		Game Over = false


For setup opengl environment in codeblocks:
	
	I share a youtube link : 
	
		https://www.youtube.com/watch?v=7rLo69vCooU&pp=ygUUb3BlbmdsIGdsdXQgdHV0b3JpYWw%3D
		Notice that this video only for codeb;ocks 20.03 version.

