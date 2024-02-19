#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

void printTableToFile(const std::vector<std::vector<std::string>>& data, const std::string& filename) {
    std::ofstream outputFile(filename);

    // Check if file open, else stop
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    // Calculate column widths
    std::vector<size_t> columnWidths(data[0].size(), 0);
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            columnWidths[i] = std::max(columnWidths[i], row[i].size());
        }
    }

    // Write table to file
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            outputFile << std::setw(columnWidths[i] + 2) << std::left << row[i];
        }
        outputFile << std::endl;
    }

    // End file write
    outputFile.close();
    std::cout << "Table saved to " << filename << std::endl;
}

int main() {
    // Iron table datan        
    // https://www.healthline.com/nutrition/how-much-iron-per-day#recommendations
    std::vector<std::vector<std::string>> table = {
        {"Age group", "Male (mg/day)", "Female (mg/day)"},
        {"0-0.5", "0.27", "0.27"},
        {"0.6-0.9", "11", "11"},
        {"1-3", "7", "7"},
        {"4-8", "10", "10"},
        {"9-13", "8", "8"},
        {"14-18", "11", "15"},
        {"19-30", "8", "18"},
        {"31-50", "8", "18"},
        {"51-100", "8", "8"}
    };

    // Potassium table datan        
    // https://www.healthline.com/nutrition/how-much-Potassium-per-day#recommendations
    std::vector<std::vector<std::string>> table = {
        {"Age group", "Male (mg/day)", "Female (mg/day)"},
        {"0-0.5", "400", "400"},
        {"0.6-0.9", "860", "860"},
        {"1-3", "2000", "2000"},
        {"4-8", "2300", "2300"},
        {"9-13", "2500", "2300"},
        {"14-18", "3000", "2300"},
        {"19-50", "3400", "2600"},
        {"51-100", "3400", "2600"}
    };

    // Iodine table datan        
    // https://ods.od.nih.gov/factsheets/Iodine-Consumer/
    std::vector<std::vector<std::string>> table = {
        {"Age group", "Amount mcg"},
        {"0-0.5", "400"},
        {"0.6-0.9", "860"},
        {"1-3", "2000"},
        {"4-8", "2300"},
        {"9-13", "2500"},
        {"14-18", "3000"},
        {"19-50", "3400"},
        {"51-100", "3400"}
    };    

    // Molybdenum table datan        
    // https://www.ncbi.nlm.nih.gov/books/NBK222301/#:~:text=The%20Recommended%20Dietary%20Allowance%20(RDA,reproduction%20and%20growth%20in%20animals.
    std::vector<std::vector<std::string>> table = {
        {"Age group", "Male (mg/day)", "Female (mg/day)"},
        {"0-0.5", "400", "400"},
        {"0.6-0.9", "860", "860"},
        {"1-3", "2000", "2000"},
        {"4-8", "2300", "2300"},
        {"9-13", "2500", "2300"},
        {"14-18", "3000", "2300"},
        {"19-50", "3400", "2600"},
        {"51-100", "3400", "2600"}
    };

    // Save table to a file
    printTableToFile(table, "/Users/davidfarache/Documents/HealthApp/Database/Mineral/Iron_Data.txt");

    return 0;
}