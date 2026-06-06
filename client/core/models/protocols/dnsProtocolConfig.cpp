#include "dnsProtocolConfig.h"

namespace mugen
{

QJsonObject DnsProtocolConfig::toJson() const
{
    return QJsonObject();
}

DnsProtocolConfig DnsProtocolConfig::fromJson(const QJsonObject& json)
{
    Q_UNUSED(json);
    return DnsProtocolConfig();
}

} // namespace mugen

