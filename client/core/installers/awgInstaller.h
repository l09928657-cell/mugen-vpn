#ifndef AWGINSTALLER_H
#define AWGINSTALLER_H

#include "installerBase.h"

class AwgInstaller : public InstallerBase
{
    Q_OBJECT
public:
    explicit AwgInstaller(QObject *parent = nullptr);

    mugen::ContainerConfig generateConfig(mugen::DockerContainer container, int port, mugen::TransportProto transportProto) override;
    mugen::ErrorCode extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                                         SshSession* serverController, mugen::ContainerConfig &config) override;

private:
    void generateAwgParameters(mugen::AwgServerConfig &serverConfig, bool isAwg2 = false);
};

#endif // AWGINSTALLER_H

