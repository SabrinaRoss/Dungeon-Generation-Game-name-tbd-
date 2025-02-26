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
### Example of a Simple BSP code (completely adopted from DeepSeek )
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Rect {
    int x, y, w, h;
    Rect(int x = 0, int y = 0, int w = 0, int h = 0) 
        : x(x), y(y), w(w), h(h) {}
};

class BSPNode {
    Rect area;
    BSPNode* left;
    BSPNode* right;
    Rect room;
    
public:
    BSPNode(int x, int y, int w, int h)
        : area(x, y, w, h), left(nullptr), right(nullptr) {}

    ~BSPNode() {
        delete left;
        delete right;
    }

    bool isLeaf() const { return !left && !right; }

    void split(int minSize) {
        if (!isLeaf()) return;

        // Choose split direction (prefer wider/narrower splits)
        bool splitH = rand() % 2;
        if (area.w > area.h * 1.25) splitH = false;
        else if (area.h > area.w * 1.25) splitH = true;

        int max = (splitH ? area.h : area.w) - minSize;
        if (max <= minSize) return; // Too small to split

        int split = rand() % (max - minSize) + minSize;

        if (splitH) {
            left = new BSPNode(area.x, area.y, 
                             area.w, split);
            right = new BSPNode(area.x, area.y + split, 
                              area.w, area.h - split);
        } else {
            left = new BSPNode(area.x, area.y, 
                             split, area.h);
            right = new BSPNode(area.x + split, area.y, 
                              area.w - split, area.h);
        }

        // Recursively split children
        left->split(minSize);
        right->split(minSize);
    }

    void generateRooms(int minRoomSize) {
        if (isLeaf()) {
            // Create random room within partition
            int roomW = minRoomSize + rand() % (area.w - minRoomSize);
            int roomH = minRoomSize + rand() % (area.h - minRoomSize);
            int roomX = area.x + rand() % (area.w - roomW);
            int roomY = area.y + rand() % (area.h - roomH);
            room = Rect(roomX, roomY, roomW, roomH);
        } else {
            // Process children first
            left->generateRooms(minRoomSize);
            right->generateRooms(minRoomSize);
            
            // Connect children's rooms
            connectRooms(left->getRoom(), right->getRoom());
        }
    }

    Rect getRoom() const {
        if (isLeaf()) return room;
        
        // Return combined area for corridors
        return Rect(area.x, area.y, area.w, area.h);
    }

private:
    void connectRooms(const Rect& r1, const Rect& r2) {
        // Connect room centers with L-shaped corridor
        int x1 = r1.x + r1.w/2;
        int y1 = r1.y + r1.h/2;
        int x2 = r2.x + r2.w/2;
        int y2 = r2.y + r2.h/2;

        // 50% chance for horizontal-vertical vs vertical-horizontal
        if (rand() % 2) {
            // Horizontal then vertical
            cout << "Corridor: (" << x1 << "," << y1 << ") -> ("
                 << x2 << "," << y1 << ") -> (" << x2 << "," << y2 << ")\n";
        } else {
            // Vertical then horizontal
            cout << "Corridor: (" << x1 << "," << y1 << ") -> ("
                 << x1 << "," << y2 << ") -> (" << x2 << "," << y2 << ")\n";
        }
    }
};

int main() {
    srand(time(nullptr));

    const int MAP_WIDTH = 50;
    const int MAP_HEIGHT = 40;
    const int MIN_SIZE = 6;

    BSPNode root(0, 0, MAP_WIDTH, MAP_HEIGHT);
    root.split(MIN_SIZE);
    
    cout << "Generated dungeon structure:\n";
    root.generateRooms(MIN_SIZE);

    return 0;
}
```
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
