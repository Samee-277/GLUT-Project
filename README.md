# GLUT-Project
Glut project description
Hiiiiiii!!! 

This is my GLUT project. I will explain you how I make this project.

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

		There are three purple obstacles:
		float obstacles[3][2]
		Each obstacle moves downward toward the player.
		hen an obstacle leaves the screen, it is moved back to the top and the player's score increases.

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
