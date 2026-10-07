#include "SSHService.hpp"

#include <stdexcept>

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
        throw std::runtime_error("ssh_new failed");
    }

    // Setze IP und User
    ssh_options_set(session, SSH_OPTIONS_HOST, host.c_str());
    ssh_options_set(session, SSH_OPTIONS_USER, user.c_str()); // c_str converts std::string to const char*

    if (ssh_connect(session) != SSH_OK)
    {
        ssh_free(session);
        return false;
    }

    // Passwort ist falsch
    if (ssh_userauth_password(session, nullptr, password.c_str()) != SSH_AUTH_SUCCESS)
    {
        ssh_disconnect(session);
        ssh_free(session);
        return false;
    }

    m_sshSession = session;
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