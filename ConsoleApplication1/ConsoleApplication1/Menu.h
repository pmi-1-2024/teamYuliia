#pragma once
#include "User.h"
#include <vector>
#include <string>
using namespace std;

class Menu {
public:
    static void showStartMenu();
    static User* authFlow(vector<User>& users, int defaultRoleId);
};