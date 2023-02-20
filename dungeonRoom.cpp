//
// Created by seans on 2/2/2023.
//

#include "dungeonRoom.h"

DungeonRoom::DungeonRoom() {

}

DungeonRoom::DungeonRoom(string name, dungeonRoomSize roomSize, renderInformation renderInfo) {
    this->name = name;
    this->roomSize = roomSize;
    this->renderInfo = renderInfo;
}

string DungeonRoom::getName() {
    return name;
}

dungeonRoomSize DungeonRoom::getRoomSize() {
    return roomSize;
}

renderInformation DungeonRoom::getRenderInfo() {
    return renderInfo;
}

DungeonRoom *DungeonRoom::getNorthRoom() {
    return northRoom;
}

DungeonRoom *DungeonRoom::getEastRoom() {
    return eastRoom;
}

DungeonRoom *DungeonRoom::getSouthRoom() {
    return southRoom;
}

DungeonRoom *DungeonRoom::getWestRoom() {
    return westRoom;
}

void DungeonRoom::setName(std::string name) {
    this->name = name;
}

void DungeonRoom::setRoomSize(dungeonRoomSize roomSize) {
    this->roomSize = roomSize;
}

void DungeonRoom::setRenderInfo(renderInformation renderInfo) {
    this->renderInfo = renderInfo;
}

void DungeonRoom::setNorthRoom(DungeonRoom *northRoom) {
    this->northRoom = northRoom;
}

void DungeonRoom::setEastRoom(DungeonRoom *eastRoom) {
    this->eastRoom = eastRoom;
}

void DungeonRoom::setSouthRoom(DungeonRoom *southRoom) {
    this->southRoom = southRoom;
}

void DungeonRoom::setWestRoom(DungeonRoom *westRoom) {
    this->westRoom = westRoom;
}
