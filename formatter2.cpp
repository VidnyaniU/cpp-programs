#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Formatter {
public:
    static std::string formatNumber(const std::string& number) {
        size_t dotPosition = number.find('.');
        if (dotPosition == std::string::npos) {
            throw std::invalid_argument("Input must contain a decimal point.");
        }

        std::string integralPart = number.substr(0, dotPosition);
        std::string fractionalPart = number.substr(dotPosition + 1);

        // Remove trailing zeros from the fractional part
        fractionalPart.erase(fractionalPart.find_last_not_of('0') + 1);
        // Remove leading zeros from the integral part
        integralPart.erase(0, integralPart.find_first_not_of('0'));

        if (integralPart.empty()) {
            integralPart = "0";
        }
        if (fractionalPart.empty()) {
            fractionalPart = "0";
        }

        // Create the hashes string
        std::string hashes(5 - integralPart.length(), '#');

        // Combine the parts
        std::string formattedNumber = fractionalPart + hashes + "." + integralPart;
        
        return formattedNumber;
    }
};

int main() {
    std::string input;
    std::cout << "Enter a positive real number in the form F.I: ";
    std::cin >> input;

    try {
        std::string output = Formatter::formatNumber(input);
        std::cout << "Formatted number: " << output << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test cases
    std::cout << "Test case results:" << std::endl;
    std::cout << "Input: 10000.6660, Output: " << Formatter::formatNumber("10000.6660") << std::endl;
    std::cout << "Input: 990.0080, Output: " << Formatter::formatNumber("990.0080") << std::endl;
    std::cout << "Input: 101.11111, Output: " << Formatter::formatNumber("101.11111") << std::endl;
    std::cout << "Input: 31657.0, Output: " << Formatter::formatNumber("31657.0") << std::endl;

    return 0;
}
