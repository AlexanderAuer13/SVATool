#include "LoginService.hpp"

#include <QString>

LoginService::LoginService(std::shared_ptr<SSHService> sshServicePtr)
{
    m_sshService = sshServicePtr; // Now m_sshService is initialized with the provided shared pointer to SSHService
}

bool LoginService::attemptLogin(QString ipAdress, QString userName, QString password)
{
    m_sshService->attemptSSHConnection(ipAdress.toStdString(), userName.toStdString(), password.toStdString());
}

void LoginService::logout()
{
}