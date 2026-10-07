#include "AppController.hpp"

AppController::AppController(QObject *parent)
{
}

bool AppController::getLoggedIn() const
{
    return m_isLoggedIn;
}

void AppController::login(QString ipAdress, QString userName, QString password)
{
    m_isLoggedIn = m_loginService->attemptLogin(ipAdress, userName, password);
    emit loggedInChanged();
}