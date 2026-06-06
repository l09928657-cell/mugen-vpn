#ifndef SOCKS5PROXYPROTOCOLCONFIG_H
#define SOCKS5PROXYPROTOCOLCONFIG_H

#include <QJsonObject>
#include <QString>

namespace mugen
{

struct Socks5ProxyProtocolConfig {
    QString port;
    QString userName;
    QString password;
    
    QJsonObject toJson() const;
    static Socks5ProxyProtocolConfig fromJson(const QJsonObject& json);
};

} // namespace mugen

#endif // SOCKS5PROXYPROTOCOLCONFIG_H

