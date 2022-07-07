//
// Created by Buz on 5/21/2022.
//

#include "RepoFriend.h"
#include<algorithm>
void RepoFriend::addFriend(User u1, User u2) {
    mm.put(u1,u2);
}

RepoFriend::RepoFriend() {

}

RepoFriend::RepoFriend(Multimap<User,User> multimap) {
    mm = multimap;
}

Multimap<User,User> RepoFriend::showFriend() {
    return mm;
}

void RepoFriend::deleteFriend(User me, User toDelete) {
    /// Deletes the friendship between user me, and user toDelete.
    vector<User> vU = mm.remove(me);
    int pos = 0;
    for(int i = 0; i< vU.size(); i++)
        if(vU[i] == toDelete)
            pos = i;

    for (auto &it: vU)
        if (it == toDelete)
            vU.erase(vU.begin() + pos);
    for (auto &it: vU)
        mm.put(me, it);
    }

RepoFriend::RepoFriend(const RepoFriend & rF) {
    mm = rF.mm;
}