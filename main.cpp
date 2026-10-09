#include <iostream>
#include <string>

class Fish {
private:
    int id;
    std::string name;
    std::string color;
    std::string characteristic;

public:
    Fish() : id(0), name(""), color(""), characteristic("") {}

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
    Fish betta(1, "Betta", "Red/Blue", "Aggressive towards same species");
    Fish goldfish(2, "Goldfish", "Orange", "Peaceful");

    betta.display();
    goldfish.display();

    return 0;
}