/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:18:36 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/16 15:10:07 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else {
        for (int i = 1; i < argc; i++) {
            std::string s(argv[i]);
            for (size_t j = 0; j < s.length(); j++) {
                std::cout << static_cast<char>(std::toupper(s[j]));
            }
        }
        std::cout << std::endl;
    }
    return (0);
}