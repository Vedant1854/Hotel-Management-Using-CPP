#include <iostream>
using namespace std;

const int MAX_ROOMS = 50;

enum RoomStatus { AVAILABLE, OCCUPIED, RESERVED };
enum RoomType { AC, NON_AC };

class Room 
{
public:
    Room(int number) : number(number), status(AVAILABLE), type(NON_AC) {}
    int getNumber() const { return number; }
    RoomStatus getStatus() const { return status; }
    RoomType getType() const { return type; }
    void reserve() { status = RESERVED; }
    void checkIn() { status = OCCUPIED; }
    void checkOut() { status = AVAILABLE; }
    void toggleAC() { type = (type == AC) ? NON_AC : AC; }
private:
    int number;
    RoomStatus status;
    RoomType type;
};

class Hotel {
public:
    Hotel() {
        for (int i = 0; i < MAX_ROOMS; i++) {
            rooms[i] = new Room(i + 1);
        }
    }
    ~Hotel() {
        for (int i = 0; i < MAX_ROOMS; i++) {
            delete rooms[i];
        }
    }
    void displayRooms() const {
        cout << "Rooms in the hotel:\n";
        for (int i = 0; i < MAX_ROOMS; i++) {
            cout << "Room " << rooms[i]->getNumber() << ": ";
            if (rooms[i]->getStatus() == AVAILABLE) {
                cout << "Available, ";
            } else if (rooms[i]->getStatus() == OCCUPIED) {
                cout << "Occupied, ";
            } else if (rooms[i]->getStatus() == RESERVED) {
                cout << "Reserved, ";
            }
            if (rooms[i]->getType() == AC) {
                cout << "AC\n";
            } else {
                cout << "Non-AC\n";
            }
        }
    }
    void bookRoom(int roomNumber) {
        Room* room = rooms[roomNumber - 1];
        if (room->getStatus() == AVAILABLE) {
            room->reserve();
            cout << "Room " << roomNumber << " reserved successfully.\n";
        } else {
            cout << "Room " << roomNumber << " is not available.\n";
        }
    }
    void checkIn(int roomNumber) {
        Room* room = rooms[roomNumber - 1];
        if (room->getStatus() == RESERVED) {
            room->checkIn();
            cout << "Room " << roomNumber << " checked in successfully.\n";
        } else {
            cout << "Room " << roomNumber << " cannot be checked in.\n";
        }
    }
    void checkOut(int roomNumber) {
        Room* room = rooms[roomNumber - 1];
        if (room->getStatus() == OCCUPIED) {
            room->checkOut();
            cout << "Room " << roomNumber << " checked out successfully.\n";
        } else {
            cout << "Room " << roomNumber << " cannot be checked out.\n";
        }
    }
    void toggleAC(int roomNumber) {
        Room* room = rooms[roomNumber - 1];
        room->toggleAC();
        if (room->getType() == AC) {
            cout << "Room " << roomNumber << " now has AC.\n";
        } else {
            cout << "Room " << roomNumber << " now does not have AC.\n";
        }
    }
private:
    Room* rooms[MAX_ROOMS];
};

int main() {
    Hotel hotel;
    int choice, roomNumber;

    while (true) {
        cout << "\nHotel Management System\n";
        cout << "-----------------------\n";
        cout << "1. Display Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Check In\n";
        cout << "4. Check Out\n";
        cout << "5. Toggle AC\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;
            case 2:
                cout << "Enter the room number: ";
                cin >> roomNumber;
                hotel.bookRoom(roomNumber);
                break;
            case 3:
                cout << "Enter the room number: ";
                cin >> roomNumber;
                hotel.checkIn(roomNumber);
                break;
            case 4:
                cout << "Enter the room number: ";
                cin >> roomNumber;
                hotel.checkOut(roomNumber);
                break;
            case 5:
                cout << "Enter the room number: ";
                cin >> roomNumber;
                hotel.toggleAC(roomNumber);
                break;
            case 6:
                cout << "Thank you for using the system!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
