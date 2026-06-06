#ifndef MTPROXYINSTALLER_H
#define MTPROXYINSTALLER_H

#include "installerBase.h"

#include <QString>

struct MtProxyContainerDiagnostics {
    bool portReachable = false;
    bool upstreamReachable = false;
    int clientsConnected = -1;
    QString lastConfigRefresh;
    QString statsEndpoint;
};

class MtProxyInstaller : public InstallerBase {
Q_OBJECT
public:
    explicit MtProxyInstaller(QObject *parent = nullptr);

    mugen::ErrorCode
    extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                               SshSession *sshSession, mugen::ContainerConfig &config) override;

    static void uploadClientSettingsSnapshot(SshSession &sshSession, const mugen::ServerCredentials &credentials,
                                             mugen::DockerContainer container,
                                             const mugen::ContainerConfig &config);

    static mugen::ErrorCode queryDiagnostics(SshSession &sshSession, const mugen::ServerCredentials &credentials,
                                               mugen::DockerContainer container, int listenPort,
                                               MtProxyContainerDiagnostics &out);
};

#endif // MTPROXYINSTALLER_H
