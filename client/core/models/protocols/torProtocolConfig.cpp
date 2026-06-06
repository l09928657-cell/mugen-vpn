#include "torProtocolConfig.h"

#include "core/utils/constants/configKeys.h"

using namespace mugen;

namespace mugen
{

QJsonObject TorServerConfig::toJson() const
{
    QJsonObject obj;
    
    if (!site.isEmpty()) {
        obj[configKey::site] = site;
    }
    
    return obj;
}

TorServerConfig TorServerConfig::fromJson(const QJsonObject& json)
{
    TorServerConfig config;
    
    config.site = json.value(configKey::site).toString();
    
    return config;
}

QJsonObject TorProtocolConfig::toJson() const
{
    return serverConfig.toJson();
}

TorProtocolConfig TorProtocolConfig::fromJson(const QJsonObject& json)
{
    TorProtocolConfig config;
    
    config.serverConfig = TorServerConfig::fromJson(json);
    
    return config;
}

} // namespace mugen

