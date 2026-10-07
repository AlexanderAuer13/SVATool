#pragma once

#include <QString>

class LoginService
{
private:
public:
    LoginService();
    virtual ~LoginService() = default;

    bool attemptLogin(QString ipAdress, QString userName, QString password);
};