/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:18:55 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/16 17:11:58 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
		PhoneBook phoneBook;
        while (true) {
            std::string command;
            std::getline(std::cin, command);
			if (std::cin.eof()) {
				std::cout << std::endl << "How dare you? Exiting..." << std::endl;
				return (-1);
        	}
            if (command == "ADD") {
                if (phoneBook.addContact() == -1) {
					return (-1);
				}
            } else if (command == "SEARCH") {
                if (phoneBook.searchContact() == -1) {
					return (-1);
				}
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