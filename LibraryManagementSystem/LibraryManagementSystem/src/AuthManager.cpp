#include "../include/AuthManager.h"
#include <regex>
using namespace std;

bool AuthManager::login(string username, string password) {

    if (username != "admin") {
        return false;
    }

    regex passwordPattern("^[0-9]{4}$");

    if (regex_match(password, passwordPattern)) {
        return true;
    }

    return false;
}