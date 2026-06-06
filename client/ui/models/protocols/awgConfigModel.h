#ifndef AWGCONFIGMODEL_H
#define AWGCONFIGMODEL_H

#include <QAbstractListModel>

#include "core/utils/containerEnum.h"
#include "core/utils/containers/containerUtils.h"
#include "core/utils/protocolEnum.h"
#include "core/models/protocols/awgProtocolConfig.h"

class AwgConfigModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        SubnetAddressRole = Qt::UserRole + 1,
        PortRole,

        ClientMtuRole,
        ClientJunkPacketCountRole,
        ClientJunkPacketMinSizeRole,
        ClientJunkPacketMaxSizeRole,
        ClientSpecialJunk1Role,
        ClientSpecialJunk2Role,
        ClientSpecialJunk3Role,
        ClientSpecialJunk4Role,
        ClientSpecialJunk5Role,

        ServerJunkPacketCountRole,
        ServerJunkPacketMinSizeRole,
        ServerJunkPacketMaxSizeRole,
        ServerInitPacketJunkSizeRole,
        ServerResponsePacketJunkSizeRole,
        ServerCookieReplyPacketJunkSizeRole,
        ServerTransportPacketJunkSizeRole,

        ServerInitPacketMagicHeaderRole,
        ServerResponsePacketMagicHeaderRole,
        ServerUnderloadPacketMagicHeaderRole,
        ServerTransportPacketMagicHeaderRole,
        ServerSpecialJunk1Role,
        ServerSpecialJunk2Role,
        ServerSpecialJunk3Role,
        ServerSpecialJunk4Role,
        ServerSpecialJunk5Role,

        IsAwg2Role
    };

    explicit AwgConfigModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void updateModel(mugen::DockerContainer container, const mugen::AwgProtocolConfig &protocolConfig);
    mugen::AwgProtocolConfig getProtocolConfig();
    bool isServerSettingsEqual();
    
    bool isHeadersEqual(const QString &h1, const QString &h2, const QString &h3, const QString &h4);
    bool isPacketSizeEqual(const int s1, const int s2, const int s3, const int s4);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    mugen::DockerContainer m_container;
    mugen::AwgProtocolConfig m_protocolConfig;
    mugen::AwgProtocolConfig m_originalProtocolConfig;
    
    void applyDefaultsToServerConfig(mugen::AwgServerConfig& config);
    void applyDefaultsToClientConfig(mugen::AwgClientConfig& config);
};

#endif // AWGCONFIGMODEL_H
