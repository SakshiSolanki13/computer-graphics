#include <iostream>
#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib");

    // Draw face
    circle(250, 200, 50); // Head

    // Draw eyes
    circle(235, 185, 5);  // Left eye
    circle(265, 185, 5);  // Right eye

    // Draw mouth (smile)
    arc(250, 200, 180, 0, 25);  // Start angle: 180, End angle: 0, Radius: 25

    getch();
    closegraph();

    return 0;
}

