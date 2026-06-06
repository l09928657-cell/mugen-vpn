#ifndef CONFIGURATORBASE_H
#define CONFIGURATORBASE_H

#include <QObject>
#include <QScopedPointer>

#include "core/utils/containerEnum.h"
#include "core/utils/containers/containerUtils.h"
#include "core/utils/protocolEnum.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/models/containerConfig.h"
#include "core/models/protocolConfig.h"

class SshSession;

class ConfiguratorBase : public QObject
{
    Q_OBJECT
public:
    explicit ConfiguratorBase(SshSession* sshSession, QObject *parent = nullptr);

    static QScopedPointer<ConfiguratorBase> create(mugen::Proto protocol,
                                                   SshSession* sshSession);

    virtual mugen::ProtocolConfig createConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container,
                                        const mugen::ContainerConfig &containerConfig,
                                        const mugen::DnsSettings &dnsSettings,
                                        mugen::ErrorCode &errorCode) = 0;

    virtual mugen::ProtocolConfig processConfigWithLocalSettings(const mugen::ConnectionSettings &settings,
                                                                   mugen::ProtocolConfig protocolConfig);
    virtual mugen::ProtocolConfig processConfigWithExportSettings(const mugen::ExportSettings &settings,
                                                                     mugen::ProtocolConfig protocolConfig);

protected:
    void applyDnsToNativeConfig(const mugen::DnsSettings &dns, mugen::ProtocolConfig &protocolConfig);

    SshSession* m_sshSession;
};

#endif // CONFIGURATORBASE_H
