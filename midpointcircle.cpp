#include <iostream>
#include <graphics.h>

void drawCircleMidpoint(int xc, int yc, int r) {
    int x = r, y = 0;
    int p = 1 - r;
    putpixel(xc + x, yc - y, WHITE);

    while (x > y) {
        y++;

        if (p <= 0)
            p = p + 2*y + 1;
    
        else {
            x--;
            p = p + 2*y - 2*x + 1;
        }


        if (x < y)
            break;

        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);

        if (x != y) {
            putpixel(xc + y, yc - x, WHITE);
            putpixel(xc - y, yc - x, WHITE);
            putpixel(xc + y, yc + x, WHITE);
            putpixel(xc - y, yc + x, WHITE);
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib");

    int xc, yc, r;

    // Input coordinates of the center and radius of the circle
    std::cout << "Enter coordinates of the center (xc yc): ";
    std::cin >> xc >> yc;

    std::cout << "Enter radius of the circle: ";
    std::cin >> r;

    drawCircleMidpoint(xc, yc, r);

    delay(5000);
    closegraph();

    return 0;
}

