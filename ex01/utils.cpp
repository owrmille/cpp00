#include "utils.hpp"

std::string truncateText(std::string text) {
    if (text.length() > 10) {
        return text.substr(0, 9) + ".";
    }
    return text;
}

std::string getNonEmptyString(const std::string& message) {
    std::string input;
	size_t i, j;
    while (true) {
        std::cout << message;
        std::getline(std::cin, input);
		i = input.find_first_not_of("\t\r\n ");
		j = input.find_last_not_of("\t\r\n ");
		if (i != std::string::npos) {
			input = input.substr(i, j - i + 1);
		} else {
			input.clear();
		}
        if (input.empty()) {
            std::cout << "This field cannot be empty. Try again." << std::endl;
        } else {
            return (input);
        }   
    }
}

void printSeparator() {
    std::cout << "--------------------------------------------" << std::endl;
}

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

std::string getValidPhoneNumber() {
    std::string number;
    while (true) {
        number = getNonEmptyString("Enter your phone number: ");
        if (is_digits(number)) {
            return number;
        } else {
            std::cout << "Invalid phone number. Try again." << std::endl;
        }
    }   
}