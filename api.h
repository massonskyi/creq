#ifndef API_H
#define API_H
#include <string>

std::string sign_in(const std::string&, const std::string&);

void sign_up(const std::string&, const std::string&);

void access_protected(const std::string&);
#endif //API_H
