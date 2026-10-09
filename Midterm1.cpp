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

    Category(int id) 
        : categoryId(id), categoryName("Uncategorized"), description("None") {}

    Category(int id, std::string name) 
        : categoryId(id), categoryName(name), description("None") {}

    Category(int id, std::string name, std::string desc) 
        : categoryId(id), categoryName(name), description(desc) {}

    int getCategoryId() const { 
        return categoryId; 
    }

    std::string getCategoryName() const { 
        return categoryName; 
    }

    std::string getDescription() const { 
        return description; 
    }

    void setCategoryId(int id) { 
        categoryId = id; 
    }

    void setCategoryName(const std::string& name) { 
        categoryName = name; 
    }

    void setDescription(const std::string& desc) { 
        description = desc; 
    }

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
    void setName(const std::string& n) { name = n; }
    void setColor(const std::string& c) { color = c; }
    void setCharacteristic(const std::string& ch) { characteristic = ch; }
    void setCategory(const Category& cat) { category = cat; }

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
    Category catDefault; 
    Category cat1(1, "Cichlids", "Intelligent & territorial tropical fish");
    Category cat2(2, "Anabantoids", "Labyrinth breathers (Bettas, Gouramis)");
    Category cat3(3, "Cyprinids", "Hardy freshwater schooling fish");

    std::cout << "=== TESTING CATEGORY METHODS ===\n";
    std::cout << "Default Category before setters:\n";
    catDefault.displayCategoryInfo();

    catDefault.setCategoryId(4);
    catDefault.setCategoryName("Catfish");
    catDefault.setDescription("Bottom-feeding freshwater fish with barbels");

    std::cout << "Updated Category using setters:\n";
    catDefault.displayCategoryInfo();

    std::cout << "Retrieved via Getters -> Name: " << cat1.getCategoryName() 
              << " | ID: " << cat1.getCategoryId() << "\n\n";

    Fish fish1(1, "Discus", "Blue", "Requires warm, clean water", cat1);
    Fish fish2(2, "Betta", "Red", "Aggressive towards same species", cat2);
    Fish fish3(3, "Goldfish", "Orange", "Coldwater, peaceful", cat3);

    std::cout << "=== FISH WITH LINKED CATEGORIES ===\n\n";
    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();

    return 0;
}