# Python program for solving maze problems using Depth First Search (DFS)

def solve_maze(maze, start, end):
    def dfs(current):
        nonlocal solved
        if current == end:
            solved = True
            return

        visited.add(current)
        for neighbor in get_neighbors(current):
            if neighbor not in visited:
                path.append(neighbor)
                dfs(neighbor)
                if solved:
                    return
                path.pop()

    def get_neighbors(pos):
        x, y = pos
        neighbors = [(x+1, y), (x-1, y), (x, y+1), (x, y-1)]
        return [(nx, ny) for nx, ny in neighbors if 0 <= nx < len(maze) and 0 <= ny < len(maze[0]) and maze[nx][ny] == 0]

    solved = False
    visited = set()
    path = [start]
    dfs(start)
    return path if solved else []

# Example usage: you can give any maze of your choice
maze = [
    [0, 1, 1, 1, 1],
    [0, 0, 0, 1, 1],
    [1, 1, 0, 0, 1],
    [1, 1, 1, 0, 0],
    [1, 1, 1, 1, 0]
]

start = (0, 0) # you can change the start point 
end = (4, 4) # you can change the end point if you want

solution = solve_maze(maze, start, end)
if solution:
    print("Solution path:", solution)
else:
    print("No solution found.")
