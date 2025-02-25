#ifndef DUNGEON_GENERATOR_H
#define DUNGEON_GENERATOR_H

#include <vector>
#include "tile.h"

class DungeonGenerator() {
public:
    DungeonGenerator(int width, int height);
    ~DungeonGenerator();
    std::vector<std::vector<Tile>& getTiles();
    void generateDungeon(); //change this later when have the procedural stuff intergrated
    bool isLeaf() const;
    void generateRoom();
    void connectRooms(DungeonGenerator* other);
    bool split(int min_size);
    void getRoom() const;
private:
    struct Rect {
        int x { 0 }, y { 0 }, w { 0 }, h { 0 }
    };
    std::vector<std::vector<Tile>> tiles;
    Rect area;
    Rect room;
    DungeonGenerator* left { nullptr };
    DungeonGenerator* right { nullptr };
    bool has_room { false };
    int randomInt(int min, int max);
    void createBetweenRooms(int x1, int y1, int x2, int y2);

}

#endif