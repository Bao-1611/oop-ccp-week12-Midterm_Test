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
    Category() : categoryId(0), categoryName("Uncategorized"), description("None") {}
    Category(int id, std::string name, std::string desc) 
        : categoryId(id), categoryName(name), description(desc) {}

    int getCategoryId() const { return categoryId; }
    std::string getCategoryName() const { return categoryName; }
    std::string getDescription() const { return description; }

    void setCategoryId(int id) { categoryId = id; }
    void setCategoryName(const std::string& name) { categoryName = name; }
    void setDescription(const std::string& desc) { description = desc; }

    void displayCategoryInfo() const {
        std::cout << "Category ID: " << categoryId << "\n"
                  << "Category Name: " << categoryName << "\n"
                  << "Description: " << description << "\n"
                  << "-----------------------------\n";
    }
};

class Fish {
private:
    int id;
    std::string name;
    std::string color;
    std::string characteristic;
    int categoryId; 

public:
    Fish() 
        : id(0), name("Unknown"), color("Unknown"), characteristic("None"), categoryId(0) {}

    Fish(int id) 
        : id(id), name("Unknown"), color("Unknown"), characteristic("None"), categoryId(0) {}

    Fish(int id, std::string name) 
        : id(id), name(name), color("Unknown"), characteristic("None"), categoryId(0) {}

    Fish(int id, std::string name, std::string color) 
        : id(id), name(name), color(color), characteristic("None"), categoryId(0) {}

    Fish(int id, std::string name, std::string color, std::string characteristic) 
        : id(id), name(name), color(color), characteristic(characteristic), categoryId(0) {}

    Fish(int id, std::string name, std::string color, std::string characteristic, int categoryId) 
        : id(id), name(name), color(color), characteristic(characteristic), categoryId(categoryId) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    std::string getCharacteristic() const { return characteristic; }
    int getCategoryId() const { return categoryId; } 

    void setId(int id) { this->id = id; }
    void setName(const std::string& n) { name = n; }
    void setColor(const std::string& c) { color = c; }
    void setCharacteristic(const std::string& ch) { characteristic = ch; }
    void setCategoryId(int catId) { categoryId = catId; } 

    void displayFishInfo() const {
        std::cout << "ID: " << id << "\n"
                  << "Name: " << name << "\n"
                  << "Color: " << color << "\n"
                  << "Characteristic: " << characteristic << "\n"
                  << "Category ID: " << categoryId << "\n" 
                  << "-----------------------------------------\n";
    }
};

int main() {
    Fish fish1(1, "Discus", "Blue", "Requires warm, clean water", 101);
    Fish fish2(2, "Betta", "Red", "Aggressive towards same species", 102);
    Fish fish3(3, "Goldfish", "Orange", "Coldwater, peaceful", 103);

    std::cout << "=== FISH INFORMATION WITH CATEGORY ID ===\n\n";
    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();

    std::cout << "Updating Fish 1's Category ID using setter...\n";
    fish1.setCategoryId(105);
    std::cout << "New Category ID via Getter: " << fish1.getCategoryId() << "\n\n";

    fish1.displayFishInfo();

    return 0;
}