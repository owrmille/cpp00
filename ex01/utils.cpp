/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:19:07 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/23 13:02:09 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool detectCinFail(void) {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (true);
	}
	return (false);
}

std::string truncateText(const std::string &text) {
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
		if (std::cin.eof()) {
            std::cout << std::endl << "How dare you? Exiting..." << std::endl;
            return("");
        }
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

bool hasOnlyDigits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool hasOnlyLetters(const std::string &str)
{
    return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos;
}

std::string getValidPhoneNumber() {
    std::string number;
    while (true) {
        number = getNonEmptyString("Enter your phone number: ");
		if (number == "") {
			return "";
		}
        if (hasOnlyDigits(number)) {
            return number;
        } else {
            std::cout << "ATTENTION: Invalid phone number. Try again." << std::endl;
        }
    }   
}

std::string getValidName(const std::string &nameType) {
    std::string name;
    while (true) {
        if (!nameType.compare("first")) {
			name = getNonEmptyString("Enter your first name: ");
		} else if (!nameType.compare("last")) {
			name = getNonEmptyString("Enter your last name: ");
		}
		if (name == "") {
			return "";
		}
        if (hasOnlyLetters(name)) {
            return name;
        } else {
            std::cout << "ATTENTION: Invalid name. Try again." << std::endl;
        }
    }   
}