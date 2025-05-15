#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>

std::string truncateText(std::string text);
std::string getNonEmptyString(const std::string& input);
void printSeparator();
bool is_digits(const std::string &str); 
std::string getValidPhoneNumber();

#endif
