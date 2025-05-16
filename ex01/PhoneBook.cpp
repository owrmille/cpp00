/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:18:59 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/16 17:12:12 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->index = 0;
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook was destroyed." << std::endl;
}

int PhoneBook::addContact() {
    Contact newContact;
    
	std::string fname = getNonEmptyString("Enter your first name: ");
	if (fname == "") {
		return (-1);
	}
    newContact.setFirstName(fname);
	
	std::string lname = getNonEmptyString("Enter your last name: ");
	if (lname == "") {
		return (-1);
	}
    newContact.setLastName(lname);
	
	std::string nname = getNonEmptyString("Enter your nickname: ");
	if (nname == "") {
		return (-1);
	}
    newContact.setNickname(nname);
	
	std::string pnumber = getValidPhoneNumber();
	if (pnumber == "") {
		return (-1);
	}
    newContact.setPhoneNumber(pnumber);
	
	std::string dsecret = getNonEmptyString("Enter your darkest secret: ");
	if (dsecret == "") {
		return (-1);
	}
    newContact.setDarkestSecret(dsecret);
	

    this->contacts[this->index % 8] = newContact;
    this->index++;
    std::cout << "New contact was successfully added!" << std::endl;
	return (0);
}

int PhoneBook::searchContact() {
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
		if (std::cin.eof()) {
            std::cout << std::endl << "How dare you? Exiting..." << std::endl;
            return (-1);
        }
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
	return (0);
}