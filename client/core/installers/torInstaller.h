#ifndef TORINSTALLER_H
#define TORINSTALLER_H

#include "installerBase.h"

class TorInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit TorInstaller(QObject *parent = nullptr);

    mugen::ErrorCode extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                                         SshSession* serverController, mugen::ContainerConfig &config) override;
};

#endif // TORINSTALLER_H

