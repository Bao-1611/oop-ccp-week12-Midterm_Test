#include <iostream>
#include <string>
#include <vector>
#include <map>

class Category {
private:
    int categoryId;
    std::string categoryName;
    std::string description;

public:
    Category() 
        : categoryId(0), categoryName("Uncategorized"), description("None") {}

    Category(int id, std::string name, std::string desc) 
        : categoryId(id), categoryName(name), description(desc) {}

    int getCategoryId() const { return categoryId; }
    std::string getCategoryName() const { return categoryName; }
    std::string getDescription() const { return description; }

    void setCategoryId(int id) { categoryId = id; }
    void setCategoryName(const std::string& name) { categoryName = name; }
    void setDescription(const std::string& desc) { description = desc; }

    void displayCategoryInfo() const {
        std::cout << "Category [" << categoryId << "]: " << categoryName 
                  << " | " << description << "\n";
    }
};

class Fish {
private:
    int id;
    std::string name;
    std::string color;
    std::string characteristic;
    Category category;

public:
    Fish() 
        : id(0), name("Unknown"), color("Unknown"), characteristic("None"), category() {}

    Fish(int id) 
        : id(id), name("Unknown"), color("Unknown"), characteristic("None"), category() {}

    Fish(int id, std::string name) 
        : id(id), name(name), color("Unknown"), characteristic("None"), category() {}

    Fish(int id, std::string name, std::string color) 
        : id(id), name(name), color(color), characteristic("None"), category() {}

    Fish(int id, std::string name, std::string color, std::string characteristic) 
        : id(id), name(name), color(color), characteristic(characteristic), category() {}

    Fish(int id, std::string name, std::string color, std::string characteristic, Category cat) 
        : id(id), name(name), color(color), characteristic(characteristic), category(cat) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    std::string getCharacteristic() const { return characteristic; }
    Category getCategory() const { return category; }

    void setId(int id) { this->id = id; }
    void setName(std::string n) { name = n; }
    void setColor(std::string c) { color = c; }
    void setCharacteristic(std::string ch) { characteristic = ch; }
    void setCategory(Category cat) { category = cat; }

    void displayFishInfo() const {
        std::cout << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Color: " << color << "\n"
                  << "Characteristic: " << characteristic << "\n"
                  << "Category: " << category.getCategoryName() << " (" << category.getDescription() << ")\n"
                  << "-----------------------------------------\n";
    }
};

int main() {
    Category catCichlids(1, "Cichlids", "Intelligent & territorial tropical fish");
    Category catAnabantoids(2, "Anabantoids", "Labyrinth breathers (Bettas, Gouramis)");
    Category catCyprinids(3, "Cyprinids", "Hardy freshwater schooling fish");

    Fish fish1(1, "Discus", "Blue", "Requires warm, clean water", catCichlids);
    Fish fish2(2, "Betta", "Red", "Aggressive towards same species", catAnabantoids);
    Fish fish3(3, "Goldfish", "Orange", "Coldwater, peaceful", catCyprinids);
    Fish fish4(4, "Angel Fish", "Silver", "Striped body, elegant swimmer", catCichlids);
    Fish fish5(5, "Gourami", "Blue", "Calm labyrinth breather", catAnabantoids);

    std::vector<Fish> fishList = { fish1, fish2, fish3, fish4, fish5 };

    std::cout << "=== ALL FISH WITH CATEGORIES ===\n\n";
    for (const auto& fish : fishList) {
        fish.displayFishInfo();
    }

    std::map<std::string, std::vector<Fish>> groupedByCategory;
    for (const auto& fish : fishList) {
        groupedByCategory[fish.getCategory().getCategoryName()].push_back(fish);
    }

    std::cout << "\n=========================================\n";
    std::cout << "      FISH GROUPED BY CATEGORY           \n";
    std::cout << "=========================================\n\n";

    for (const auto& entry : groupedByCategory) {
        std::cout << ">>> CATEGORY: " << entry.first << " <<<\n";
        for (const auto& fish : entry.second) {
            std::cout << "  - [ID: " << fish.getId() << "] " 
                      << fish.getName() << " (" << fish.getColor() << ")\n";
        }
        std::cout << "\n";
    }

    return 0;
}