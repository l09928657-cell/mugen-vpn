#ifndef XRAY_CONFIGURATOR_H
#define XRAY_CONFIGURATOR_H

#include <QObject>
#include <QJsonObject>

#include "configuratorBase.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/models/protocols/xrayProtocolConfig.h"

class XrayConfigurator : public ConfiguratorBase
{
    Q_OBJECT
public:
    XrayConfigurator(SshSession* sshSession, QObject *parent = nullptr);

    mugen::ProtocolConfig createConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container, const mugen::ContainerConfig &containerConfig,
                                const mugen::DnsSettings &dnsSettings,
                                mugen::ErrorCode &errorCode) override;

    mugen::ProtocolConfig processConfigWithLocalSettings(const mugen::ConnectionSettings &settings,
                                                           mugen::ProtocolConfig protocolConfig) override;

    mugen::ErrorCode applyServerSettingsToRemote(const mugen::ServerCredentials &credentials,
                                                   mugen::DockerContainer container,
                                                   mugen::ContainerConfig &containerConfig,
                                                   const mugen::DnsSettings &dnsSettings,
                                                   bool appendNewClient,
                                                   QString *outClientId = nullptr);

private:
    QString prepareServerConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container, const mugen::ContainerConfig &containerConfig,
                                const mugen::DnsSettings &dnsSettings,
                                mugen::ErrorCode &errorCode);

    mugen::ErrorCode uploadServerConfigJson(const mugen::ServerCredentials &credentials, mugen::DockerContainer container,
                                              const mugen::DnsSettings &dnsSettings, const QJsonObject &serverConfig) const;

    mugen::XrayProtocolConfig buildClientProtocolConfig(const mugen::ServerCredentials &credentials,
                                                          mugen::DockerContainer container,
                                                          const mugen::XrayServerConfig &srv,
                                                          const QString &clientId,
                                                          mugen::ErrorCode &errorCode,
                                                          const QString &prefetchedRealityPublicKey = {},
                                                          const QString &prefetchedRealityShortId = {}) const;

    mugen::ErrorCode readRealityKeyFiles(mugen::DockerContainer container,
                                           const mugen::ServerCredentials &credentials,
                                           QString &outPublicKey,
                                           QString &outShortId) const;

    QJsonObject mergeStreamSettingsForServerInbound(const mugen::XrayServerConfig &srv,
                                                    const QJsonObject &existingStreamSettings) const;

    QJsonObject buildStreamSettings(const mugen::XrayServerConfig &srv,
                                    const QString &clientId) const;
};

#endif // XRAY_CONFIGURATOR_H
