/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatopchu <iatopchu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:19:11 by iatopchu          #+#    #+#             */
/*   Updated: 2025/05/16 17:17:54 by iatopchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

std::string truncateText(std::string text);
std::string getNonEmptyString(const std::string& input);
void printSeparator();
bool hasOnlyDigits(const std::string &str); 
std::string getValidPhoneNumber();

#endif
