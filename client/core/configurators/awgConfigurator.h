#ifndef AWGCONFIGURATOR_H
#define AWGCONFIGURATOR_H

#include <QObject>

#include "wireguardConfigurator.h"

class AwgConfigurator : public WireguardConfigurator
{
    Q_OBJECT
public:
    AwgConfigurator(SshSession* sshSession, QObject *parent = nullptr);

    mugen::ProtocolConfig createConfig(const mugen::ServerCredentials &credentials, mugen::DockerContainer container,
                                const mugen::ContainerConfig &containerConfig,
                                const mugen::DnsSettings &dnsSettings,
                                mugen::ErrorCode &errorCode) override;
};

#endif // AWGCONFIGURATOR_H
