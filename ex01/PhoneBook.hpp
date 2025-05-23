/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:19:03 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/23 12:48:56 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <limits>
#include "Contact.hpp"
#include "utils.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    ~PhoneBook();
    int addContact();
    int searchContact();
};
