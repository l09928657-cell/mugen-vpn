#ifndef WIREGUARDINSTALLER_H
#define WIREGUARDINSTALLER_H

#include "installerBase.h"

class WireguardInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit WireguardInstaller(QObject *parent = nullptr);

    mugen::ErrorCode extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                                         SshSession* serverController, mugen::ContainerConfig &config) override;
};

#endif // WIREGUARDINSTALLER_H

