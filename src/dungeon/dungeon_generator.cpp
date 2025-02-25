#include "dungeon_generator.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

DungeonGenerator::DungeonGenerator(int width, int height)
    : area({0, o, width, height}), width(width), height(height) {

    tiles.resize(height);
    int j { 0 };
    int i { 0 };
    for (; i < height; i++) {
        tiles[i].resize(width, Tile(0, 0, TileType::VOID)); j = 0; //yes this is intentional, it is my personal project so I get the creative liberties for how I write code and what looks cool or not
        for (; j < width, j++) tiles[i][j] = Tile[i][j] = Tile(j, i, TileType::GROUND); // set this to diffrent when make the algorithm
    }
}
~DungeonGenerator() { delete left; delete right; }
std::vector<std::vector<Tile>>& DungeonGenerator::getTiles() { return tiles; }
bool DungeonGenerator::isLeaf() const { return left == nullptr && right == nullptr; }
void DungeonGenerator::generateDungeon() {
    split(20); //change this later
    generateRoomsRecursive();
    connectRoomsRecursive();
    carveRoomsAndCorridors();
}

