#include <iostream>

#include "api.h"

int main() {
    // Replace these with actual credentials
    const std::string username = "mssnskyi";
    const std::string password = "$2b$12$h.CYeQOBGuGas7nETx2lg.qg5AgV396vRvfbrzgTUYQYsY4OCUARC";

    sign_up(username, password);

    const std::string token = sign_in(username, password);

    if (!token.empty()) {
        access_protected(token);
    }

    return 0;
}
