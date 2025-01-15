For this project I am going to decide between three main algorithms

### 1. Random Walk
This algorithm is the simplest out of the three algorithms. After every tile, the program generates a random direction to continue, then moves to that tile and continues.

**Pros:**  
- Effective for creating realistic caves and/or corridors for dungeons.

**Cons:**  
- Since it is so simple, it is prone to error.  
<br>
### 2. Cellular Automata
There exists a grid system that interacts with cells, telling it what state it should be in depending on the rules, iterating until a natural-like structure is generated, kind of like a mini-Bogo sort. The generation continues until the rules are met for each cell.

**Pro:**  
- Simple to implement with minimal rules, generating believable structures and terrains.

**Con:**  
- Performance: Lots of iterations mean longer runtime, or for structures that require lots of precision with their layouts.
<br>
### 3. Binary Search Partition
The grid is split into smaller and smaller sections (hence binary partition), rooms or corridors (etc) are than placed into these sections

**Pro**: Offers fine control over room placement, ensures a connected layout is generated

**Con**: This reliability makes the generations predictable


<h3>Conclusion</h3>
Considering these 3 common procedural generation algorithms. It has been decided that the program will use a combination of Random Walk and Cellular Automata.

- Random Walk for any corridor-like structure, 
- Cellular Automata for more complex rooms, 