#include <iostream>
#include <graphics.h>
#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#define X_MIN 100
#define Y_MIN 100
#define X_MAX 400
#define Y_MAX 300

int computeRegionCode(int x, int y) {
    int code = INSIDE;

    if (x < X_MIN)      
        code |= LEFT;
    else if (x > X_MAX) 
        code |= RIGHT;

    if (y < Y_MIN)      
        code |= BOTTOM;
    else if (y > Y_MAX) 
        code |= TOP;

    return code;
}

void cohenSutherlandLineClip(int x1, int y1, int x2, int y2) {
    int code1, code2, code;
    int accept = 0;
    int x, y;

    while (true) {
        code1 = computeRegionCode(x1, y1);
        code2 = computeRegionCode(x2, y2);

        if (code1 == 0 && code2 == 0) {
            accept = 1;
            break;
        }
    
        else if (code1 & code2) {
            break;
        }
        
        else {
            int code_out = (code1 != 0) ? code1 : code2;

            
            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            
            if (code_out == code1) {
                x1 = x;
                y1 = y;
            } else {
                x2 = x;
                y2 = y;
            }
        }
    }

    if (accept) {
       
        setcolor(RED);
        line(x1, y1, x2, y2);
        setcolor(WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib");

    int x1, y1, x2, y2;

 
    std::cout << "Enter coordinates of the line segment (x1 y1 x2 y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    setcolor(WHITE);
    line(x1, y1, x2, y2);

    cohenSutherlandLineClip(x1, y1, x2, y2);

    delay(5000);
    closegraph();

    return 0;
}

