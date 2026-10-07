#include "AppController.hpp"

AppController::AppController(QObject *parent) : QObject(parent)
{
}

bool AppController::getLoggedIn() const
{
    return m_isLoggedIn;
}

void AppController::login(const QString &ipAdress, const QString &userName, const QString &password)
{
    bool loginSuccessful = m_loginService->attemptLogin(ipAdress, userName, password);

    if (!loginSuccessful)
    {
        emit loginFailed();
        return;
    }

    if (!m_isLoggedIn)
    {
        m_isLoggedIn = true;
        emit loggedInChanged();
    }
}

void AppController::logout()
{
    if (!m_isLoggedIn)
        return;

    m_loginService->attemptLogout();

    m_isLoggedIn = false;
    emit loggedInChanged();
}