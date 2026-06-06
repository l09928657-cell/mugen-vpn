#ifndef OPENVPNCONFIGMODEL_H
#define OPENVPNCONFIGMODEL_H

#include <QAbstractListModel>

#include "core/utils/containerEnum.h"
#include "core/utils/containers/containerUtils.h"
#include "core/utils/protocolEnum.h"
#include "core/models/protocols/openVpnProtocolConfig.h"

class OpenVpnConfigModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        SubnetAddressRole = Qt::UserRole + 1,
        TransportProtoRole,
        PortRole,
        AutoNegotiateEncryprionRole,
        HashRole,
        CipherRole,
        TlsAuthRole,
        BlockDnsRole,
        AdditionalClientCommandsRole,
        AdditionalServerCommandsRole,

        IsPortEditable,
        IsTransportProtoEditable,

        HasRemoveButton
    };

    explicit OpenVpnConfigModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void updateModel(mugen::DockerContainer container, const mugen::OpenVpnProtocolConfig &protocolConfig);
    mugen::OpenVpnProtocolConfig getProtocolConfig();

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    mugen::DockerContainer m_container;
    mugen::OpenVpnProtocolConfig m_protocolConfig;
    mugen::OpenVpnProtocolConfig m_originalProtocolConfig;
    
    void applyDefaultsToServerConfig(mugen::OpenVpnServerConfig& config);
    void applyDefaultsToClientConfig(mugen::OpenVpnClientConfig& config);
};

#endif // OPENVPNCONFIGMODEL_H
