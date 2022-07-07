//
// Created by Buz on 5/15/2022.
//

#ifndef PROJECT_USER_H
#define PROJECT_USER_H


#include <string>

class User {
    int id;
    std::string lastName;
    std::string firstName;
    std::string userName;
    std::string password;

public:
    User();
    User(int, std::string last, std::string first, std::string user, std::string pass);
    User(const User&);
    User(std::string, char);
    bool operator ==(User&);
    User& operator=(const User&);
    void setId(int);
    void setLastN(std::string);
    void setFirstN(std::string);
    void setUser(std::string);
    void setPass(std::string);
    std::string getUser();
    std::string getLastN();
    std::string getFirstN();
    std::string getPass();
    std::string toStringDelimiter(char);
    ~User();

};


#endif //PROJECT_USER_H
