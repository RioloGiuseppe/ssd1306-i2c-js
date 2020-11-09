"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.display = exports.Layer = exports.Color = exports.Font = void 0;
var fonts_1 = require("./fonts");
Object.defineProperty(exports, "Font", { enumerable: true, get: function () { return fonts_1.Font; } });
var colors_1 = require("./colors");
Object.defineProperty(exports, "Color", { enumerable: true, get: function () { return colors_1.Color; } });
var layers_1 = require("./layers");
Object.defineProperty(exports, "Layer", { enumerable: true, get: function () { return layers_1.Layer; } });
exports.display = require('bindings')('oledjs.node');
//# sourceMappingURL=index.js.map