``
# Dungeon Generation
For this project, I am going to decide between three main algorithms.

## 1. Random Walk
This algorithm is the simplest out of the three algorithms. After every tile, the program generates a random direction to continue, then moves to that tile and continues.
<br>
I found this example of Random Walk on github by the user abhayMore
[Random-Walker](https://github.com/abhayMore/Random-Walker)
### Examples of Random Walk (adapted from abhayMore)
```cpp
float x{ 0 };
float y{ 0 };

void random_walk() {
	int random = rand() % 8 + 1;
	switch (random) {
		case 1:
			x++;
			break;
		case 2:
			y--;
			break;
		case 3:
			y++;
			break;
		case 4:
			y--;
			break;
		case 5:
			x++;
			y++;
			break;
		case 6:
			x++;
			y--;
			break;
		case 7:
			x--;
			y++;
			break;
		case 8:
			x--;
			y--;
			break;
	}
}
```
### Pros:
- Effective for creating realistic caves and/or corridors for dungeons.
- simple and easy to implement.

### Cons:
- Prone to error due to it's simplicity. It also lacks any checks or optimisations, making it potentially inefficient when it comes to larger-scale generations and/or complex generations.
- Since it is random, some paths you are going to get with this algorithm are going to be crazy.

## 2. Cellular Automata
There exists a grid system that interacts with cells, telling it what state it should be in depending on the rules, iterating until a natural-like structure is generated, kind of like a **mini-Bogo sort** where the process continues until the rules are satisfied for each cell, resulting in a stable pattern. 

Provided by the TFE TIMES, this article will how an interesting usage for the Cellular Automaton algorithm for creating complex shapes
[Cellular Automaton](https://tfetimes.com/c-elementary-cellular-automaton/)

### Example of a Simple Cellular Automata code (adapted from TFE TIMES)

```cpp
	#include <bitset>
	#define SIZE 80
	#define RULE 30
	#define RULE_TEST(x) (RULE & 1 << (7 & (x)))
	void evolve(std::bitset<SIZE> &s) {
		int i { 0 };
		std::bitset<SIZE> t(0);
		t[SIZE - 1] = RULE_TEST( s[0] << 2 | s[SIZE-1] << 1 | s[SIZE-2] );
		t[0] = RULE_TEST( s[1] << 2 | s[0] << 1 | s[SIZE-1] );
		i = 1;
		for (; i < SIZE-1; i++) 
			t[i] = RULE_TEST( s[i+1] << 2 | s[i] << 1 | s[i-1] );
		i = 0;
		for (; i < SIZE; i++) s[i] = t[i];
	}
```
This example code above is utilising a simple rule called rule 30 which can be used to generate complex patterns, with a simple rule. The rule states that takes cells, 2 adjacent cells and itself, and than set it to either 1 or 0 depending on the result. Iterating until it has the final pattern
### Pros:
- Simple to implement with minimal rules.
- Can generate very complex and natural-like structures.

### Cons:
- Performance: Lots of iterations mean longer runtime, or for structures that require lots of precision with their layouts.

## 3. Binary Search Partition
The grid is split into smaller and smaller sections (hence binary partition), and rooms or corridors (etc.) are then placed into these sections.

### Pros:
- Offers fine control over room placement, ensuring a connected layout is generated.

### Cons:
- This reliability makes the generations predictable.

---

## Conclusion

Considering these 3 common procedural generation algorithms, it has been decided that the program will use a combination of Binary Search Partition

- **Binary Search Partition** 
	- Considering the gameloop, making fine control over the rooms, makes it so that the core gameplay (of minesweeper) look is not compromised by wonky generations of the room.
	- More predictable makes debuging easier and reduces change of softlocks for a map based puzzle which can easily be compromised when generating.
-  (Stretch Goal) Cellular Automata:
	- This can be used to decorate rooms, in a unique way.


# Minesweeper 

This a code example for generating a random minesweeper board,
adapted from [Creating Minesweeper](https://www.geeksforgeeks.org/cpp-implementation-minesweeper-game/) and Gemini 2.0 Flash Thinking Experimental
```cpp
#include <vector>
#include <random>

}
```
