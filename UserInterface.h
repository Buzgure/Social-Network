//
// Created by Buz on 5/16/2022.
//

#ifndef PROJECT_USERINTERFACE_H
#define PROJECT_USERINTERFACE_H
#include"Service.h"

class UserInterface {
    Service service;
    void reg();
    void logIn();
    void addEvent(User);
    void showEvents();
    void deleteEvent(User);
    void addFriend(User);
    void showFriends(User);
    void newMessage(User);
    void deleteMessage(User);
    void showMessageOfUser(User);
    void deleteFriend(User);
    void updateProfile(User);
    void deleteProfile(User);
public:
    UserInterface();
    UserInterface(Service &);
    void mainMenu();
    void secondMenu(std::string);
    void showMenu();
    void showSecondMenu();
};


#endif //PROJECT_USERINTERFACE_H
