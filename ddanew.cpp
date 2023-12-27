#include <iostream>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2) {
    // Initialize variables
    int dx = x2 - x1;
    int dy = y2 - y1;
    float x, y, xInc, yInc;
    int steps;

    // Determine the number of steps to be taken
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    // Calculate increments in x and y
    xInc = float(dx) / steps;
    yInc = float(dy) / steps;

    // Set initial points
    x = x1;
    y = y1;

    // Draw the line
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xInc;
        y += yInc;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib");

    int x1, y1, x2, y2;

    // Input coordinates of the line
    std::cout << "Enter coordinates of the first point (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter coordinates of the second point (x2 y2): ";
    std::cin >> x2 >> y2;

    // Draw the line using DDA algorithm
    drawLineDDA(x1, y1, x2, y2);

    delay(5000);
    closegraph();

    return 0;
}

