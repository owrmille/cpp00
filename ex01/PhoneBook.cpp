/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:18:59 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/23 13:09:27 by iatopchu         ###   ########.fr       */
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
    
	std::string fname = getValidName("first");
	if (fname == "") {
		return (-1);
	}
    newContact.setFirstName(fname);
	
	std::string lname = getValidName("last");
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
		
		if (detectCinFail()) {
			std::cout << "ATTENTION: Input was not a number. Try again." << std::endl;
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
        if (userIndex == -1) {
            std::cout << "Exiting search..." << std::endl;
            break;
        }
		if (userIndex < -1 || userIndex >= this->index || userIndex >= 8) {
            std::cout << "ATTENTION: Invalid index. Try again." << std::endl;
			continue;
        }
		this->contacts[userIndex].printContact();
		break;
    }
	return (0);
}