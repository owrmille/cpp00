#include "PhoneBook.hpp"

int main(int argc, char **argv) {
    PhoneBook phoneBook;
    if (argc == 1) {
        while (true) {
            std::string command;
            std::getline(std::cin, command);
            if (command == "ADD") {
                phoneBook.addContact();
            } else if (command == "SEARCH") {
                phoneBook.searchContact();
            } else if (command == "EXIT") {
                break;
            }
        }
    } else {
        std::cout << "Error: Invalid number of arguments." << std::endl;
    }
    (void)argv;
    return (0);
}