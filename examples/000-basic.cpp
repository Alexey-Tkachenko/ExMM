#include "../utilities/examples-registry.hpp"
#include <iostream>

#include "../src/exmm.hpp"

using namespace ExMM;

volatile struct Registers
{
    volatile int A;
    volatile int B;
    volatile int C;
};

struct Controller000 final : public ControllerBase<HookTypes::None, Registers>
{
};

EXMM_DEMO(Basic)
{
    output << "Basic demo - no hooks" << std::endl;

    const Controller000 controller;
    auto *registers = controller.GetIoSpace();

    ExMM::Run([registers]() {        
        registers->A = 42;
    });
    return registers->A == 42;
}
