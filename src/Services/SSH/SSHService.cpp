#include "SSHService.hpp"

#include <stdexcept>
#include <qdebug.h>

SSHService::SSHService()
{
}

SSHService::~SSHService()
{
    disconnect();
}

bool SSHService::attemptSSHConnection(const std::string &host, const std::string &user, const std::string &password)
{
    disconnect();

    ssh_session session = ssh_new();

    if (session == nullptr)
    {
        qDebug() << "ssh_new() failed!";
        return false;
    }

    // Setze IP und User
    ssh_options_set(session, SSH_OPTIONS_HOST, host.c_str());
    ssh_options_set(session, SSH_OPTIONS_USER, user.c_str()); // c_str converts std::string to const char*

    qDebug() << "Host:" << QString::fromStdString(host);
    qDebug() << "User:" << QString::fromStdString(user);

    int rc = ssh_connect(session);

    if (rc != SSH_OK)
    {
        qDebug() << "ssh_connect return:" << rc;
        qDebug() << "ssh error code:"
                 << ssh_get_error_code(session);
        qDebug() << "ssh error:"
                 << QString::fromUtf8(ssh_get_error(session));
        ssh_free(session);
        return false;
    }

    qDebug() << "Passwort:" << QString::fromStdString(password);

    // Passwort ist falsch
    if (ssh_userauth_password(session, nullptr, password.c_str()) != SSH_AUTH_SUCCESS)
    {
        qDebug() << "SSH authentication failed:"
                 << ssh_get_error(session);
        ssh_disconnect(session);
        ssh_free(session);
        return false;
    }

    qDebug() << "SSH authentication successful";

    m_sshSession = session;
    return true;
}

void SSHService::disconnect()
{
    if (m_sshSession)
    {
        ssh_disconnect(m_sshSession);
        ssh_free(m_sshSession);
        m_sshSession = nullptr;
    }
}