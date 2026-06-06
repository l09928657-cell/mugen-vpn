#ifndef DNSPROTOCOLCONFIG_H
#define DNSPROTOCOLCONFIG_H

#include <QJsonObject>

namespace mugen
{

struct DnsProtocolConfig {
    QJsonObject toJson() const;
    static DnsProtocolConfig fromJson(const QJsonObject& json);
};

} // namespace mugen

#endif // DNSPROTOCOLCONFIG_H

