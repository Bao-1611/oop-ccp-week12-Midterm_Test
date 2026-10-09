#include <iostream>
#include <string>
#include <vector>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(2026) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    std::string toString() const {
        return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
    }
};

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
    Fish() : id(0), name("Unknown"), color("Unknown"), characteristic("None"), categoryId(0) {}
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

class FishShop {
private:
    int id;
    std::string name;
    std::string address;
    std::string owner;
    Date startdate;
    std::vector<Category> categories;
    std::vector<Fish> fishes;

public:
    FishShop() 
        : id(0), name("Unknown Shop"), address("Unknown Address"), owner("Unknown Owner"), startdate() {}

    FishShop(int id, std::string name, std::string address, std::string owner, Date startdate)
        : id(id), name(name), address(address), owner(owner), startdate(startdate) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getOwner() const { return owner; }
    Date getStartDate() const { return startdate; }
    std::vector<Category> getCategories() const { return categories; }
    std::vector<Fish> getFishes() const { return fishes; }

    void setId(int id) { this->id = id; }
    void setName(const std::string& n) { name = n; }
    void setAddress(const std::string& addr) { address = addr; }
    void setOwner(const std::string& o) { owner = o; }
    void setStartDate(const Date& d) { startdate = d; }
    void setCategories(const std::vector<Category>& cats) { categories = cats; }
    void setFishes(const std::vector<Fish>& f) { fishes = f; }

    void addCategory(const Category& category) {
        categories.push_back(category);
    }

    void addFish(const Fish& fish) {
        fishes.push_back(fish);
    }


    void displayShopInfo() const {
        std::cout << "=========================================\n"
                  << "            FISH SHOP DETAILS            \n"
                  << "=========================================\n"
                  << "Shop ID   : " << id << "\n"
                  << "Shop Name : " << name << "\n"
                  << "Address   : " << address << "\n"
                  << "Owner     : " << owner << "\n"
                  << "Start Date: " << startdate.toString() << "\n"
                  << "Categories: " << categories.size() << " available\n"
                  << "Total Fish: " << fishes.size() << " in inventory\n"
                  << "-----------------------------------------\n";
    }

    void displayAllCategories() const {
        std::cout << "\n=== ALL CATEGORIES IN " << name << " ===\n";
        if (categories.empty()) {
            std::cout << "No categories added yet.\n";
            return;
        }
        for (const auto& category : categories) {
            category.displayCategoryInfo();
        }
    }

    void displayAllFishes() const {
        std::cout << "\n=== ALL FISH IN " << name << " INVENTORY ===\n";
        if (fishes.empty()) {
            std::cout << "No fish in inventory yet.\n";
            return;
        }
        for (const auto& fish : fishes) {
            fish.displayFishInfo();
        }
    }

    void displayFullShopDetails() const {
        displayShopInfo();
        displayAllCategories();
        displayAllFishes();
    }
};

int main() {
    FishShop shop;

    std::cout << "=== INITIAL DEFAULT SHOP ===\n";
    shop.displayShopInfo();

    shop.setId(5001);
    shop.setName("Ocean World Aquarium");
    shop.setAddress("456 Coral Reef Way");
    shop.setOwner("Alice Smith");
    shop.setStartDate(Date(10, 4, 2021));

    Category c1(101, "Cichlids", "Intelligent & territorial tropical fish");
    Category c2(102, "Anabantoids", "Labyrinth breathers (Bettas, Gouramis)");
    shop.addCategory(c1);
    shop.addCategory(c2);

    Fish f1(1, "Discus", "Blue", "Requires warm water", 101);
    Fish f2(2, "Betta", "Red", "Aggressive towards same species", 102);
    Fish f3(3, "Angel Fish", "Silver", "Striped body, calm swimmer", 101);
    shop.addFish(f1);
    shop.addFish(f2);
    shop.addFish(f3);

    std::cout << "\n=== TESTING GETTERS ===\n";
    std::cout << "Retrieved Shop Name : " << shop.getName() << "\n";
    std::cout << "Retrieved Owner     : " << shop.getOwner() << "\n";
    std::cout << "Retrieved Start Date: " << shop.getStartDate().toString() << "\n";
    std::cout << "Retrieved Fish Count: " << shop.getFishes().size() << "\n";

    std::cout << "\n=== TESTING FULL DISPLAY FUNCTION ===\n";
    shop.displayFullShopDetails();

    return 0;
}