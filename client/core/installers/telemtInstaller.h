#ifndef TELEMTINSTALLER_H
#define TELEMTINSTALLER_H

#include "installerBase.h"

class TelemtInstaller : public InstallerBase {
Q_OBJECT
public:
    explicit TelemtInstaller(QObject *parent = nullptr);

    mugen::ErrorCode
    extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                               SshSession *sshSession, mugen::ContainerConfig &config) override;

    static void uploadClientSettingsSnapshot(SshSession &sshSession, const mugen::ServerCredentials &credentials,
                                             mugen::DockerContainer container,
                                             const mugen::ContainerConfig &config);
};

#endif // TELEMTINSTALLER_H
