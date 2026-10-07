#pragma once

#include "../SSH/SSHService.hpp"
#include <QString>
#include <memory>

class LoginService
{
private:
    std::shared_ptr<SSHService> m_sshService = nullptr;
public:
    LoginService(std::shared_ptr<SSHService> sshServicePtr);
    virtual ~LoginService() = default;

    bool attemptLogin(QString ipAdress, QString userName, QString password);
    void logout();
};