#ifndef QML_REGISTER_PROTOCOLS_H
#define QML_REGISTER_PROTOCOLS_H

#include "core/utils/protocolEnum.h"

#include <QObject>
#include <QDebug>
#include <QQmlEngine>

namespace mugen {

using namespace mugen::ProtocolEnumNS;

void declareQmlProtocolEnum() {
    qmlRegisterUncreatableMetaObject(
        ProtocolEnumNS::staticMetaObject,
        "ProtocolEnum",
        1, 0,
        "ProtocolEnum",
        "Error: only enums"
        );

    qmlRegisterUncreatableMetaObject(
        ProtocolEnumNS::staticMetaObject,
        "ProtocolEnum",
        1, 0,
        "TransportProto",
        "Error: only enums"
        );

    qmlRegisterUncreatableMetaObject(
        ProtocolEnumNS::staticMetaObject,
        "ProtocolEnum",
        1, 0,
        "ServiceType",
        "Error: only enums"
        );
}

} // namespace mugen

#endif // QML_REGISTER_PROTOCOLS_H
