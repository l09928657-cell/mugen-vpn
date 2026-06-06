#ifndef TELEMTDIAGNOSTICS_H
#define TELEMTDIAGNOSTICS_H

#include "containerDiagnostics.h"

#include <QString>

namespace mugen
{
    struct TelemtDiagnostics : ContainerDiagnostics
    {
        bool upstreamReachable = false;
        int clientsConnected = -1;
        QString lastConfigRefresh;
        QString statsEndpoint;
    };

} // namespace mugen

#endif // TELEMTDIAGNOSTICS_H
