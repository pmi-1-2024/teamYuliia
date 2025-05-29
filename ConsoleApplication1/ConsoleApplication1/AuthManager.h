#pragma once
#include "User.h"
#include "Role.h"
#include <vector>
#include <string>
using namespace std;

class AuthManager {
public:
    static User* login(const string& email, const string& password, const vector<User>& users);
    static bool emailExists(const string& email, const vector<User>& users);
    static User registerUser(const string& name, const string& email, const string& password, int defaultRoleId, vector<User>& users);
};