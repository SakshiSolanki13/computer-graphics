#include <iostream>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm,(char*)"C:\\Program Files (x86)\\Dev-Cpp\\MinGW64\\lib\\libbgi.a"); 

    int left = 100;    // x-coordinate of the top-left corner
    int top = 100;     // y-coordinate of the top-left corner
    int right = 300;   // x-coordinate of the bottom-right corner
    int bottom = 200;  // y-coordinate of the bottom-right corner

    rectangle(left, top, right, bottom); // draw rectangle

    delay(5000); // pause for 5 seconds

    closegraph(); // close graphics mode

    return 0;
}

