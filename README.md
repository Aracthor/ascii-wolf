## PLEASE DO NOT JUDGE ME ON THE CODE !

I did this wolf a long time ago, I was very unexperimented, and I didn't do most of basic stability checks (malloc's return for instance) because i just wanted to do it fast.

I coded this without IDE, with only a VI (not VIM, VI) without any configuration file. I had to did myself even indentation.

So please, if you are looking for clear and clean code, go to look at another repository.

Else, please compile and run my wolf.

![Screenshot](./images/screenshot.png?raw=true "Screenshot")

## Compilation and run

    gcc *.c -o wolf -lm
	./wolf map.wolf

## Commands

Move front and back with **up and down arrows**.  
Turn over yourself with **left and right arrows**.  
Turn back to your shell with **escape**.

### If your window is jerky while you keep moving:

The termcaps library was not designed to use raycasting in a looped game.
If your display is jerky, just reduce your window's dimentions and re-run my wolf.
