#ifndef AUTHDATA_H
#define AUTHDATA_H

#include <QJsonObject>
#include <QString>

#include "core/utils/serverConfigUtils.h"
#include "core/utils/constants/apiKeys.h"
#include "core/utils/constants/apiConstants.h"

namespace mugen
{

struct AuthData {
    QString apiKey;
    
    QJsonObject toJson() const;
    static AuthData fromJson(const QJsonObject& json);
};

} // namespace mugen

#endif // AUTHDATA_H

