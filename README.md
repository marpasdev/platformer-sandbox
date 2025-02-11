# Platformer Sandbox

This is basically a clone of Terraria done in C that I made to practice programming, game development and because it seemed like a fun and pretty customizable idea. Though it has to be said that my vision for this game is to be quite different besides the core mechanics.

Currently you can move a dirt tile - a player placeholder. You can move in any direction using either WASD or arrows. You can also scroll to zoom. The terrain is generated randomly using grass tile for the surface, dirt blocks right below them and a bit deeper are stone tiles.

I resolved most issues, but the movement is jittery and I will fix that later. I hope to add more features soon.

## How to compile

- you need to have Cmake installed
- create a build directory and enter it - `mkdir build`, `cd build`
- `cmake ..`
- `make`
- `./PlatformerSandbox`