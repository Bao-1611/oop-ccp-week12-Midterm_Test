#include <iostream>
#include <string>
#include <vector>
#include <map>

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
    Fish fish5(5, "Betta", "Red", "Aggressive towards same species");

    fish1.setId(1);
    fish1.setName("Discus");
    fish1.setColor("Blue");
    fish1.setCharacteristic("Requires warm, clean water");

    std::vector<Fish> fishList = { fish1, fish2, fish3, fish4, fish5 };

    fishList.push_back(Fish(6, "Goldfish", "Orange", "Coldwater, hardy"));
    fishList.push_back(Fish(7, "Angel Fish", "Silver", "Striped body, elegant swimmer"));
    fishList.push_back(Fish(8, "Platy", "Orange", "Peaceful livebearer"));
    fishList.push_back(Fish(9, "Red Tail Shark", "Black", "Territorial bottom dweller"));
    fishList.push_back(Fish(10, "Cherry Barb", "Red", "Schooling fish, vibrant male colors"));
    fishList.push_back(Fish(11, "Black Tetra", "Black", "Active swimmer, peaceful"));
    fishList.push_back(Fish(12, "Gourami", "Blue", "Labyrinth breathers, calm"));
    fishList.push_back(Fish(13, "Molly", "Black", "Adaptable, livebearer"));
    fishList.push_back(Fish(14, "Zebra Danio", "Silver", "Fast swimmer, striped pattern"));
    fishList.push_back(Fish(15, "Clown Loach", "Orange", "Bottom feeder, distinctive stripes"));

    std::map<std::string, std::vector<Fish>> groupedByColor;

    for (const auto& fish : fishList) {
        groupedByColor[fish.getColor()].push_back(fish);
    }

    std::cout << "===========================================\n";
    std::cout << "      ORNAMENTAL FISH GROUPED BY COLOR      \n";
    std::cout << "===========================================\n\n";

    for (const auto& entry : groupedByColor) {
        std::string colorGroup = entry.first;
        const std::vector<Fish>& fishesInGroup = entry.second;

        std::cout << ">>> COLOR GROUP: " << colorGroup << " (" << fishesInGroup.size() << " fish) <<<\n";
        std::cout << "-------------------------------------------\n";

        for (const auto& fish : fishesInGroup) {
            std::cout << "  - [ID: " << fish.getId() << "] " 
                      << fish.getName() 
                      << " | Characteristic: " << fish.getCharacteristic() << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}