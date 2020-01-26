# SFML-GameOfLife
A simulation of Conway's Game of Life

Conway's game of life is a zero player game, which takes a single input, then computes the following generations. It consists of a grid of cells which can either be alive or dead. When the next generation is calculated, the cells live or die depending on 3 rules:

- If a living cell is surrounded by less than two other cells, it dies of underpopulation
- If a living cell is surrounded by more than three other cells, it dies of overpopulation
- if a dead cell is surrounded by exactly three other cells, it is born

The surrounding cells of a cell are the 8 cells neighbouring that cell, either horizontally, vertically or diagonally.

White squares represent alive cells, and black squares represent dead cells.

You can progress through each generation by clicking the mouse inside the game window.
