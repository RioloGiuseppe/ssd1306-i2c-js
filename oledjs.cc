#include <nan.h>
#include <v8.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

#include "sources/ssd1306.h"

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

using namespace Nan;
using namespace v8;

extern FONT_INFO *_font;
extern int bus;

NAN_METHOD(InitModule)
{
    if (info.Length() == 2)
    {
        uint8_t ce = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        uint8_t addr = info[1]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        uint8_t i2c[] = "/dev/i2c-1";
        i2c[9] = 48 + ce;
        bus = i2c_init((char *)i2c, addr);
        ssd1306Init(SSD1306_SWITCHCAPVCC);
        ssd1306ClearScreen(LAYER0 | LAYER1);
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_METHOD(Dispose)
{
    close(bus);
}

NAN_METHOD(ClearScreen)
{
    ssd1306ClearScreen(LAYER0 | LAYER1);
}

NAN_METHOD(Refresh)
{
    ssd1306Refresh();
}

NAN_METHOD(TurnOn)
{
    ssd1306TurnOn();
}

NAN_METHOD(TurnOff)
{
    ssd1306TurnOff();
}

NAN_METHOD(SetFont)
{
    if (info.Length() == 1)
    {
        int16_t fontName = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        switch (fontName)
        {
        case 0:
            ssd1306SetFont((FONT_INFO *)&ubuntuMono_8ptFontInfo);
            break;
        case 1:
            ssd1306SetFont((FONT_INFO *)&ubuntuMono_10ptFontInfo);
            break;
        case 2:
            ssd1306SetFont((FONT_INFO *)&ubuntuMono_12ptFontInfo);
            break;
        case 3:
            ssd1306SetFont((FONT_INFO *)&ubuntuMono_16ptFontInfo);
            break;
        case 4:
            ssd1306SetFont((FONT_INFO *)&ubuntuMono_24ptFontInfo);
            break;
        case 5:
            ssd1306SetFont((FONT_INFO *)&ubuntuMono_48ptFontInfo);
            break;
        }
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_METHOD(DrawPixel)
{
    if (info.Length() == 4)
    {
        int16_t x = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t y = info[1]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t color = info[2]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t layer = info[3]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        ssd1306DrawPixel(x, y, color, layer);
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_METHOD(DrawLine)
{
    if (info.Length() == 6)
    {
        int16_t x0 = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t y0 = info[1]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t x1 = info[2]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t y1 = info[3]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t color = info[4]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t layer = info[5]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        ssd1306DrawLine(x0, y0, x1, y1, color, layer);
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_METHOD(FillRect)
{
    if (info.Length() == 6)
    {
        int16_t x = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t y = info[1]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t w = info[2]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t h = info[3]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t color = info[4]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t layer = info[5]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        ssd1306FillRect(x, y, w, h, color, layer);
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_METHOD(DrawRect)
{
    if (info.Length() == 6)
    {
        int16_t x = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t y = info[1]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t w = info[2]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t h = info[3]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t color = info[4]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t layer = info[5]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        ssd1306DrawRect(x, y, w, h, color, layer);
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_METHOD(DrawChar)
{
    if (info.Length() == 6)
    {
        int16_t x = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t y = info[1]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        uint8_t c = info[2]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        uint8_t size = info[3]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t color = info[4]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t layer = info[5]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        ssd1306DrawChar(x, y, c, size, color, layer);
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_METHOD(DrawString)
{
    if (info.Length() == 6)
    {
        int16_t x = info[0]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t y = info[1]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        if (!info[2]->IsString())
        {
            return Nan::ThrowTypeError("Text is not a string!");
        }
        Nan::Utf8String str(info[2]);
	int len = str.length();
	if (len <= 0) {
		return Nan::ThrowTypeError("Text must be a non-empty string.");
	}
        uint8_t size = info[3]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t color = info[4]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        int16_t layer = info[5]->Uint32Value(Nan::GetCurrentContext()).FromJust();
        ssd1306DrawString(x, y, (int8_t *)(*str), size, color, layer);
    }
    else
        return Nan::ThrowTypeError("Wrong argument number!");
}

NAN_MODULE_INIT(Init)
{
    Nan::Set(target, New<String>("init").ToLocalChecked(), GetFunction(New<FunctionTemplate>(InitModule)).ToLocalChecked());
    Nan::Set(target, New<String>("dispose").ToLocalChecked(), GetFunction(New<FunctionTemplate>(Dispose)).ToLocalChecked());
    Nan::Set(target, New<String>("clearScreen").ToLocalChecked(), GetFunction(New<FunctionTemplate>(ClearScreen)).ToLocalChecked());
    Nan::Set(target, New<String>("refresh").ToLocalChecked(), GetFunction(New<FunctionTemplate>(Refresh)).ToLocalChecked());
    Nan::Set(target, New<String>("turnOn").ToLocalChecked(), GetFunction(New<FunctionTemplate>(TurnOn)).ToLocalChecked());
    Nan::Set(target, New<String>("turnOff").ToLocalChecked(), GetFunction(New<FunctionTemplate>(TurnOff)).ToLocalChecked());
    Nan::Set(target, New<String>("drawPixel").ToLocalChecked(), GetFunction(New<FunctionTemplate>(DrawPixel)).ToLocalChecked());
    Nan::Set(target, New<String>("drawChar").ToLocalChecked(), GetFunction(New<FunctionTemplate>(DrawChar)).ToLocalChecked());
    Nan::Set(target, New<String>("drawLine").ToLocalChecked(), GetFunction(New<FunctionTemplate>(DrawLine)).ToLocalChecked());
    Nan::Set(target, New<String>("drawRect").ToLocalChecked(), GetFunction(New<FunctionTemplate>(DrawRect)).ToLocalChecked());
    Nan::Set(target, New<String>("fillRect").ToLocalChecked(), GetFunction(New<FunctionTemplate>(FillRect)).ToLocalChecked());
    Nan::Set(target, New<String>("drawString").ToLocalChecked(), GetFunction(New<FunctionTemplate>(DrawString)).ToLocalChecked());
    Nan::Set(target, New<String>("setFont").ToLocalChecked(), GetFunction(New<FunctionTemplate>(SetFont)).ToLocalChecked());
}

NODE_MODULE(oledjs, Init)
