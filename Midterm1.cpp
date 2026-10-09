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


    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    std::string getColor() const {
        return color;
    }

    std::string getCharacteristic() const {
        return characteristic;
    }


    void setId(int id) {
        this->id = id;
    }

    void setName(std::string n) {
        name = n;
    }

    void setColor(std::string c) {
        color = c;
    }

    void setCharacteristic(std::string ch) {
        characteristic = ch;
    }


    void display() const {
        std::cout << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Color: " << color << "\n"
                  << "Characteristic: " << characteristic << "\n"
                  << "-----------------------------\n";
    }
};

int main() {
    Fish fish1;
    std::cout << "=== Default Fish1 before Setters ===\n";
    fish1.display();

    fish1.setId(101);
    fish1.setName("Guppy");
    fish1.setColor("Rainbow");
    fish1.setCharacteristic("Peaceful surface swimmer");

    std::cout << "=== Fish1 after Setters ===\n";
    fish1.display();

    std::cout << "=== Testing Getters for Fish1 ===\n";
    std::cout << "Retrieved Name: " << fish1.getName() << "\n";
    std::cout << "Retrieved Color: " << fish1.getColor() << "\n";

    return 0;
}