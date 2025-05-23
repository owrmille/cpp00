/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:19:11 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/23 13:02:16 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <limits>
#include <string>

bool detectCinFail(void);
std::string truncateText(const std::string& text);
std::string getNonEmptyString(const std::string& input);
void printSeparator();
bool hasOnlyDigits(const std::string& str);
bool hasOnlyLetters(const std::string& str);
std::string getValidPhoneNumber();
std::string getValidName(const std::string& nameType);

#endif
