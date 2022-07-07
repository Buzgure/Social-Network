//
// Created by Buz on 5/16/2022.
//

#include "Service.h"
Service::Service() = default;

Service::Service(RepositoryFileCSV<User> & rU, RepoFriend& rF, MessageRepository& mR, EventRepository& eR) {
    userRepo = rU;
    repoFriend = rF;
    messageRepo = mR;
    eventRepo = eR;

}

RepositoryFileCSV<User> &Service::getRepoUser() {
    ///Returns repository of users.
    return userRepo;
}

void Service::addUser(User u) {
    ///Adds user u.
    userRepo.add(u);
}

User Service::findUser(string uN) {
    ///Finds the user whose username is uN.
    User u;
    vector<User> rU = userRepo.getAll();
    for(int i = 0; i<userRepo.getAll().size();i++ )
        if(rU[i].getUser() == uN)
            return rU[i];
    return u;
}

void Service::addFriend(User u1, User u2) {
    ///Adds friendship between users u1 and u2.
    repoFriend.addFriend(u1, u2);
}

RepoFriend &Service::getRepoFriend() {
    return repoFriend;
}

vector<User> Service::showFriends(User u1) {
    /// Returns a vector with friends of user u1.
    return repoFriend.showFriend().showValuesForKey<User>(u1);

}

void Service::addMessage(Message m) {
    ///Adds message m.
    messageRepo.addMessage(m);
}

void Service::deleteMessage(Message m) {
    ///Deletes message m.
    messageRepo.deleteMessage(m);
}

vector<Message> Service::getMessages() {
    ///Returns a vector with all messages.
    return messageRepo.showMessages();
}

void Service::deleteFriend(User me, User toDelete) {
    ///Deletes friendship between 2 users.
    repoFriend.deleteFriend(me, toDelete);
}

void Service::deleteUser(User u) {
    ///Deletes user u.
    userRepo.remove(u);
}

void Service::updateUser(User me, User toUpdate) {
    ///Updates user me.
    userRepo.update(me, toUpdate);
}

Service &Service::operator=(const Service &s) {
    if(this != & s){
        this->userRepo = s.userRepo;
        this->repoFriend = s.repoFriend;
        this->messageRepo = s.messageRepo;
    }
        return *this;
}

void Service::addEvent(Event e) {
    ///Adds event e.
    eventRepo.addEvent(e);
}

void Service::deleteEvent(Event e) {
    ///Deletes event e.
    eventRepo.deleteEvent(e);
}

Event Service::findEvent(std::string name) {
    ///Finds the event with given name.
    return eventRepo.findEvent(name);
}

vector<Event> Service::showEvents() {
    ///Returns a vector with all the events.
    return eventRepo.showEvents();
}
