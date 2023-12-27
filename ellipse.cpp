#include <iostream>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\libbgi.a");

    int x = getmaxx() / 2;
    int y = getmaxy() / 2;

    int rx = 100; // major axis radius
    int ry = 50;  // minor axis radius

    ellipse(x, y, 0, 360, rx, ry); // draw ellipse

    delay(5000); // pause for 5 seconds

    closegraph(); // close graphics mode

    return 0;
}

