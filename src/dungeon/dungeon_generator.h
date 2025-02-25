#ifndef DUNGEON_GENERATOR_H
#define DUNGEON_GENERATOR_H

#include <vector>
#include "tile.h"

class DungeonGenerator() {
public:
    DungeonGenerator(int width, int height);
    std::vector<std::vector<Tile>& getTiles();
    void generateDungeon(); //change this later when have the procedural stuff intergrated
private:
    int height;
    int width;
    std::vector<std::vector<Tile>> tiles;
}

#endif