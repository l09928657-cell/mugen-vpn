#ifndef OPENVPN_CONFIGURATOR_H
#define OPENVPN_CONFIGURATOR_H

#include <QObject>
#include <QProcessEnvironment>

#include "configuratorBase.h"
#include "core/utils/errorCodes.h"
#include "core/utils/routeModes.h"
#include "core/utils/commonStructs.h"

class OpenVpnConfigurator : public ConfiguratorBase
{
    Q_OBJECT
public:
    OpenVpnConfigurator(SshSession* sshSession, QObject *parent = nullptr);

    struct ConnectionData
    {
        QString clientId;
        QString request;    // certificate request
        QString privKey;    // client private key
        QString clientCert; // client signed certificate
        QString caCert;     // server certificate
        QString taKey;      // tls-auth key
        QString host;       // host ip
    };

    mugen::ProtocolConfig createConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container,
                               const mugen::ContainerConfig &containerConfig,
                               const mugen::DnsSettings &dnsSettings,
                               mugen::ErrorCode &errorCode) override;

    mugen::ProtocolConfig processConfigWithLocalSettings(const mugen::ConnectionSettings &settings,
                                                           mugen::ProtocolConfig protocolConfig) override;
    mugen::ProtocolConfig processConfigWithExportSettings(const mugen::ExportSettings &settings,
                                                            mugen::ProtocolConfig protocolConfig) override;

    static ConnectionData createCertRequest();

private:
    ConnectionData prepareOpenVpnConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container,
                                       const mugen::DnsSettings &dnsSettings,
                                       mugen::ErrorCode &errorCode);
    mugen::ErrorCode signCert(mugen::DockerContainer container, const mugen::ServerCredentials &credentials, 
                      const mugen::DnsSettings &dnsSettings, QString clientId);
};

#endif // OPENVPN_CONFIGURATOR_H
