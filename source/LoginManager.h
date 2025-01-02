#pragma once

#ifndef LOGIN_MANAGER_H
#define LOGIN_MANAGER_H

#include <string>

void Login(const std::string& username, std::string& password);
void Register(const std::string& username, std::string& password, std::string& password_a);

#endif