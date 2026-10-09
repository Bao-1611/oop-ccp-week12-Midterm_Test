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
        std::cout << "Category ID : " << categoryId << "\n"
                  << "Name        : " << categoryName << "\n"
                  << "Description : " << description << "\n"
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

    void displayAllCategories() const {
        std::cout << "\n=========================================\n"
                  << "           SHOP CATEGORIES LIST          \n"
                  << "=========================================\n";
        for (const auto& category : categories) {
            category.displayCategoryInfo();
        }
    }

    void displayFishesGroupedByCategory() const {
        std::cout << "\n=========================================\n"
                  << "       INVENTORY GROUPED BY CATEGORY     \n"
                  << "=========================================\n";

        for (const auto& category : categories) {
            std::cout << "\n>>> " << category.getCategoryName() 
                      << " (Category ID: " << category.getCategoryId() << ") <<<\n";
            std::cout << "Description: " << category.getDescription() << "\n";
            std::cout << "-----------------------------------------\n";

            int count = 0;
            for (const auto& fish : fishes) {
                if (fish.getCategoryId() == category.getCategoryId()) {
                    fish.displayFishInfo();
                    count++;
                }
            }
            std::cout << "Total in " << category.getCategoryName() << ": " << count << " fish\n";
        }
    }
};

int main() {
    Date openingDate(1, 3, 2024);
    FishShop myShop(101, "AquaWorld Emporium", "789 Ocean Boulevard", "Sarah Jenkins", openingDate);

    Category cat1(1001, "Cichlids", "Intelligent and territorial tropical freshwater fish");
    Category cat2(1002, "Anabantoids", "Labyrinth breathers capable of taking air from the surface");
    Category cat3(1003, "Cyprinids", "Hardy freshwater schooling fish including Barbs and Danios");
    Category cat4(1004, "Poeciliids", "Vibrant, live-bearing peaceful community fish");

    myShop.addCategory(cat1);
    myShop.addCategory(cat2);
    myShop.addCategory(cat3);
    myShop.addCategory(cat4);

    myShop.addFish(Fish(1, "Discus", "Blue Turquoise", "Requires warm, clean water", 1001));
    myShop.addFish(Fish(2, "Angelfish", "Silver Striped", "Graceful long fins", 1001));
    myShop.addFish(Fish(3, "Oscar", "Tiger Orange", "Large and intelligent", 1001));
    myShop.addFish(Fish(4, "German Blue Ram", "Bright Yellow/Blue", "Peaceful dwarf cichlid", 1001));
    myShop.addFish(Fish(5, "Electric Blue Dempsey", "Neon Blue", "Striking coloration", 1001));
    myShop.addFish(Fish(6, "Convict Cichlid", "Black and White", "Extremely defensive of fry", 1001));
    myShop.addFish(Fish(7, "Keyhole Cichlid", "Brownish Yellow", "Shy and peaceful dwarf", 1001));
    myShop.addFish(Fish(8, "Kribensis", "Pink and Olive", "Cave spawner", 1001));
    myShop.addFish(Fish(9, "Yellow Lab", "Electric Yellow", "African lake mbuna", 1001));
    myShop.addFish(Fish(10, "Firemouth", "Red and Grey", "Gills flare when threatened", 1001));

    myShop.addFish(Fish(11, "Siamese Fighting Fish", "Red and Blue", "Solitary male, long fins", 1002));
    myShop.addFish(Fish(12, "Dwarf Gourami", "Powder Blue", "Labyrinth breather, peaceful", 1002));
    myShop.addFish(Fish(13, "Pearl Gourami", "Spotted Silver", "Lace-like pattern", 1002));
    myShop.addFish(Fish(14, "Three-Spot Gourami", "Opaline", "Hardy and active", 1002));
    myShop.addFish(Fish(15, "Kissing Gourami", "Pale Pink", "Fights by pressing lips", 1002));
    myShop.addFish(Fish(16, "Paradise Fish", "Red and Blue Stripes", "Tolerates cold temperatures", 1002));
    myShop.addFish(Fish(17, "Chocolate Gourami", "Dark Brown", "Requires soft acidic water", 1002));
    myShop.addFish(Fish(18, "Honey Gourami", "Golden Yellow", "Small, very gentle", 1002));
    myShop.addFish(Fish(19, "Sparkling Gourami", "Iridescent Green", "Produces clicking sounds", 1002));
    myShop.addFish(Fish(20, "Moonlight Gourami", "Silvery Green", "Long thread-like feelers", 1002));

    myShop.addFish(Fish(21, "Zebra Danio", "Silver Striped", "Fast top swimmer", 1003));
    myShop.addFish(Fish(22, "Cherry Barb", "Bright Crimson", "Schooling species", 1003));
    myShop.addFish(Fish(23, "Tiger Barb", "Yellow and Black", "Active fin nipper", 1003));
    myShop.addFish(Fish(24, "Harlequin Rasbora", "Copper Pink", "Distinct black wedge", 1003));
    myShop.addFish(Fish(25, "Celestial Pearl Danio", "Galaxy Blue", "White spots, red fins", 1003));
    myShop.addFish(Fish(26, "Rosy Barb", "Rose Red", "Hardy and cold-tolerant", 1003));
    myShop.addFish(Fish(27, "White Cloud Mountain", "Bronze Silver", "Coldwater nano fish", 1003));
    myShop.addFish(Fish(28, "Bala Shark", "Silver with Black Fins", "Large active swimmer", 1003));
    myShop.addFish(Fish(29, "Red Tail Black Shark", "Black and Red", "Territorial bottom dweller", 1003));
    myShop.addFish(Fish(30, "Odessa Barb", "Red Banded", "Vibrant dark markings", 1003));

    myShop.addFish(Fish(31, "Fancy Guppy", "Multicolor Rainbow", "Prolific livebearer", 1004));
    myShop.addFish(Fish(32, "Black Molly", "Solid Velvet Black", "Prefers slightly brackish water", 1004));
    myShop.addFish(Fish(33, "Red Wagtail Platy", "Orange and Black", "Friendly community fish", 1004));
    myShop.addFish(Fish(34, "Green Swordtail", "Olive with Sword Tail", "Males possess long caudal extension", 1004));
    myShop.addFish(Fish(35, "Endler's Livebearer", "Neon Orange Green", "Small, highly active", 1004));
    myShop.addFish(Fish(36, "Dalmatian Molly", "Black and White Speckled", "Loves algae feeding", 1004));
    myShop.addFish(Fish(37, "Mickey Mouse Platy", "Golden Yellow", "Distinct tail marking", 1004));
    myShop.addFish(Fish(38, "Sailfin Molly", "Iridescent Turquoise", "High back fin in males", 1004));
    myShop.addFish(Fish(39, "Pineapple Swordtail", "Yellow Red", "Bright contrast colors", 1004));
    myShop.addFish(Fish(40, "Mosquito Fish", "Grey Translucent", "Hardy mosquito larva eater", 1004));

    myShop.displayShopInfo();
    myShop.displayAllCategories();
    myShop.displayFishesGroupedByCategory();

    return 0;
}