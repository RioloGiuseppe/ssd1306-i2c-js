# rf24js

![Support Node of LTS](https://img.shields.io/badge/node-LTS-brightgreen.svg?style=plastic) ![npm version](https://img.shields.io/badge/npm-3.5.0-brightgreen.svg?style=plastic) ![Build passing](https://img.shields.io/badge/build-passing_C++-brightgreen.svg?style=plastic) ![Build passing](https://img.shields.io/badge/build-passing%20Typescript-brightgreen.svg?style=plastic) ![Support](https://img.shields.io/badge/support-javascript%20|%20typescript-yellow.svg?style=plastic) ![dependencies nan](https://img.shields.io/badge/dependencies-NAN-blue.svg?style=plastic) ![License mit](https://img.shields.io/badge/license-MIT-blue.svg?style=plastic) ![tested](https://img.shields.io/badge/tested%20on-Raspberry%20Pi%20|%20Orange%20Pi-orange.svg?style=plastic)

---

# Description
Module ssd1306-i2c-js is a simple javascript wrapper of [vadzimyatskevich/SSD1306](https://github.com/vadzimyatskevich/SSD1306). No logic added, just existing methods wrapped.

# How to use

### Import in node js
Install library, simple run:
```sh
npm install --save ssd1306-i2c-js
```

### Use in your project
#### Typescript
```ts
import {display, Font, Color, Layer } from 'ssd1306-i2c-js'
```
#### Javascript
```js
var ssd1306 = require('ssd1306-i2c-js');
var display = ssd1306.display;
var Font = ssd1306.Font;
var Color = ssd1306.Color;
var Layer = ssd1306.Layer;
```
#### Configure and setup your display using init(i2cNumber, address) method.
Parameter *i2cNumber* is the mini-pc i2c bus name in `/dev/` in with is connected display.<br>
Parameter *address* is the i2c address of display driver ad specified in datasheet.

```js
display.init(1, 0x3C);      // Open bus and initialize driver
display.turnOn();           // Turn on display module
display.clearScreen();      // Clear display buffer
display.refresh();          // Write buffer in display registries
```

**Setup font**
```js
display.setFont(Font.UbuntuMono_8ptFontInfo);
```
Available fonts are defined in `Font` enum.

**Drawing functions**
Following function are available.
```js
display.drawPixel(x, y, color, layer);
display.drawLine(x, y, x1, y1, color, layer);
display.drawRect(x, y, w, h, color, layer);
display.fillRect(x, y, w, h, color, layer);
display.drawString(x:number, y:number, text, size, color, layer);
```

**Dispose i2c bus**
To close i2c bus call `dispose` function.
```js
process.on('SIGINT', function(){
    display.dispose();
    process.exit();
});
```