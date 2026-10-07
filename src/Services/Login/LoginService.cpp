#include "LoginService.hpp"

#include <QString>

LoginService::LoginService()
{
}

bool LoginService::attemptLogin(QString ipAdress, QString userName, QString password)
{
    return (password == "Ja");
}
