#include <iostream>
#include <string>

class Fish {
private:
    int id;
    std::string name;
    std::string color;
    std::string characteristic;

public:
    Fish() : id(0), name("Unknown"), color("Unknown"), characteristic("None") {}

    Fish(int id) : id(id), name("Unknown"), color("Unknown"), characteristic("None") {}

    Fish(int id, std::string name) 
        : id(id), name(name), color("Unknown"), characteristic("None") {}

    Fish(int id, std::string name, std::string color) 
        : id(id), name(name), color(color), characteristic("None") {}

    Fish(int id, std::string name, std::string color, std::string characteristic) 
        : id(id), name(name), color(color), characteristic(characteristic) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    std::string getCharacteristic() const { return characteristic; }

    void setId(int id) { this->id = id; }
    void setName(std::string n) { name = n; }
    void setColor(std::string c) { color = c; }
    void setCharacteristic(std::string ch) { characteristic = ch; }

    void displayFishInfo() const {
        std::cout << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Color: " << color << "\n"
                  << "Characteristic: " << characteristic << "\n"
                  << "-----------------------------\n";
    }
};

int main() {
    Fish fish1;
    Fish fish2(2, "Clownfish", "Orange/White");
    Fish fish3(3, "Turtle", "Green");
    Fish fish4(4, "Great White Shark", "Grey/White");
    Fish fish5(5, "Betta", "Red/Blue", "Aggressive towards same species");

    std::cout << "=== INITIAL ALL 5 FISH OBJECTS ===\n\n";
    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();
    fish5.displayFishInfo();

    fish1.setId(1);
    fish1.setName("Discus");
    fish1.setColor("Turquoise");
    fish1.setCharacteristic("Requires warm, clean water and peaceful tankmates");

    std::cout << "=== RETRIEVING UPDATED FISH 1 DETAILS USING GETTERS ===\n";
    std::cout << "Retrieved ID: " << fish1.getId() << "\n";
    std::cout << "Retrieved Name: " << fish1.getName() << "\n";
    std::cout << "Retrieved Color: " << fish1.getColor() << "\n";
    std::cout << "Retrieved Characteristic: " << fish1.getCharacteristic() << "\n";
    std::cout << "-----------------------------\n\n";

    std::cout << "=== VERIFYING FISH 1 CHANGES WITH displayFishInfo() ===\n";
    fish1.displayFishInfo();

    return 0;
}