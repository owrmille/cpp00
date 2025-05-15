#include <iomanip>
#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook {
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    ~PhoneBook();
    void addContact();
    void searchContact();
};
