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
                  << "Characteristics: " << characteristic << "\n"
                  << "-----------------------------\n";
    }
};

int main() {
    Fish fish1(1, "Betta", "Red/Blue", "Aggressive towards same species");
    Fish fish2(2, "Goldfish", "Orange", "Peaceful");

    std::cout << "=== Ornamental Fish Details ===\n\n";
    
    fish1.displayFishInfo();
    fish2.displayFishInfo();

    return 0;
}