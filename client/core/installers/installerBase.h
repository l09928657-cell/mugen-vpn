#ifndef INSTALLERBASE_H
#define INSTALLERBASE_H

#include <QObject>
#include <QJsonObject>

#include "core/utils/containerEnum.h"
#include "core/utils/protocolEnum.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/utils/selfhosted/sshSession.h"
#include "core/models/containerConfig.h"

class InstallerBase : public QObject
{
    Q_OBJECT
public:
    explicit InstallerBase(QObject *parent = nullptr);

    virtual mugen::ContainerConfig generateConfig(mugen::DockerContainer container, int port, mugen::TransportProto transportProto);

    virtual mugen::ErrorCode extractConfigFromContainer(mugen::DockerContainer container, const mugen::ServerCredentials &credentials,
                                                 SshSession* sshSession, mugen::ContainerConfig &config);

    mugen::ContainerConfig createBaseConfig(mugen::DockerContainer container, int port, mugen::TransportProto transportProto);

protected:
};

#endif // INSTALLERBASE_H

