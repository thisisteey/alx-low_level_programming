#!usr/bin/python3
"""An island perimeter measuring function is defined"""


def island_perimeter(grid):
    """Calculates and returns the perimeter of an island
    Args:
    grid (list): a list of list of integers that represents the island
    the grid: water = 0 and land = 1"""
    rows = len(grid)
    permt = 0
    for x in range(rows):
        colms = len(grid[x])
        for y in range(colms):
            if (grid[x][y] == 1):
                lftedg = 1 if y == 0 or grid[x][y - 1] == 0 else 0
                tpedg = 1 if x == 0 or grid[x - 1][y] == 0 else 0
                rtedg = 1 if y == colms - 1 or grid[x][y + 1] == 0 else 0
                btedg = 1 if x == rows - 1 or grid[x + 1][y] == 0 else 0
                permt += (tpedg + rtedg + btedg + lftedg)
    return permt
