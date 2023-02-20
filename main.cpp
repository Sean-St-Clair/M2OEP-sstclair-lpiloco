#include <iostream>
#include <sstream>
#include <vector>
#include "dungeonRoom.h"

using namespace std;

// This function takes a string and returns true if and only if it contains any whitespace characters
bool stringContainsSpace(string input);

// This function prompts a user for input until a valid integer within the range is entered
int getIntFromUser(string prompt, int range);

// This function prompts a user for input until a valid word is entered
string getWordFromUser(string prompt);

// This function prompts a user for input until a valid single character is entered
char getCharFromUser(string prompt);

// Prompts the user for input to create a room and displays it in the console
DungeonRoom createRoom(vector<DungeonRoom> &dungeon);

// Prompts the user to select two rooms to "link" together so that each room will have pointers to each other
void linkRooms(vector<DungeonRoom> &dungeon);

// Takes a string and returns a vector of substrings split by the given delimiter
vector<string> splitString(string input, char delimiter);

// Prints out a list of all the rooms, with added numbers
void printRooms(vector<DungeonRoom> &dungeon);

// Prints an ascii visual of the created dungeon.
void displayDungeon(vector<DungeonRoom> &dungeon, int dungeonRowWidth);

// Testing some basic functionality without yet doing input validation
int main() {
    // This vector represents the rooms in the dungeon, which will be split into rows by the renderer
    vector<DungeonRoom> dungeon;
    int dungeonRowWidth = 6;

    // Prompts the user to select from the builder menu
    cout << "Welcome to Dungeon Builder!";
    string prompt = "What would you like to do?"
                    "\n[1] - Create new room"
                    "\n[2] - Link two rooms together"
                    "\n[3] - Display dungeon"
                    "\n[4] - Quit\n";
    int response = -1;

    // Handles each case with a separate function
    while (response != 4) {
        response = getIntFromUser(prompt, 4);
        switch (response) {
            case 1:
                dungeon.push_back(createRoom(dungeon));
                printRooms(dungeon);
                break;
            case 2:
                if (dungeon.size() >= 2) {
                    linkRooms(dungeon);
                } else cout << "At least 2 rooms must exist before linking!" << endl;
                break;
            case 3:
                displayDungeon(dungeon, dungeonRowWidth);
                break;
        }
    }
    cout << "Thank you for using Dungeon Builder! Your finished dungeon: " << endl;
    // Prints an ascii visual of the finished dungeon
    displayDungeon(dungeon, dungeonRowWidth);
    return 0;
}

int getIntFromUser(string prompt, int range) {
    string input;
    string excess;
    stringstream ss;
    int num;
    ss.clear();
    ss.str("");

    // Uses a string stream to process input into num
    cout << prompt;
    getline(cin, input);
    ss.str(input);
    ss >> num;

    // Checks whether the string stream could properly read from the whole string to an integer
    while (input.length() < 1 || ss.fail() || ss.peek() != EOF || num < 1 || num > range) {
        if (input.length() < 1) {
            cout << "No input. ";
        } else if (num < 1 || num > range) {
            cout << "Number not within range. ";
        } else {
            cout << "Invalid input. ";
        }
        ss.clear();
        excess = "";

        // Re-prompts user for input
        cout << prompt;
        getline(cin, input);
        ss.str(input);
        ss >> num;
    }
    return num;
}

bool stringContainsSpace(string input) {
    for (int i = 0; i < input.length(); i++)
        if (isspace(input[i]))
            return true;
    return false;
}

string getWordFromUser(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);

    // Re-prompts user for input if it contains any whitespace characters
    while (input.length() < 1 || stringContainsSpace(input)) {
        if (input.length() < 1)
            cout << "No input. ";
        else cout << "Invalid input. ";
        cout << prompt;
        getline(cin, input);
    }
    return input;
}

char getCharFromUser(string prompt) {
    string input;
    cout << prompt;
    getline(cin, input);

    // Re-prompts user for input if more or less than 1 character is entered
    while (input.length() != 1) {
        if (input.length() < 1)
            cout << "No input. ";
        else cout << "Invalid input. ";
        cout << prompt;
        getline(cin, input);
    }
    return input[0];
}

DungeonRoom createRoom(vector<DungeonRoom> &dungeon) {
    DungeonRoom room;
    cout << "Creating room!" << endl;

    // Prompts the user for the room name
    string prompt = "What is the name of this room?\n";
    string name = getWordFromUser(prompt);

    // Prompts the user for the size and matches it to a dungeonRoomSize enum
    prompt = "What is the size of this room?"
             "\n[1] - Small"
             "\n[2] - Medium"
             "\n[3] - Large\n";
    int response = getIntFromUser(prompt, 3);
    dungeonRoomSize roomSize;
    switch (response) {
        case 1:
            roomSize = SMALL;
            break;
        case 2:
            roomSize = MEDIUM;
            break;
        case 3:
            roomSize = LARGE;
            break;
        default:
            cout << "Invalid response: " << response << endl;
            roomSize = LARGE;
            break;
    }

    // Asks the user to enter visual rendering information for the room
    prompt = "What character will the room use for the wall?\n";
    char wall = getCharFromUser(prompt);
    prompt = "What character will the room use for the ceiling?\n";
    char ceiling = getCharFromUser(prompt);
    prompt = "What character will the room use for the floor? (whitespace is ok)\n";
    char floor = getCharFromUser(prompt);
    prompt = "What character will the room use for added detail?\n";
    char detail = getCharFromUser(prompt);
    renderInformation renderInfo{
            wall,
            ceiling,
            floor,
            detail
    };

    room = DungeonRoom(name, roomSize, renderInfo);
    cout << "Room " << name << " is complete!" << endl;
    cout << room.generateRoomVisuals() << endl;
    return room;
}

void linkRooms(vector<DungeonRoom> &dungeon) {
    printRooms(dungeon);
    string prompt = "Enter the number of the first room to link.\n";
    int room1Index = getIntFromUser(prompt, dungeon.size());
    prompt = "Enter the number of the second room to link.\n";
    int room2Index = getIntFromUser(prompt, dungeon.size());
    prompt = "Where will the second room be placed with respect to the first?"
             "\n[1] - North"
             "\n[2] - East"
             "\n[3] - South"
             "\n[4] - West\n";
    int direction = getIntFromUser(prompt, 4);

    DungeonRoom *room1Ptr = &dungeon[room1Index];
    DungeonRoom *room2Ptr = &dungeon[room2Index];
    switch (direction) {
        case 1:
            // North
            dungeon[room1Index].setNorthRoom(room2Ptr);
            dungeon[room2Index].setSouthRoom(room1Ptr);
            break;
        case 2:
            // East
            dungeon[room1Index].setEastRoom(room2Ptr);
            dungeon[room2Index].setWestRoom(room1Ptr);
        case 3:
            // South
            dungeon[room1Index].setSouthRoom(room2Ptr);
            dungeon[room2Index].setNorthRoom(room1Ptr);
            break;
        case 4:
            // West
            dungeon[room1Index].setWestRoom(room2Ptr);
            dungeon[room2Index].setEastRoom(room1Ptr);
            break;
        default:
            cout << "Unexpected direction: " << direction << endl;
            break;
    }
    cout << "Linking complete!" << endl;
}

vector<string> splitString(string input, char delimiter) {
    vector<string> splitVector;
    int startIndex = 0;
    for (int i = 0; i <= input.size(); i++) {
        if (input[i] == delimiter || i == input.size()) {
            string subString = input.substr(startIndex, i - startIndex);
            splitVector.push_back(subString);
            startIndex = i + 1;
        }
    }
    return splitVector;
}

void printRooms(vector<DungeonRoom> &dungeon) {
    cout << "Current rooms: ";
    for (int i = 0; i < dungeon.size(); i++) {
        cout << "[" << (i + 1) << "]" << dungeon[i].getName();
        if (i < dungeon.size() - 1)
            cout << ", ";
    }
    cout << endl;
}

void displayDungeon(vector<DungeonRoom> &dungeon, int dungeonRowWidth) {
    // A default room for testing
    string defaultRoom = "--------------"
                         "\n|            |"
                         "\n|            |"
                         "\n|            |"
                         "\n|            |"
                         "\n|            |"
                         "\n--------------";
    // Split the room string by its newline characters in order to print several side-by-side.
    vector<string> split = splitString(defaultRoom, '\n');
//    char emptySpace = ' ';

    // Testing variables - will likely be user-specified
    int dungeonWidth = 6;
    int dungeonHeight = 4;
    // Print several rows of rooms on top of each other
    for (int i = 0; i < dungeonHeight; i++) {
        // Print several rooms next to each other in a single row
        for (int e = 0; e < split.size(); e++) {
            for (int w = 0; w < dungeonWidth; w++)
                cout << split[e] << " ";
            cout << endl;
        }
    }

    for (DungeonRoom room: dungeon)
        cout << room.generateRoomVisuals() << endl;
}