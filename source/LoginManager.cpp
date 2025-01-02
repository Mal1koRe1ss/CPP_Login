#include "LoginManager.h"
#include "DataManager.h"
#include "Converter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

void Register(const std::string& username, std::string& password, std::string& password_a) {
    if (password != password_a) {
        std::cout << "Passwords do not match." << std::endl;
        return;
    }

    std::ofstream fileL("username.data");
    std::ofstream fileP("password.data");

    std::string binary_username = string_to_binary(username);
    std::string binary_password = string_to_binary(password);
    std::cout << "Binary encoded " << std::endl;

    if (fileL.is_open()) {
        fileL << binary_username << std::endl;
        fileL.close();
        std::cout << "Username saved correctly." << std::endl;
    } else {
        std::cout << "Error opening file." << std::endl;
    }

    if (fileP.is_open()) {
        fileP << binary_password << std::endl;
        fileP.close();
        std::cout << "Password saved correctly." << std::endl;
    } else {
        std::cout << "Error opening file." << std::endl;
    }
}

void Login(const std::string& username, std::string& password) {
    std::ifstream input_fileL("username.data");
    std::ifstream input_fileP("password.data");

    std::string binary_from_file;

    if (input_fileL.is_open()) {
        std::getline(input_fileL, binary_from_file);
        input_fileL.close();

        std::string decoded_username = binary_to_string(binary_from_file);

        if (decoded_username == username) {
        } else {
            std::cout << "Username is incorrect." << std::endl;
            return;
        }
    } else {
        std::cout << "File can't be read!" << std::endl;
        return;
    }

    if (input_fileP.is_open()) {
        std::getline(input_fileP, binary_from_file);
        input_fileP.close();

        std::string decoded_pass = binary_to_string(binary_from_file);

        if (decoded_pass == password) {
            std::cout << "Welcome back, " << username << "." << std::endl;
        } else {
            std::cout << "Password is incorrect." << std::endl;
        }
    } else {
        std::cout << "File can't be read!" << std::endl;
    }
}