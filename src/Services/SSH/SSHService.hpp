#pragma once

#include <libssh/libssh.h>
#include <memory>
#include <QString>
#include <string>

class SSHService
{
private:
    ssh_session m_sshSession = nullptr;

public:
    SSHService();
    ~SSHService();

    // Returns a bool whether the connection was established or not, saves ssh session to attribute if it could be established
    bool attemptSSHConnection(const std::string &host, const std::string &user, const std::string &password);

    void disconnect();
};