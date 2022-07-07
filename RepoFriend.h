//
// Created by Buz on 5/21/2022.
//

#ifndef PROJECT_REPOFRIEND_H
#define PROJECT_REPOFRIEND_H
#include "MultiMap.h"
#include "User.h"
class RepoFriend {
    Multimap<User, User> mm; // container for friends.

public:
    RepoFriend();
    RepoFriend(Multimap<User, User>);
    RepoFriend(const RepoFriend&);
    void addFriend(User, User);
    void deleteFriend(User, User);
    Multimap<User,User> showFriend();

};


#endif //PROJECT_REPOFRIEND_H
