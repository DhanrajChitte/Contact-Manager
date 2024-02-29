#include "ContactManager.hpp"
#include <fstream>
using namespace std;
int main()
{
    ContactManager cm;
    cm.add(7822969515, "Dhanraj Chitte", "chittedhanraj3@gmail.com", "Mr.");
    cm.list();
    cm.add();
    cm.list();
    cm.edit();
    cm.list();
    cm.editPhoneNumber();
    cm.list();
    cm.editName();
    cm.list();
    cm.editEmail();
    cm.list();
    cm.editTitle();
    cm.list();
    cm.removeUser();
    cm.list();
    cm.removeUserName();
    cm.list();
    cm.removeUserNumber();
    cm.list();
    cm.removeUserEmail();
    cm.list();
    cm.searchName();
    cm.searchNumber();
    cm.searchEmail();
    cm.list();
    cm.backUp();
    return 0;
}
