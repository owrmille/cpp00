#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->index = 0;
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook was destroyed." << std::endl;
}

void PhoneBook::addContact() {
    Contact newContact;
    
    newContact.setFirstName(getNonEmptyString("Enter your first name: "));
    newContact.setLastName(getNonEmptyString("Enter your last name: "));
    newContact.setNickname(getNonEmptyString("Enter your nickname: "));
    newContact.setPhoneNumber(getValidPhoneNumber());
    newContact.setDarkestSecret(getNonEmptyString("Enter your darkest secret: "));

    this->contacts[this->index % 8] = newContact;
    this->index++;
    std::cout << "New contact was successfully added!" << std::endl;
}

void PhoneBook::searchContact() {
    std::cout << std::setw(10) << "Index" << "|"
            << std::setw(10) << "First Name" << "|"
            << std::setw(10) << "Last Name" << "|"
            << std::setw(10) << "Nickname" << std::endl;
    printSeparator();
    for (int i = 0; i < this->index && i < 8; i++) {
        std::cout << std::setw(10) << i << "|"
            << std::setw(10) << truncateText(this->contacts[i].getFirstName()) << "|"
            << std::setw(10) << truncateText(this->contacts[i].getLastName()) << "|"
            << std::setw(10) << truncateText(this->contacts[i].getNickname()) << std::endl;
    }
    printSeparator();
    int userIndex;
    while (true) {
        std::cout << "Enter the index of the contact you want to search for (or enter -1 to exit): ";
        std::cin >> userIndex;
        if (userIndex == -1) {
            std::cout << "Exiting search..." << std::endl;
            break;
        } else if (userIndex < 0 || userIndex >= this->index || userIndex >= 8) {
            std::cout << "Invalid index. Try again." << std::endl;
        } else {
            this->contacts[userIndex].printContact();
            break;
        }
    }
}