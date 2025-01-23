This is a Document dedicated to planning out the overall core gameplay loop of the game

**Brainstorming**
```
I would like a game with puzzle mechanics, I think combat gameplay like hack and slash are fun, but when I consider the time scope and the overall enjoyment that comes along with it. Getting the feel of attacking enemies the traditional way, just does not feel satisfying without lots of minor tweeks and expecually without a game engine alot of time and extra code.

This is why, I am thinking of a way of making a rougelike, procedurally generated game where the defeating of enemies is done through, procedurally generated puzzles/game. Kind of like how Peglin takes Pachinko and makes that into a rougelike, of course I am not going to the scopes of Peglin, but I think my point has come accross. 

I am looking at games like Balatro, which takes Poker a game that is already well established and puts their own twist on it, I think I might do something like that with this, this way: 
	I do not have to create an entirely new puzzle game from scratch
	The game is easier to learn
	Already guarenteed that most likely the game I am adapting from is fun
	More procedural generation I get to make

Having wrote all this, I think the loop will be the game, but a gimik is that the player has to use their character to solve the puzzle, like the ice puzzles of the Pokemon games.

Thinking about what games I should choose to base off of, there are a couple I have to think from:
	Minesweeper (use to play this game alot during my breaks at work (when I took breaks that is...))
	Reversi (I loved this game as a kid)
	Checkers
	Chess
All of these games I could potentially think of means to make them into rougelikes and put a twist on it for the gameplay part of the game.

Minesweeper:
	This one sounds quite fun to make, it also seems like one of the easier games to produce for the game. perhaps, the player is given small minesweeper puzzles across the room, and if the fail it, they take damage but if they succeed they deal damage to the enemy. The further into the game you go, the harder the minesweeper becomes.

Reversi:
	What if the player has to, like in the Minesweeper idea, be given a reversi game (mid complete or something idk yet) and be asked to solve it, thus dealing damage if succedd, or taking damage if lose. The problem is, unlike minesweeper, I do not see a means that the difficulty could spike as easily, such, minesweeper has a very 1 0 difficulty ceiling.

Checkers:
	Provide checkers senarios and ask the player to solve them, thus dealing damage if succedd, or taking damage if lose. An issue I see is that Chess might be too boring in this situation.

Chess:
	Provide Chess senarios and ask the player to solve them, thus dealing damage if succedd, or taking damage if lose. The issue with this is that chess is a very complex game, and implementing it in small forms to a way that makes it that there is always a solution could either be too easy or impossible, and easy to program a softlock, and since I am not good enough at chess would not know a softlock compared to a case of my ineptitude. 

From these four game ideas, it is safe to assume that I am going to make a game where you deal damage from solving a mini puzzle and take damage from failing it, and you are giving puzzles to solve throughout the room. Each puzzle is randomly generated.

I chose to center my game around Minesweeper.

```

**Notice:** The following is a legibility recap of what I wrote in my free writing brainstorming section, this section was assisted by Gemini 2.0 Flash Experimental.

*   **Puzzle-Based Combat:**  Traditional combat mechanics will be replaced by puzzle-solving. This choice is driven by considerations of development scope, time constraints, and the desire to create a unique and engaging gameplay experience without the complexities of developing satisfying traditional combat from scratch.
*   **Roguelike and Procedural Generation:** The game will be a roguelike with procedurally generated dungeons and puzzles. This will maximise replayability and align with the desire to explore procedural generation techniques.
*   **Adapted Puzzle Mechanic: Minesweeper:**  Combat encounters will be based on Minesweeper puzzles. Minesweeper was chosen for its inherent puzzle structure, clear win/loss conditions, scalability in difficulty, and relative ease of implementation.  This approach leverages a pre-existing, well-understood game mechanic to create a novel roguelike experience.
*   **Core Gameplay Loop:** The core gameplay loop will revolve around entering a room, encountering procedural generated Minesweeper puzzles, and interacting with them using the player. Successfully solving puzzles will deal damage to enemies, while failing puzzles will result in the player taking damage.  This loop will be the foundation of the game's moment-to-moment gameplay.


**Update:** Thinking about a design choice that, requires the map being generated first, and than the placement of the minesweeper is dependant on the room, and if the minesweeper is placed next to a wall the wall is counting in the puzzle etc.

