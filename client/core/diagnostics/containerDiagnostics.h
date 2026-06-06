#ifndef CONTAINERDIAGNOSTICS_H
#define CONTAINERDIAGNOSTICS_H

namespace mugen
{
    struct ContainerDiagnostics
    {
        bool available = false;
        bool portReachable = false;

        virtual ~ContainerDiagnostics() = default;
    };

} // namespace mugen

#endif // CONTAINERDIAGNOSTICS_H
