# Car Dodging Game

A DOS-style car dodging game written in about 700 lines of C/C++. You drive a car at the bottom of the screen and dodge five obstacle cars coming down from the top. Everything is drawn in code with the BGI `graphics.h` library, so there are no sprites or image files.

## Gameplay

- You start with **3 lives**, shown as hearts at the bottom of the screen.
- Hitting an obstacle car costs a life and resets the obstacles.
- Your **score** goes up every frame, and the obstacles get **faster as your score rises**.
- Reach a score of **3000** to win.
- The main menu is controlled with the **mouse** (Play, Help, Exit), and there is a loading bar, a help screen, and an exit confirmation.

## Controls

| Key | Action |
|-----|--------|
| `A` | Move left |
| `D` | Move right |
| `P` | Pause |
| `X` | Back to the main menu |

## Libraries used

| Header | Used for |
|--------|----------|
| `graphics.h` | Drawing the cars, menu and text (BGI graphics) |
| `conio.h` | Keyboard input (`kbhit`, `getch`) |
| `dos.h` | Mouse input through interrupt 33h |
| `stdio.h`, `stdlib.h` | Basic I/O and random obstacle positions |

## How to run

The game uses Turbo C++ style graphics, so it needs an old DOS-style compiler environment.

1. Install **Turbo C++** (or **DOSBox** with Turbo C++ inside it).
2. Open `NAME.CPP` in Turbo C++.
3. Make sure the BGI graphics folder path in the `initgraph` call matches where the `BGI` files are on your computer.
4. Compile and run (`Ctrl+F9`).

## Files

- `NAME.CPP`: the whole game

## Possible improvements

- Replace the repeated collision code for each obstacle car with a loop over an array of cars.
- Add a high score table.
- Add a screenshot or GIF to this README.

## Built with

C/C++, Turbo C++, BGI graphics
