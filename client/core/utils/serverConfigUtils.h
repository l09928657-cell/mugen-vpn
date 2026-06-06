#ifndef SERVERCONFIGUTILS_H
#define SERVERCONFIGUTILS_H

#include <QJsonObject>

namespace serverConfigUtils
{

enum ConfigType {
    MugenFreeV2 = 0,
    MugenFreeV3,
    MugenPremiumV1,
    MugenPremiumV2,
    SelfHosted,
    ExternalPremium,

    SelfHostedAdmin = 8,
    SelfHostedUser,
    Native,
    Invalid
};

enum ConfigSource {
    Telegram = 1,
    MugenGateway
};

bool isServerFromApi(const QJsonObject &serverConfigObject);

ConfigSource getConfigSource(const QJsonObject &serverConfigObject);

ConfigType configTypeFromJson(const QJsonObject &serverConfigObject);

bool isLegacyApiSubscription(ConfigType configType);

bool isApiV2Subscription(ConfigType configType);

} // namespace serverConfigUtils

#endif // SERVERCONFIGUTILS_H
