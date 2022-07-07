//
// Created by Buz on 5/16/2022.
//

#include <iostream>
#include "UserInterface.h"

UserInterface::UserInterface() = default;
UserInterface::UserInterface(Service &s) {
    service = s;
}

void UserInterface::mainMenu() {
    /// Shows the main menu.
    std::cout<<"Choose your option: "<<endl;
    std::cout<<"1.Register. "<<endl;
    std::cout<<"2.Log in."<<endl;
    std::cout<<"3.Exit."<<endl;
}

void UserInterface::secondMenu( std::string name) {
    ///Shows the secondary menu, after the log in.
    std::cout<<"Welcome, "<<name<<endl;
    std::cout<<"Choose your option: "<<endl;
    std::cout<<"1.View Friends."<<endl;
    std::cout<<"2.View Messages."<<endl;
    std::cout<<"3.Add Friend."<<endl;
    std::cout<<"4.New Message."<<endl;
    std::cout<<"5.Delete Message."<<endl;
    std::cout<<"6.Delete Friend."<<endl;
    std::cout<<"7.Update Profile."<<endl;
    std::cout<<"8.Delete Profile."<<endl;
    std::cout<<"9.Add Event."<<endl;
    std::cout<<"10.Delete Event."<<endl;
    std::cout<<"11.Show Events."<<endl;
    std::cout<<"12.Log out."<<endl;

}

void UserInterface::deleteProfile(User u1) {
    service.deleteUser(u1);
    cout<<"Your Profile was deleted."<<endl;
}

void UserInterface::showFriends(User u) {
    ///Shows friends of user u.
    vector<User> vU;
    vU = service.showFriends(u);
    for(auto &it:vU)
        cout<<it.getFirstN()<<' '<<endl;
}

void UserInterface::deleteFriend(User me) {
    ///Deletes friendship between 2 users
    cout<<"Enter your friend's username: "<<endl;
    std::string uN;
    cin>>uN;
    service.deleteFriend(me, service.findUser(uN));

}

void UserInterface::newMessage(User U) {
    cout<<"Whom would you like to send your message to: "<<endl;
    std::string receiver;
    cin>>receiver;
    std::string sender;
    sender = U.getUser();
    cout<<"Enter the message: "<<endl;
    std::string content;
    cin.ignore();
    getline(cin, content, '\n');
    Message m(0,sender, receiver, content);
    service.addMessage(m);

}

void UserInterface::showMessageOfUser(User U) {
    /// Show messages sent or received by user u.
    vector<Message> vM = service.getMessages();
    for(auto & it: vM){
        if(it.getSender() == U.getUser())
            cout<<"to "<<it.getReceiver()<<": "<<it.getContent()<<endl;
    }
    for(auto & it: vM){
        if(it.getReceiver() == U.getUser())
            cout<<"from "<<it.getSender()<<": "<<it.getContent()<<endl;
    }



}

void UserInterface::deleteMessage(User u) {
    ///Deletes a certain message of user u.
    cout<<"Enter message's content: "<<endl;
    std::string content;
    cin.ignore();
    getline(cin, content, '\n');
    vector<Message> vM = service.getMessages();
    for(auto & it: vM){
        if((it.getContent() == content) && (it.getSender() == u.getUser()))
            service.deleteMessage(it);
    }
}


void UserInterface::updateProfile(User oU) {
    std::cout<<"Your new username: "<<endl;
    string uN;
    std::cin>>uN;
    bool check = true;
    string p;
    while(check){
        std::cout<<"Your new password: "<<endl;

        std::cin>>p;
        if(p.length() < 6)
            std::cout<<"Your password must be at least 6 characters long."<<endl;
        else
            check = false;
    }
    std::cout<<"Enter first Name: "<<endl;
    string fN;
    std::cin>>fN;
    std::cout<<"Enter Last Name: "<<endl;
    string lN;
    std::cin>>lN;
    User nU(0, lN, fN, uN, p);
    service.updateUser(oU, nU);
}

void UserInterface::showSecondMenu() {
    ///Verifies if the user exists, if the password is correct, and shows the second menu.
    std::cout<<"Enter Username: "<<endl;
    string uN;
    std::cin>>uN;
    User u;
    u = service.findUser(uN);
    if(u.getLastN() == ""){
        cout<<"User does not exist!"<<endl;
        return;
    }

    std::cout<<"Enter Password: "<<endl;
    string p;
    std::cin>>p;
    while(u.getPass() != p){
        std::cout<<"Wrong password!"<<endl;
        std::cout<<"Retry!"<<endl;
        std::cin>>p;
    }
    int opt;
    bool check =true;
    while(check){
        secondMenu(u.getFirstN());
        std::cin>>opt;
        switch(opt){
            case 1:
                showFriends(u);
                break;
            case 2:
                showMessageOfUser(u);
                break;
            case 3:
                addFriend(u);
                break;
            case 4:
                newMessage(u);
                break;
            case 5:
                deleteMessage(u);
                break;
            case 6:
                deleteFriend(u);
                break;
            case 7:
                updateProfile(u);
                check = false;
                break;
            case 8:
                deleteProfile(u);
                check = false;
                break;
            case 9:
                addEvent(u);
                break;
            case 10:
                deleteEvent(u);
                break;
            case 11:
                showEvents();
                break;
            case 12:
                check = false;
                break;
        }
    }

}

void UserInterface::reg() {
    /// Interface for register.
    std::cout<<"Your desired username: "<<endl;
    string uN;
    std::cin>>uN;
    bool check = true;
    string p;
    while(check){
        std::cout<<"Your desired password: "<<endl;

        std::cin>>p;
        if(p.length() < 6)
            std::cout<<"Your password must be at least 6 characters long."<<endl;
        else
            check = false;
    }
    std::cout<<"First Name: "<<endl;
    string fN;
    std::cin>>fN;
    std::cout<<"Last Name: "<<endl;
    string lN;
    std::cin>>lN;
    User u(0,lN, fN, uN, p);
    service.addUser(u);


}

void UserInterface::logIn() {
    ///Interface for login.
    std::cout<<"Enter Username: "<<endl;
    string uN;
    std::cin>>uN;
    User u;
    u = service.findUser(uN);
    std::cout<<"Enter Password: "<<endl;
    string p;
    std::cin>>p;
    while(u.getPass() != p){
        std::cout<<"Wrong password!"<<endl;
        std::cout<<"Retry!"<<endl;
        std::cin>>p;
    }
    




}

void UserInterface::addEvent(User u) {
    ///Creates an event, which can be deleted only by user u.
    cout<<"Enter event's name: "<<endl;
    std::string name;
    cin.ignore();
    getline(cin, name, '\n');
    cout<<"Enter event's start date: "<<endl;
    std::string date;
    cin>>date;
    cout<<"Enter event's start time: "<<endl;
    std::string time;
    cin>>time;
    cout<<"Enter event's desired location: "<<endl;
    std::string location;
    cin>>location;
    std::string userName = u.getUser();

    Event e(name, date, time, location, userName);
    service.addEvent(e);

}

void UserInterface::deleteEvent(User u) {
    ///Checks if the event was created by user u, and if so deletes it.
    cout<<"Enter event name: "<<endl;
    std::string name;
    cin.ignore();
    getline(cin, name, '\n');
    vector<Event> vE = service.showEvents();
//    Event e = service.findEvent(name);
    for(auto &it: vE)
        if(it.getUser() == u.getUser() && it.getName() == name)
            service.deleteEvent(it);
        else
            cout<<"You can only delete events created by you!"<<endl;
}

void UserInterface::showEvents() {
    /// Show all the events created by users.
    vector<Event> vE = service.showEvents();
    for(auto &it : vE)
        cout<<it<<endl;
    cout<<endl;
}

    void UserInterface::addFriend(User u1) {
    cout<<"Enter your friend's username:"<<endl;
    std::string uN;
    cin>>uN;
    User u2;
    u2 = service.findUser(uN);
    service.addFriend(u1,u2);

}

void UserInterface::showMenu() {
    int opt;
    bool check = true;
    while(check){
        mainMenu();
        std::cin>>opt;
        switch(opt){
            case 1:
                reg();
                break;
            case 2:
                showSecondMenu();
                break;
            case 3:
                check = false;
                break;
        }
    }
}

