#include "DataManager.h"
#include "Converter.h"
#include "LoginManager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>

void SaveData(const std::string& login, std::string& password) {
    std::ofstream fileL("username.data");
    std::ofstream fileP("password.txt");

    std::string binary_username = string_to_binary(login);
    std::string binary_password = string_to_binary(password);

    fileL << login << std::endl;
    fileP << password << std::endl;
}