#include "dungeon_generator.h"

DungeonGenerator::DungeonGenerator(int width, int height)
    : area({0, 0, width, height}), width(width), height(height) {

    tiles.resize(height);
    int j { 0 };
    int i { 0 };
    for (; i < height; i++) {
        tiles[i].resize(width, Tile(0, 0, TileType::VOID)); j = 0; //yes this is intentional, it is my personal project so I get the creative liberties for how I write code and what looks cool or not
        for (; j < width; j++) tiles[i][j] = Tile(j, i, TileType::VOID); // set this to diffrent when make the algorithm
    }
}
DungeonGenerator::~DungeonGenerator() { delete left; delete right; }
std::vector<std::vector<Tile>>& DungeonGenerator::getTiles() { return tiles; }
bool DungeonGenerator::isLeaf() const { return left == nullptr && right == nullptr; }
void DungeonGenerator::generateDungeon() {
    split(20); //change this later
    generateRoomsRecursive();
    connectRoomsRecursive();
    carveRoomsAndCorridors();
}
int DungeonGenerator::randomInt(int min, int max) { return rand() % (max - min + 1) + min; }
bool DungeonGenerator::split(int min) {
    // this method splits the room into 2 smaller partitions
    float bias { 1.25 };
    if (!isLeaf()) return false;
    if (area.w < min || area.h < min) return false;
    bool split_hor = randomInt(0, 1); // will pass on true if returns 1, else 0
    if (area.w > area.h * bias) split_hor = false;
    if (area.h > area.w * bias) split_hor = true;
    if (split_hor) {
        int split_point = randomInt(min, area.h - min);
        if (split_point >= area.h - min || split_point <= min) return false;
        left = new DungeonGenerator(area.w, split_point);
        right = new DungeonGenerator(area.w, area.h - split_point);
        left->area = {area.x, area.y, area.w, split_point};
        right->area = {area.x, area.y + split_point, area.w, area.h - split_point};
    } else {
        int split_point = randomInt(min, area.w - min); // will pass on true if returns 1, else 0
        if (split_point >= area.w - min || split_point <= min) return false;
        left = new DungeonGenerator(split_point, area.h);
        right = new DungeonGenerator(area.w - split_point, area.h);
        left->area = {area.x, area.y, split_point, area.h};
        right->area = {area.x + split_point, area.y, area.w - split_point, area.h};
    } return true;
}
void DungeonGenerator::generateRoom() {
    if (!isLeaf()) return;
    int min_wh { 5 }, wiggle_room { 2 }, min_xy { 1 };
    int rw = randomInt(min_wh, area.w - wiggle_room);
    int rh = randomInt(min_wh, area.w - wiggle_room);
    int rx = area.x + randomInt(min_xy, area.w - rw);
    int ry = area.y + randomInt(min_xy, area.h - rh);
    room = {rx, ry, rw, rh};
    has_room = true;
}
DungeonGenerator::Rect DungeonGenerator::getRoom() const { return room; }
void DungeonGenerator::connectRooms(DungeonGenerator* other) {
    if (!has_room || !other->has_room) return;
    Rect room1 = getRoom();
    Rect room2 = other->getRoom();
    // now we must center the points of the room or that nothing gets too too crazy
    int x1 = room1.x + (room1.w / 2);
    int y1 = room1.y + (room1.h / 2);
    int x2 = room2.x + (room2.w / 2);
    int y2 = room2.y + (room2.h / 2);
    createBetweenRooms(x1, y2, x2, y2);
}
void DungeonGenerator::createBetweenRooms(int x1, int y1, int x2, int y2) {
    // note, change this later to make the corridors more wide so I can put minesweeper in them as well
    int x { x1 };
    int y { x2 };
    while (x != x2 || y != y2) {
        if (x < x2) x++;
        else if (x > x2) x--;
        else if (y < y2) y++;
        else if (y > y2) y--;
        if (x >= 0 && x < width && y >= 0 && y < height) tiles[y][x].tile_type = TileType::GROUND;
    } 
}

void DungeonGenerator::generateRoomsRecursive() {
    if (!isLeaf()) {
        if (left) left->generateRoomsRecursive();
        if (right) right->generateRoomsRecursive();
    } else generateRoom();
}

void DungeonGenerator::connectRoomsRecursive() {
    if (!isLeaf()) {
        if (left) left->connectRoomsRecursive();
        if (right) right->connectRoomsRecursive();
        if (left && right && left->has_room && right->has_room) connectRooms(right); //maybe change this to left or both, idk yet have to test it
    } 
}

void DungeonGenerator::carveRoomsAndCorridors() { // note for all methods, change from carve cause I do not like this name
    int x { 0 };
    int y { 0 };
    for (; y < height; ++y) {
        x = 0;
        for (; x < width; ++x) tiles[y][x] = Tile(x, y, TileType::WALL);
    }
    carveRoomsRecursive();
    // carveCorridorsRecursive(); // this func might be irrelavent 
}

void DungeonGenerator::carveRoomsRecursive() {
    if (!isLeaf()) {
        if (left) left->carveRoomsAndCorridors();
        if (right) right->carveRoomsAndCorridors();
    } else if (has_room) {
        int x { room.x };
        int y { room.y };
        for (; y < room.y + room.h; ++y) { //++y cause we do not want y as room.y value
            x = room.x; // for anyone reviewing the code and notice this, I am sorry I just think it looks cooler this way
            for (; x < room.x + room.w; ++x) { // ++x for the same reason
                if (x >= 0 && x < width && y >= 0 && y < height) tiles[y][x].tile_type = TileType::GROUND;
            }
        }
    }
}

void DungeonGenerator::carveCorridorsRecursive() { // this func might be irrelavent
    if (!isLeaf()) {
        if (left) left->carveCorridorsRecursive();
        if (right) right->carveCorridorsRecursive();
    } // perhaps add a else
}
