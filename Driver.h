///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __DRIVER_H__
#define __DRIVER_H__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ArduinoOTA.h>
#include <ArduinoJson.h>
#include "ESPixelStick.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct config_t;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Driver
{
public:
    virtual ~Driver() {};

    virtual int begin(const config_t *config) = 0;

    virtual uint8_t *getData() = 0;
    virtual void setValue(uint16_t address, uint8_t value) = 0;


    virtual void show() = 0;
    virtual bool canRefresh() = 0;
    virtual void refresh()
    {
        if (canRefresh())
            show();
    }

    virtual void setGamma(bool gamma) { };
    virtual void setOption(const String &name, int value) = 0;
    virtual void updateOrder(PixelColor color) { };

    virtual const String &name() const = 0;
};

extern Driver *driver;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DriverFactory
{

public:
    static Driver *create(const String &name);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // #ifndef __DRIVER_H__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
