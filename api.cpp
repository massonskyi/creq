//
// Created by user064 on 23.07.24.
//
#include <iostream>
#include "httplib.h"
#include "json.hpp"
using json = nlohmann::json;

const std::string BASE_URL = "http://0.0.0.0:8080";

// Function to sign up a new user
void sign_up(const std::string& username, const std::string& password) {
    httplib::Client client(BASE_URL.c_str());
    json body = {
        {"username", username},
        {"password", password}
    };

    auto res = client.Post("/api/auth/sign_up", body.dump(), "application/json");
    if (res && res->status == 200) {
        std::cout << "Sign up successful: " << res->body << std::endl;
    } else {
        std::cerr << "Sign up failed: " << (res ? res->body : "No response") << std::endl;
    }
}

// Function to sign in and get the token
std::string sign_in(const std::string& username, const std::string& password) {
    httplib::Client client(BASE_URL.c_str());
    httplib::Params params = {
        {"username", username},
        {"password", password}
    };

    auto res = client.Post("/api/auth/sign_in", params);
    if (res && res->status == 200) {
        auto response_json = json::parse(res->body);
        std::cout << "Sign in successful: " << res->body << std::endl;
        return response_json["access_token"].get<std::string>();
    } else {
        std::cerr << "Sign in failed: " << (res ? res->body : "No response") << std::endl;
        return "";
    }
}

// Function to access a protected route
void access_protected(const std::string& token) {
    httplib::Client client(BASE_URL.c_str());
    httplib::Headers headers = {
        {"Authorization", "Bearer " + token}
    };

    auto res = client.Get("/api/auth/protected", headers);
    if (res && res->status == 200) {
        std::cout << "Protected route access successful: " << res->body << std::endl;
    } else {
        std::cerr << "Protected route access failed: " << (res ? res->body : "No response") << std::endl;
    }
}

