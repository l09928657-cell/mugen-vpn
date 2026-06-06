#include "serverConfigUtils.h"

#include <QJsonArray>
#include <QJsonValue>

#include "core/models/selfhosted/selfHostedAdminServerConfig.h"
#include "core/utils/constants/apiKeys.h"
#include "core/utils/constants/configKeys.h"

namespace
{

bool hasThirdPartyConfig(const QJsonObject &json)
{
    const QJsonArray containersArray = json.value(mugen::configKey::containers).toArray();
    for (const QJsonValue &val : containersArray) {
        const QJsonObject containerObj = val.toObject();
        for (auto it = containerObj.begin(); it != containerObj.end(); ++it) {
            if (it.key() == mugen::configKey::container) {
                continue;
            }
            const QJsonObject protocolObj = it.value().toObject();
            if (protocolObj.contains(mugen::configKey::isThirdPartyConfig)
                && protocolObj.value(mugen::configKey::isThirdPartyConfig).toBool()) {
                return true;
            }
        }
    }
    return false;
}

} // namespace

namespace serverConfigUtils
{

bool isServerFromApi(const QJsonObject &serverConfigObject)
{
    const int configVersion = serverConfigObject.value(mugen::configKey::configVersion).toInt();
    switch (configVersion) {
    case ConfigSource::Telegram:
    case ConfigSource::MugenGateway:
        return true;
    default:
        return false;
    }
}

ConfigSource getConfigSource(const QJsonObject &serverConfigObject)
{
    return static_cast<ConfigSource>(serverConfigObject.value(mugen::configKey::configVersion).toInt());
}

ConfigType configTypeFromJson(const QJsonObject &serverConfigObject)
{
    const int configVersion = serverConfigObject.value(mugen::configKey::configVersion).toInt();

    switch (configVersion) {
    case ConfigSource::Telegram: {
        constexpr QLatin1String freeV2Endpoint(FREE_V2_ENDPOINT);
        constexpr QLatin1String premiumV1Endpoint(PREM_V1_ENDPOINT);

        const QString apiEndpointValue = serverConfigObject.value(apiDefs::key::apiEndpoint).toString();

        if (apiEndpointValue.contains(premiumV1Endpoint)) {
            return ConfigType::MugenPremiumV1;
        }
        if (apiEndpointValue.contains(freeV2Endpoint)) {
            return ConfigType::MugenFreeV2;
        }
    }
        [[fallthrough]];
    case ConfigSource::MugenGateway: {
        constexpr QLatin1String servicePremium("mugen-premium");
        constexpr QLatin1String serviceFree("mugen-free");
        constexpr QLatin1String serviceExternalPremium("external-premium");

        const QJsonObject apiConfigObject = serverConfigObject.value(apiDefs::key::apiConfig).toObject();
        const QString serviceTypeStr = apiConfigObject.value(apiDefs::key::serviceType).toString();

        if (serviceTypeStr == servicePremium) {
            return ConfigType::MugenPremiumV2;
        }
        if (serviceTypeStr == serviceFree) {
            return ConfigType::MugenFreeV3;
        }
        if (serviceTypeStr == serviceExternalPremium) {
            return ConfigType::ExternalPremium;
        }
        break;
    }
    default:
        break;
    }

    if (hasThirdPartyConfig(serverConfigObject)) {
        return ConfigType::Native;
    }

    const mugen::SelfHostedAdminServerConfig adminProbe =
            mugen::SelfHostedAdminServerConfig::fromJson(serverConfigObject);
    return adminProbe.hasCredentials() ? ConfigType::SelfHostedAdmin : ConfigType::SelfHostedUser;
}

bool isLegacyApiSubscription(ConfigType configType)
{
    return configType == ConfigType::MugenPremiumV1 || configType == ConfigType::MugenFreeV2;
}

bool isApiV2Subscription(ConfigType configType)
{
    switch (configType) {
    case ConfigType::MugenPremiumV2:
    case ConfigType::MugenFreeV3:
    case ConfigType::ExternalPremium:
        return true;
    default:
        return false;
    }
}

} // namespace serverConfigUtils
