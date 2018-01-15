import { Font } from './fonts';
import { Color } from './colors';
import { Layer } from './layers';
import 'node';
export interface Ioledjs {
    init(i2cNumber: number, address: number): void;
    dispose(): void;
    clearScreen(): void;
    refresh(): void;
    turnOn(): void;
    turnOff(): void;
    setFont(font: Font): void;
    drawPixel(x: number, y: number, color: Color, layer: Layer): void;
    drawChar(x: number, y: number, c: number, size: number, color: Color, layer: Layer): void;
    drawLine(x0: number, y0: number, x1: number, y1: number, color: Color, layer: Layer): void;
    drawRect(x: number, y: number, w: number, h: number, color: Color, layer: Layer): void;
    fillRect(x: number, y: number, w: number, h: number, color: Color, layer: Layer): void;
    drawString(x: number, y: number, text: string, size: number, color: Color, layer: Layer): void;
}
