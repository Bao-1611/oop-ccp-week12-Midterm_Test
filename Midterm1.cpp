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
    void setName(const std::string& name) { this->name = name; }
    void setColor(const std::string& color) { this->color = color; }
    void setCharacteristic(const std::string& characteristic) { this->characteristic = characteristic; }

    void display() const {
        std::cout << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Color: " << color << "\n"
                  << "Characteristic: " << characteristic << "\n"
                  << "-----------------------------\n";
    }
};

int main() {
    Fish fish1(1);
    Fish fish2(2, "Clown Fish");
    Fish fish3(3, "Turtle", "Green");
    Fish fish4(4, "Great White Shark", "White", "Top predator");
    Fish fish5(5, "Betta", "Red/Blue", "Aggressive towards same species");

    std::cout << "=== Testing Overloaded Constructors ===\n\n";
    fish1.display();
    fish2.display();
    fish3.display();
    fish4.display();
    fish5.display();

    return 0;
}