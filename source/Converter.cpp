#include "Converter.h"
#include <iostream>
#include <string>
#include <bitset>

std::string string_to_binary(const std::string &data) {
    std::string binary_representation;
    for (unsigned char c : data) {
        binary_representation += std::bitset<8>(c).to_string();
    }
    return binary_representation;
}

std::string binary_to_string(const std::string &binary_data) {
    std::string result;
    for (size_t i = 0; i < binary_data.length(); i += 8) {
        std::bitset<8> b(binary_data.substr(i, 8));
        result += char(b.to_ulong());
    }
    return result;
}