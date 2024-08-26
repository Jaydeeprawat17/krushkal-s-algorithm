# Kruskal's Algorithm in Turbo C++

This program implements Kruskal's Algorithm to find the Minimum Spanning Tree (MST) of a connected, undirected graph. Kruskal's Algorithm is a greedy algorithm that sorts all the edges of the graph by their weight and adds the smallest edge to the MST, ensuring no cycles are formed, until all vertices are included.

## Features

- **Input**: The user can input the number of edges and details for each edge (two vertices and the weight of the edge).
- **Output**: The program outputs the MST with the edges selected and their weights.

## How to Compile and Run

### Requirements

- Turbo C++ compiler.

### Compilation Steps

1. Open Turbo C++.
2. Create a new file and copy-paste the code into the file.
3. Save the file with a `.cpp` extension.
4. Compile the code by navigating to **Compile** > **Compile** or pressing `Alt + F9`.

### Running the Program

1. Run the program by navigating to **Run** > **Run** or pressing `Ctrl + F9`.
2. Follow the prompts to input the number of edges and the details of each edge.
3. The output will display the sorted edges and the Minimum Spanning Tree (MST).

## Code Structure

The program consists of several key parts:

- **Graph Structure**: Represents the edges and their weights.
- **MST Structure**: Used to store the edges that are part of the Minimum Spanning Tree.
- **Kruskal's Algorithm Class**: Contains the methods to:
  - Insert edges into the graph.
  - Sort the edges by weight.
  - Create singleton sets for each vertex.
  - Find the set containing a particular vertex.
  - Perform the union of two sets.
  - Execute Kruskal's Algorithm to find the MST.

## Example Usage

### Input

Below is an example of how to input the data:
```bach
Enter Vertices and their weights Enter No of Edges of Graph G: 6 Insert 1 v1 and v2 And weight A B 4 Insert 2 v1 and v2 And weight A C 3 Insert 3 v1 and v2 And weight B C 1 Insert 4 v1 and v2 And weight B D 2 Insert 5 v1 and v2 And weight C D 5 Insert 6 v1 and v2 And weight A D 6
```

### Output

After running the program and entering the input as shown above, the program will display:

```bach
Sorted Edges by Weight: B C 1 B D 2 A C 3 A B 4 C D 5 A D 6

Singleton Sets: {A}{B}{C}{D}

Selected Vertices: {A B C D}

Minimum Spanning Tree: B C: 1 B D: 2 A C: 3 A B: 4
```

**Explanation**:

- **Sorted Edges**: The edges are sorted by weight in ascending order.
- **Singleton Sets**: Each vertex is initially placed in its own set.
- **Selected Vertices**: Shows the vertices included in the MST.
- **Minimum Spanning Tree**: Lists the edges that form the MST, along with their weights.

## Notes

- **Turbo C++ Specifics**: The program uses functions like `clrscr()` and `getch()` for screen management, which are specific to Turbo C++.
- **Graph Representation**: The graph is represented by its edges, which are sorted and processed to form the MST using union-find to manage disjoint sets.
