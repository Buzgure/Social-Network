#include <iostream>
#include "SimplyLinkedList.h"
#include "Event.h"
#include "MultiMap.h"
#include "RepositoryFileCSV.h"
#include "Service.h"
#include "UserInterface.h"
#include "RepoFriend.h"
#include "EventRepository.h"
int main() {
RepositoryFileCSV<User> r1("Users.csv");
RepoFriend rF;
MessageRepository mR;
r1.loadFromFile();
vector <User> vU = r1.getAll();
rF.addFriend(vU[0], vU[1]);
rF.addFriend(vU[0], vU[2]);
rF.addFriend(vU[2], vU[0]);
rF.addFriend(vU[1], vU[0]);
rF.addFriend(vU[1], vU[2]);
rF.addFriend(vU[2], vU[1]);
rF.addFriend(vU[3], vU[4]);
rF.addFriend(vU[4], vU[3]);
rF.addFriend(vU[3], vU[5]);
rF.addFriend(vU[5], vU[3]);
rF.addFriend(vU[4], vU[5]);
rF.addFriend(vU[5], vU[4]);
rF.addFriend(vU[6], vU[7]);
rF.addFriend(vU[7], vU[6]);
rF.addFriend(vU[6], vU[8]);
rF.addFriend(vU[8], vU[6]);
rF.addFriend(vU[7], vU[9]);
rF.addFriend(vU[9], vU[7]);
rF.addFriend(vU[9], vU[10]);
rF.addFriend(vU[10], vU[9]);
rF.addFriend(vU[10], vU[11]);
rF.addFriend(vU[11], vU[10]);
rF.addFriend(vU[11], vU[12]);
rF.addFriend(vU[12], vU[11]);
rF.addFriend(vU[12], vU[13]);
rF.addFriend(vU[13], vU[12]);
rF.addFriend(vU[13], vU[14]);
rF.addFriend(vU[14], vU[0]);
rF.addFriend(vU[14], vU[12]);
rF.addFriend(vU[12], vU[14]);
rF.addFriend(vU[0], vU[14]);
Message m1(0,"buz", "buzkh", "tpup!");
Message m2(1,"buzkh", "buz", ":*");
Message m3(2,"rafar", "buzkh", "ce faci?");
Message m4(3,"adipop", "rafar", "Iesim?");
Message m5(4,"cristideac", "adipop", "Bem si noi ceva ?");
Message m6(5,"rafaelcodrea", "cristideac", "efectiv aneu!");
Message m7(6,"crisanpaul", "rafaelcodrea", "ce zici rafa?");
Message m8(7,"andreikiss", "crisanpaul", "Ne vedem maine!");
Message m9(8,"mihaidascalescu", "andreikiss", "Maine merg la meci ");
Message m10(9,"buz", "mihaidascalescu", "ok");
Message m11(10,"cosmincandrea", "ecedialexandru", "Sal");
Message m12(11,"daniindrei", "cosmincandrea", "Asa ramane nu ?");
Message m13(12,"vasiboss", "daniindrei", "Perfect!");
Message m14(13,"ralucaserban", "vasiboss", "Cum esti?");
Message m15(14,"dianag", "ralucaserban", "Noapte buna!");
Message m16(15,"rafaelcodrea", "buz", "Ne vedem?");
mR.addMessage(m1);
mR.addMessage(m2);
mR.addMessage(m3);
mR.addMessage(m4);
mR.addMessage(m5);
mR.addMessage(m6);
mR.addMessage(m7);
mR.addMessage(m8);
mR.addMessage(m9);
mR.addMessage(m10);
mR.addMessage(m11);
mR.addMessage(m12);
mR.addMessage(m13);
mR.addMessage(m14);
mR.addMessage(m15);
EventRepository eR;
Service service(r1, rF, mR, eR);

UserInterface ui(service);
ui.showMenu();
return 0;
}
