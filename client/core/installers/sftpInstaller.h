#ifndef SFTPINSTALLER_H
#define SFTPINSTALLER_H

#include "installerBase.h"

class SftpInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit SftpInstaller(QObject *parent = nullptr);

    mugen::ContainerConfig generateConfig(mugen::DockerContainer container, int port, mugen::TransportProto transportProto) override;
    mugen::ErrorCode extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                                         SshSession* serverController, mugen::ContainerConfig &config) override;
};

#endif // SFTPINSTALLER_H

