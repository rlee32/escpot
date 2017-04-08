#pragma once

#include <assert.h>


struct Component
{
    Component();
    static int TotalInstantiated;
    static int TotalSetup;
    static void CheckSetup();
    void setup() const;
};