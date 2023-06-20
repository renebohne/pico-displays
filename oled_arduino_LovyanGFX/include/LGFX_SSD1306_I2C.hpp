#pragma once

#define LGFX_USE_V1
#include <LovyanGFX.hpp>

class LGFX_SSD1306 : public lgfx::LGFX_Device
{
    lgfx::Panel_SSD1306      _panel_instance;
    lgfx::Bus_I2C              _bus_instance;

  public:
    LGFX_SSD1306(void)
    {
      {
        auto cfg = _bus_instance.config();
        cfg.pin_scl = SCL;
        cfg.pin_sda = SDA;
        cfg.i2c_port = 1;
        cfg.i2c_addr = 0x3C;
        

        _bus_instance.config(cfg);
        _panel_instance.setBus(&_bus_instance);
      }

      {
        auto cfg = _panel_instance.config();
        cfg.panel_width      =   128;
        cfg.panel_height     =    64;
        cfg.offset_x         =     0;
        cfg.offset_y         =     0;
        cfg.offset_rotation  =     2;
        cfg.pin_rst = -1;
        cfg.pin_cs = -1;
        
        _panel_instance.config(cfg);
      }

      setPanel(&_panel_instance);
    }
};