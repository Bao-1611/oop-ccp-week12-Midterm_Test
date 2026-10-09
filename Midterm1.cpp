#include <iostream>
#include <string>
#include <vector>


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
        std::cout << "Category ID: " << categoryId << "\n"
                  << "Name       : " << categoryName << "\n"
                  << "Description: " << description << "\n"
                  << "-----------------------------------------\n";
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
        std::cout << "ID            : " << id << "\n"
                  << "Name          : " << name << "\n"
                  << "Color         : " << color << "\n"
                  << "Characteristic: " << characteristic << "\n"
                  << "Category ID   : " << categoryId << "\n"
                  << "-----------------------------------------\n";
    }
};

int main() {
    std::vector<Category> categories = {
        Category(101, "Cichlids", "Intelligent and territorial tropical freshwater fish"),
        Category(102, "Anabantoids", "Labyrinth breathers that can take air from the surface"),
        Category(103, "Cyprinids", "Hardy freshwater fish including Barbs, Danios, and Goldfish")
    };

    std::vector<Fish> fishList = {
        Fish(1, "Discus", "Blue", "Requires warm, clean water", 101),
        Fish(2, "Angel Fish", "Silver", "Striped body, elegant swimmer", 101),
        Fish(3, "Betta", "Red", "Aggressive towards same species", 102),
        Fish(4, "Gourami", "Blue", "Calm labyrinth breather", 102),
        Fish(5, "Goldfish", "Orange", "Coldwater, peaceful", 103),
        Fish(6, "Cherry Barb", "Red", "Schooling fish, vibrant color", 103)
    };

    std::cout << "=========================================\n";
    std::cout << "          AVAILABLE CATEGORIES           \n";
    std::cout << "=========================================\n";
    for (const auto& category : categories) {
        category.displayCategoryInfo();
    }

    int selectedCategoryId = 102; 

    std::cout << "\n=========================================\n";
    std::cout << "   DISPLAYING FISH IN CATEGORY ID: " << selectedCategoryId << "\n";
    std::cout << "=========================================\n";

    bool found = false;
    for (const auto& fish : fishList) {
        if (fish.getCategoryId() == selectedCategoryId) {
            fish.displayFishInfo();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No fish found for Category ID " << selectedCategoryId << ".\n";
    }

    return 0;
}