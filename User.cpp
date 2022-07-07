//
// Created by Buz on 5/15/2022.
//

#include "User.h"
#include <utility>
#include <vector>
#include <string>
#include "Utils.h"
User::User() {
    id = -1;
}

User::User(int ID, std::string last, std::string first, std::string user, std::string pass){
    id = ID;
    lastName = last;
    firstName = first;
    userName = user;
    password = pass;

}

User::User(const User & u) {
    id = u.id;
    lastName = u.lastName;
    firstName = u.firstName;
    userName = u.userName;
    password = u.password;
}

void User::setId(int ID) {
    id = ID;
}

void User::setFirstN(std::string n) {
    firstName = n;
}

void User::setLastN(std::string n) {
    lastName = n;
}

void User::setUser(std::string u) {
    userName = u;
}

void User::setPass(std::string pass) {
    password = pass;
}

std::string User::getUser() {
    return userName;
}

std::string User::getPass() {
    return password;
}

std::string User::getFirstN() {
    return firstName;
}

std::string User::getLastN() {
    return lastName;
}

User &User::operator=(const User & u) {
    if(this != &u){
        id = u.id;
        lastName = u.lastName;
        firstName = u.firstName;
        userName = u.userName;
        password = u.password;
    }
    return *this;
}

bool User::operator==(User & u) {
    return (userName == u.userName);
}

User::~User() = default;

std::string User::toStringDelimiter(char delim) {
    return to_string(id) + delim + lastName + delim + firstName + delim + userName + delim + password;
}

User::User(std::string line, char delim) {
    std::vector<std::string> tokens = splitLine(line, delim);
    string first = tokens[1];
    id = stoi(tokens[0]);
    lastName = first;
    firstName = tokens[2];
    userName = tokens[3];
    password = tokens[4];
}