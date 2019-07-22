#ifndef _CONTROLLER_INTERFACE_H_
#define _CONTROLLER_INTERFACE_H_

namespace ExMM
{
    struct ControllerInterface
    {
        virtual ~ControllerInterface() = default;
        virtual void DoHookRead(void* data, size_t offset) = 0;
        virtual void DoHookWrite(void* data, size_t offset) = 0;
        virtual HookTypes GetHookTypes() = 0;
    protected:
        ControllerInterface() = default;
    };

}

#endif
