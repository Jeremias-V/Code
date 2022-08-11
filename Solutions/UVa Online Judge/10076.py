"""
UVa Problem 10076 Solution

Author: Jeremias Villalobos

This code was documented using the Google Standard.
https://github.com/google/styleguide/blob/gh-pages/pyguide.md#383-functions-and-methods
"""

from sys import stdin, stdout
from heapq import heappop, heappush
from math import ceil

grid = None
a1, a2, gamma = None, None, None
b1, b2, delta = None, None, None
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

class State:
    """The states of every move of the robot.

    The State class represents the information needed
    for every possible State of the bumpy robot, that
    is their current position on the grid, the current
    energy left after the moves that led to their
    current position, and the time that has taken the
    robot to get to their current position (depending
    on the previous moves).

    Attributes:
        row:
            An integer indicating in which row of the grid
            is located the robot.   
        col:
            An integer indicating in which column of the 
            grid is located the robot.
        energy:
            An integer indicating the amount of energy left
            for the robot to move.
        time:
            An integer indicating how much time it has taken
            the robot to move to their current position.
    """

    def __init__(self, row, col, energy, time):
        """ 
        Inits an instance (object) of the State class with 
        all the attributes needed as arguments of this function. 
        """
        self.row = row
        self.col = col
        self.energy = energy
        self.time = time

    def __lt__(self, other):
        """
        Compares the energy of two objects of the class State
        and returns if the current object has higher energy.
        """
        return self.energy > other.energy

    def energyCost(self, adjRow, adjCol):
        """How much energy is required for the robot to move.

        Calculates the energy required for the robot to move
        to an adjacent block (i.e. up, down, left, right, 
        respecting the grid bounds).

        Args:
            adjRow:
                An integer as the adjacent valid row.
            adjCol:
                An integer as adjacent valid column.

        Returns:
            An integer indicating how much energy the robot needs 
            to move from (row, col) to (adjRow, adjCol).
        """

        h1 = grid[self.row][self.col]
        h2 = grid[adjRow][adjCol]
        ans = None

        if h1 > h2:
            ans = ceil(a1 * (h1 - h2)) + gamma
        elif h1 == h2:
            ans = gamma
        else:
            ans = ceil(a2 * (h2 - h1)) + gamma

        return ans

    def timeCost(self, adjRow, adjCol):
        """How much time is required for the robot to move.

        Calculates how much time it takes for the robot 
        to move to an adjacent block (i.e. up, down, left,
        right, respecting the grid bounds).

        Args:
            adjRow:
                An integer as the adjacent valid row.
            adjCol:
                An integer as adjacent valid column.

        Returns:
            An integer indicating how much time is needed for
            the robot to move from (row, col) to (adjRow, adjCol).
        """

        h1 = grid[self.row][self.col]
        h2 = grid[adjRow][adjCol]
        ans = None

        if h1 > h2:
            ans = ceil(b1 * (h1 - h2)) + delta
        elif h1 == h2:
            ans = delta
        else:
            ans = ceil(b2 * (h2 - h1)) + delta
        
        return ans
        
def validMovement(M, N, r, c):
    """Is the row and column in bounds of the grid?

    Determines if the row and column received as arguments
    are in bounds of the grid size received as M rows and
    N columns.

    Args:
        M:
            An integer indicating the amount of rows in the grid.
        N:
            An integer indicating the amount of columns in the grid.
        r:
            An integer indicating the row to which the robot wants
            to move (0 - indexed).
        c:
            An integer indicating the column to which the robot wants
            to move (0 - indexed).

    Returns:
        A boolean indicating if the movement is valid, that is if the
        row and column are in bounds of the grid, in which case returns
        True, otherwise it returns False.
    """

    ans = True

    if r < 0 or r >= M:
        ans = False
    elif c < 0 or c >= N:
        ans = False

    return ans

def solve(initS, M, N, rt, ct):
    """Computes the time required for the robot to reach its target block.

    This function uses a dijsktra algorithm with states (class State)
    to compute the minimum time required for the robot to reach its
    target block (if possible), starting from the initial block, 
    energy and time. The robot can only reach the target block
    if there exists a path to which its total energy consumption is 
    not greater than the initial energy.

    Args:
        initS:
            An State object with the initial values of the robot.
            That is the starting position, energy and time (which
            initially is always 0).
        M:
            An integer indicating the amount of rows in the grid.
        N:
            An integer indicating the amount of columns in the grid.
        rt:
            An integer indicating the row of the target block (0 - indexed).
        ct:
            An integer indicating the column of the target block (0 - indexed).
    
    Returns:
        An integer indicating the minimum time required for the robot
        to reach its target block. Or returns float("inf") in case it
        wasn't possible for the robot to reach its target block (in that
        case it has to be because the initial energy is not sufficient
        for any possible path from initial block to target block).
    """

    # Each block in the grid initially requires an 'infinite' amount
    # of time to be reached, because its time has not been improved.
    # This matrix (d) represents the best time required to reach
    # each block of the grid, best means lowest time.

    d = [[float("inf") for _ in range(N)] for _ in range(M)]

    # heap is the priority queue for the dijkstra.
    
    heap = []

    heappush(heap, initS)
    d[initS.row][initS.col] = initS.time

    while len(heap) != 0:
        
        currS = heappop(heap)
        r = currS.row
        c = currS.col
        E = currS.energy
        T = currS.time

        for i in range(4): 
            
            # generates every possible movement from the current position

            newR = r + dx[i]
            newC = c + dy[i]

            if(validMovement(M, N, newR, newC)):

                # if the movement is valid, calculates how much
                # energy and time is required to move.

                newE = E - currS.energyCost(newR, newC)
                newT = T + currS.timeCost(newR, newC)

                if newE >= 0 and newT < d[newR][newC]:

                    # if there is enough energy and the new time improves
                    # the previous time stored for that block, it assigns
                    # the new better time and pushes the new state (i.e.
                    # the state after moving to an adjacent cell).

                    d[newR][newC] = newT

                    newS = State(
                        row=newR, col=newC,
                        energy=newE, time=newT)

                    heappush(heap, newS)

    return d[rt][ct]


def main():
    """The main function where the problem input is read, 
    solve() is called, and the output is printed."""

    global grid, a1, a2, gamma, b1, b2, delta

    # M, N is the size of the grid, that is
    # M rows and N columns.

    M, N = map(int, stdin.readline().strip().split())

    while M != 0 and N != 0:

        # (a1) and (a2) are the constants for the energy function
        # (gamma) is another constant for the energy function

        a1, a2, gamma = stdin.readline().strip().split()
        a1 = float(a1); a2 = float(a2); gamma = int(gamma)

        # (b1) and (b2) are the constants for the time function
        # (delta) is another constant for the time function

        b1, b2, delta = stdin.readline().strip().split()
        b1 = float(b1); b2 = float(b2); delta = int(delta)

        # (grid) is the matrix with every height of the block in the grid.
        # that is, in grid[i][j] we have the height for the block in the 
        # row i and column j.
        
        grid = []

        for _ in range(M):
            grid.append(list(map(int, stdin.readline().strip().split())))

        # (rs, cs) is the row and column of the starting block
        # (rt, ct) is the row and column of the target block
        # (E) is the energy constraint for the robot
        
        rs, cs, rt, ct, E = map(int, stdin.readline().strip().split())
        
        # Creates the initial state of the robot with the info
        # given by the input.

        initialState = State(row=rs-1, col=cs-1, energy=E, time=0)
        
        # Stores the result of calling solve() with the arguments
        # provided by the input. The result would be either
        # float("inf") which means the robot couldn't reach
        # the target block, or an integer indicating the minimum
        # time required for the robot to reach the target block.

        ans = solve(initialState, M, N, rt-1, ct-1)

        if ans != float("inf"):

            stdout.write("{}\n".format(ans))

        else:
            
            stdout.write("failed\n")

        M, N = map(int, stdin.readline().strip().split())

main()

