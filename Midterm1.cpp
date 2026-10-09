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
};

int main() {
    Date openingDate(15, 6, 2022);
    FishShop shop(1001, "AquaParadise", "123 Main Street", "John Doe", openingDate);

    shop.addCategory(Category(101, "Cichlids", "Intelligent freshwater fish"));
    shop.addCategory(Category(102, "Anabantoids", "Labyrinth breathers"));

    shop.addFish(Fish(1, "Discus", "Blue", "Requires warm water", 101));
    shop.addFish(Fish(2, "Betta", "Red", "Aggressive male", 102));

    shop.displayShopInfo();

    return 0;
}