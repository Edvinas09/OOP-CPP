/*
    Sukure: Edvinas Bagdonas, programu sistemu studentas, 1 kursas, 4 grupė

    Programa sukuria klase HotelRoom, kuri turi kintamuosius, metodus, konstruktrius ir destruktoriu. Main funkcijoje vienetu testais patikrinama ar klase veikia tinkamai.
*/


#include <iostream>
#include <sstream>
#include <assert.h>

using namespace std;

class HotelRoom
{
    
    private:
        static int nextID;
        int id;
        static int count;
        string roomType;
        int roomNumber;
        int pricePerNight;
    public:


    HotelRoom(int number)
    {
        roomNumber = number;
        roomType = "Single";
        pricePerNight = 0;
        id = nextID++;
        count++;
    };

    HotelRoom(string type, int number, int price)
    {
        roomType = type;
        roomNumber = number;
        pricePerNight = price;
        id = nextID++;
        count++;
    } 

    ~HotelRoom()
    {
        count--;
    }


    string getRoomType()
    {
        return roomType;
    }
    void setRoomType(string type)
    {
        roomType = type;
    }
    int getRoomNumber()
    {
        return roomNumber;
    }
    void setRoomNumber(int number)
    {
        try {
            if (number < 0) {
                throw invalid_argument("Price cannot be negative.");
            }
            roomNumber = number;
        } catch (invalid_argument& e) {
            cout << "Error in setRoomNumber: " << e.what() << endl;
        }
       
    }
    int getPricePerNight()
    {
        return pricePerNight;
    }
    void setPricePerNight(int price)
    {
        try {
            if (price < 0) {
                throw invalid_argument("Price cannot be negative.");
            }
            pricePerNight = price;
        } catch (invalid_argument& e) {
            cout << "Error in setPrice: " << e.what() << endl;
        }
    }

    string toString()
    {
        stringstream ss;
        ss << "ID: "<< id << ", Room number: "<< roomNumber << ", Room type: " << roomType << ", Price per night: " << pricePerNight;
        return ss.str();
    }

    int getId()
    {
        return id;
    }

    int getCount()
    {
        return count;
    }

};

int HotelRoom::nextID = 1;
int HotelRoom::count = 0;


int main(int argc, char const *argv[])
{
    HotelRoom room(10);

    HotelRoom* rooms[4] = {
        new HotelRoom("Lux", 3, 500),
        new HotelRoom("Suite",4, 200),
        new HotelRoom("Triple", 5, 30),
        new HotelRoom("Presidential", 6, 1000)
    };

    assert(room.getId() == 1);
    assert(room.getRoomType() == "Single");
    room.setRoomType("Double");
    assert(room.getRoomType() == "Double");
    assert(room.getRoomNumber() == 10);
    room.setRoomNumber(1);
    assert(room.getRoomNumber() == 1);
    assert(room.getPricePerNight() == 0);
    room.setPricePerNight(50);
    assert(room.getPricePerNight() == 50);
    
    assert(room.getCount() == 5);
    for(int i=0; i<4; i++)
    {
        assert(rooms[i]->getId()==i+2);
        assert(rooms[i]->getRoomNumber()==i+3);
        delete rooms[i];
    }
    assert(room.getCount() == 1);
    HotelRoom room7("Single", 7, 500);
    assert(room7.getId() == 6);

    assert(room.getCount() == 2);

    return 0;
}