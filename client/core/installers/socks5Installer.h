#ifndef SOCKS5INSTALLER_H
#define SOCKS5INSTALLER_H

#include "installerBase.h"

class Socks5Installer : public InstallerBase
{
    Q_OBJECT
public:
    explicit Socks5Installer(QObject *parent = nullptr);

    mugen::ContainerConfig generateConfig(mugen::DockerContainer container, int port, mugen::TransportProto transportProto) override;
    mugen::ErrorCode extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                                         SshSession* serverController, mugen::ContainerConfig &config) override;
};

#endif // SOCKS5INSTALLER_H

