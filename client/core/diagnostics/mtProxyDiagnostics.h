#ifndef MTPROXYDIAGNOSTICS_H
#define MTPROXYDIAGNOSTICS_H

#include "containerDiagnostics.h"

#include <QString>

namespace mugen {
    struct MtProxyDiagnostics : ContainerDiagnostics {
        bool upstreamReachable = false;
        int clientsConnected = -1;
        QString lastConfigRefresh;
        QString statsEndpoint;
    };

} // namespace mugen

#endif // MTPROXYDIAGNOSTICS_H
