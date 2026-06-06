#ifndef XRAYINSTALLER_H
#define XRAYINSTALLER_H

#include "installerBase.h"

class XrayInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit XrayInstaller(QObject *parent = nullptr);

    mugen::ErrorCode extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                                         SshSession* serverController, mugen::ContainerConfig &config) override;
};

#endif // XRAYINSTALLER_H

