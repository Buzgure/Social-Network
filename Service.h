//
// Created by Buz on 5/16/2022.
//

#ifndef PROJECT_SERVICE_H
#define PROJECT_SERVICE_H
#include "RepositoryFileCSV.h"
#include "RepoFriend.h"
#include "User.h"
#include "MessageRepository.h"
#include "EventRepository.h"
class Service {
    RepositoryFileCSV<User> userRepo;
    RepoFriend repoFriend;
    MessageRepository messageRepo;
    EventRepository eventRepo;
public:
    Service(); // constr.
    Service(RepositoryFileCSV<User>&, RepoFriend&, MessageRepository&, EventRepository&); // constructor with params.
    RepositoryFileCSV<User>& getRepoUser();
    RepoFriend& getRepoFriend();
    void addUser(User);
    void addEvent(Event);
    Event findEvent(std::string);
    void deleteEvent(Event);
    vector<Event> showEvents();
    User findUser(string);
    void addFriend(User, User);
    vector<User> showFriends(User);
    void addMessage(Message);
    void deleteMessage(Message);
    vector<Message> getMessages();
    void deleteFriend(User, User);
    void deleteUser(User);
    void updateUser(User, User);
    Service& operator=(const Service&);
};


#endif //PROJECT_SERVICE_H
