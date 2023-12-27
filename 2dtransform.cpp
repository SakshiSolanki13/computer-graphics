#include <iostream>
#include <graphics.h>
#include <cmath>

void drawRectangle(int x, int y, int width, int height) {
    rectangle(x, y, x + width, y + height);
}

void translate(int &x, int &y, int tx, int ty) {
    x += tx;
    y += ty;
}

void rotate(int &x, int &y, double angle) {
    double radians = angle * (M_PI / 180.0);
    int newX = round(x * cos(radians) - y * sin(radians));
    int newY = round(x * sin(radians) + y * cos(radians));
    x = newX;
    y = newY;
}

void scale(int &x, int &y, double sx, double sy) {
    x = round(x * sx);
    y = round(y * sy);
}

void shear(int &x, int &y, double shx, double shy) {
    int newX = round(x + y * shx);
    int newY = round(y + x * shy);
    x = newX;
    y = newY;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib");


    int x = 100, y = 100, width = 50, height = 30;
    drawRectangle(x, y, width, height);

    
    translate(x, y, 50, 30);
    setcolor(RED);
    drawRectangle(x, y, width, height);

    
    rotate(x, y, 45);
    setcolor(GREEN);
    drawRectangle(x, y, width, height);

    
    scale(x, y, 2.0, 1.5);
    setcolor(BLUE);
    drawRectangle(x, y, width, height);

    shear(x, y, 0.5, 0);
    setcolor(CYAN);
    drawRectangle(x, y, width, height);

    delay(5000);
    closegraph();

    return 0;
}

