#ifndef TORPROTOCOLCONFIG_H
#define TORPROTOCOLCONFIG_H

#include <QJsonObject>
#include <QString>

namespace mugen
{

struct TorServerConfig {
    QString site;
    
    QJsonObject toJson() const;
    static TorServerConfig fromJson(const QJsonObject& json);
};

struct TorProtocolConfig {
    TorServerConfig serverConfig;
    
    QJsonObject toJson() const;
    static TorProtocolConfig fromJson(const QJsonObject& json);
};

} // namespace mugen

#endif // TORPROTOCOLCONFIG_H

