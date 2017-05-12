# PPP_Asteroids
PPP Assignment 2, Retro Games =>2.5D OpenGL+SDL2

       *********README for PPP_Asteroid(1.0)**********

----------------------------------------------------------------------
Author: Chengyan Zhang(Eric)
----------------------------------------------------------------------
This is a brief guide for this PPP assignment, this includes:

- Citations of assets and sources for programming help
- Controls for the application
- Some issues with the current version
- Future Updates
----------------------------------------------------------------------

Citations
___________________________________________________________________________________

IDE used / Compiler: Qtcreator 5.4 / (msvc/Win64),(gcc/Linux)

Main sites for support: 
	- Stack Overflow
	- Uni Email
	- Lazyfoo OpenGL/SDL tutorials

Third-party Library/Framework used:
	- SDL2
	- SDL_mixer
	- OpenGL(Deprecated)

Assets Used:
	- BGM: "Little Pleasure", downloaded from FreeSound, composed by Setuniman
	(http://www.setuniman.com/)
	- All other sounds are voiced by yours truly.
____________________________________________________________________________________

Controls
____________________________________________________________________________________

Movement:
	- Direction key 
		- (UP) : Move towards the head of the ship.
		- (LEFT) : Rotate anti-clockwise.
		- (RIGHT) : Rotate clockwise.
Other:	
	- Space Bar : Shoot projectiles.
	- "Esc" : Quits application.
	- "E" : Switch to wireframe mode.
	- "R" : Switch back to solid colour mode.
____________________________________________________________________________________

Issues
____________________________________________________________________________________

* Audio currently does not work on lab Linux machines. 

	SDL_GetError() = "No such audio device." when calling Mix_OpenAudio(const char*)

	Possible causes: 

	- SDL environment variable for default audio device, if so, set SDL_AUDIODEVICE to "alsa"
	- Current Linux machines lack the configurations to allow SDL_audio support.
-----
* Loading Audio failed.

	Audio sometimes fails to load, the error stated that the library functions conuldn't open the files.

	Solution: Remove assets folder from the project, rebuild and re-insert it and rebuild. 
____________________________________________________________________________________

Future Updates
____________________________________________________________________________________
</>
