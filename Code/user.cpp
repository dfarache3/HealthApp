#include <iostream>
#include <string>
#include <unordered_map>

class HumanBody {
private:
    std::unordered_map<std::string, double> minerals; // Stores minerals and their amounts
    std::unordered_map<std::string, double> vitamins; // Store macro and their amounts
    std::unordered_map<std::string, double> macros; // Store macro and their amounts
    std::unordered_map<std::string, double> body; // Info of human body

public:
    // Constructor
    HumanBody() {
        // Intialize weight
        body["Weight"] = 99; // kg
        body["Height"] = 6.1; // feet
        body["Gender"] = 0; // 0:male, 1:female
        body["Age"] = 23; //years
        body["Activity level"] = 0; // low: 0, 1: medium, 2: high

        // Initialize minerals and their amounts
        minerals["Iron"] = 10;  // mg/day
        minerals["Potassium"] = 10; // mg 
        minerals["Iodine"] = 10; // mcg
        minerals["Molybdenum"] = 10; // ucg/day
        minerals["Chromium"] = 10; // mcg
        minerals["Calcium"] = 1000; // mg
        minerals["Magnesium"] = 400; // mg

        // Not yet defined
        minerals["Sulfur"] = 10;
        minerals["Sodium"] = 1500, 2300; // mg

        // Macro information
        macros["Protein"] = 10; // grams
        macros["Carbs"];
        macros["Fat"];
        macros["Sugar"];
        macros["Calories"];

        // Vitamins
        vitamins["A"];
        vitamins["C"];
        vitamins["D"];
        vitamins["E"];
        vitamins["K"];
        vitamins["thiamine"];
        vitamins["riboflavin"];
        vitamins["B6"];
        vitamins["B12"];
        vitamins["niacin"];
        vitamins["pantothenic acid"];
        vitamins["biotin"];
        vitamins["folate"];
        
    }

    // Destructor
    // ~HumanBody() {}

    // Getter method to get the amount of a specific mineral
    double getMineralAmount(const std::string& mineral) const {
        auto it = minerals.find(mineral);
        if (it != minerals.end()) {
            return it->second;
        }
        return 0; // Return 0 if mineral not found (you can modify this behavior if needed)
    }

    // Setter method to update the amount of a specific mineral
    void setMineralAmount(const std::string& mineral, double amount) {
        minerals[mineral] = amount;
    }

    // Function to display information about minerals and their amounts
    void displayMinerals() const {
        std::cout << "Minerals in the human body and their amounts:" << std::endl;
        for (const auto& mineral : minerals) {
            std::cout << mineral.first << ": " << mineral.second << " mg" << std::endl;
        }
    }
};

int main() {
    HumanBody body;
    body.displayMinerals();

    // Update amount of Sodium
    body.setMineralAmount("Sodium", 1800);

    std::cout << "\nAfter updating Sodium amount:" << std::endl;
    body.displayMinerals();

    return 0;
}