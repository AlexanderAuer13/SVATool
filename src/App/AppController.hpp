#pragma once

#include "../Services/Login/LoginService.hpp"
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <memory>
#include <iostream>

class AppController : public QObject
{
    Q_OBJECT

    QML_ELEMENT
    QML_SINGLETON

    // To-Do: Methode login welche LoginService attemptLogin aufruft und ein Signal wirft. QProperty mit getter und signal dieses loggedinchanged signal

    // Ablauf vom Login:
    // 1. QML ruft AppController.login auf
    // 2. AppController setzt bool loggedIn basierend auf return value vom LoginService also m_loggedIn = m_loginService.attemptLogin(....);
    // 3. AppController ruft loggedInChanged auf (egal ob login erfolgreich oder nicht)
    // 4. in der main qml haben wir onLoggedInChanged welches basierend auf m_loggedIn entweder loginScreen oder dashboard ladet

    Q_PROPERTY(bool loggedIn READ getLoggedIn NOTIFY loggedInChanged)

private:
    bool m_isLoggedIn = false;
    std::unique_ptr<LoginService> m_loginService = std::make_unique<LoginService>();

public:
    explicit AppController(QObject *parent = nullptr);

    bool getLoggedIn() const; // Getter

public slots:
    void login(QString ipAdress, QString userName, QString password);

signals:
    void loggedInChanged();
};