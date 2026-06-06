#ifndef WIREGUARD_CONFIGURATOR_H
#define WIREGUARD_CONFIGURATOR_H

#include <QHostAddress>
#include <QObject>
#include <QProcessEnvironment>

#include "configuratorBase.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"
#include "core/utils/selfhosted/scriptsRegistry.h"

class WireguardConfigurator : public ConfiguratorBase
{
    Q_OBJECT
public:
    WireguardConfigurator(SshSession* sshSession,
                          bool isAwg, QObject *parent = nullptr);

    struct ConnectionData
    {
        QString clientPrivKey; // client private key
        QString clientPubKey;  // client public key
        QString clientIP;      // internal client IP address
        QString serverPubKey;  // tls-auth key
        QString pskKey;        // preshared key
        QString host;          // host ip
        QString port;
    };

    mugen::ProtocolConfig createConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container,
                                const mugen::ContainerConfig &containerConfig,
                                const mugen::DnsSettings &dnsSettings,
                                mugen::ErrorCode &errorCode) override;

    mugen::ProtocolConfig processConfigWithLocalSettings(const mugen::ConnectionSettings &settings,
                                                           mugen::ProtocolConfig protocolConfig) override;
    mugen::ProtocolConfig processConfigWithExportSettings(const mugen::ExportSettings &settings,
                                                            mugen::ProtocolConfig protocolConfig) override;

    static ConnectionData genClientKeys();

private:
    QList<QHostAddress> getIpsFromConf(const QString &input);
    ConnectionData prepareWireguardConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container,
                                          const mugen::WireGuardServerConfig* serverConfig,
                                          const mugen::AwgServerConfig* awgServerConfig,
                                          const mugen::DnsSettings &dnsSettings,
                                          mugen::ErrorCode &errorCode);

    bool m_isAwg;
    QString m_serverConfigPath;
    QString m_serverPublicKeyPath;
    QString m_serverPskKeyPath;
    mugen::ProtocolScriptType m_configTemplate;
    QString m_protocolName;
    QString m_defaultPort;
};

#endif // WIREGUARD_CONFIGURATOR_H
