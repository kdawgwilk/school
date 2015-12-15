# converting two dimensional array to single dimensional
# convert a cell index to x, y pair
# i, j = x, y
# index = j * m + i
# i = index % m
# j = index / m


# Write this method.
# It should return True if this is the end cell, OR if it leads to the end cell.
# It should return False if this is a loser cell.
def SolveR(self, i,  j):
    # Mark this cell as visited.
    self.cells[i][j].mVisited = True
    # Get index number of this cell
    index = 0
    # Record the index in the class variable mMoves.
    self.mMoves[0,]
    # If we are at the end cell, return true.
    if index = end_cell:
        return True
    # move left if there is no wall, and it hasn't been visited. Return true if it returns true.
    if not self.cells[i][j].l and not self.cells[i - 1][j].mVisited:
        if self.SolveR(i - 1, j):
            return True
    # move right if there is no wall, and it hasn't been visited. Return true if it returns true.
    elif not self.cells[i][j].r:
        return True
    # move down if there is no wall, and it hasn't been visited. Return true if it returns true.
    elif not self.cells[i][j].d:
        return True
    # move up if there is no wall, and it hasn't been visited. Return true if it returns true.
    else not self.cells[i][j].u:
        return True
    # This is a loser cell, so undo the move from self.mMoves, and return false to the previous cell.
    return False