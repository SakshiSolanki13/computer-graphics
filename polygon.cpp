#include <iostream>
#include <graphics.h>

// Define window coordinates
#define X_MIN 100
#define Y_MIN 100
#define X_MAX 400
#define Y_MAX 300

// Define clipping edge codes
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Function to compute the region code for a point (x, y)
int computeRegionCode(int x, int y) {
    int code = 0;

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

void sutherlandHodgmanPolygonClip(int clipEdges[], int &n, int x[], int y[]) {
    int outVerticesX[100], outVerticesY[100];
    int outCount = n;

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;

        int x1 = x[i];
        int y1 = y[i];
        int x2 = x[next];
        int y2 = y[next];

        int code1 = computeRegionCode(x1, y1);
        int code2 = computeRegionCode(x2, y2);

        
        if ((code1 | code2) == 0) {
            outVerticesX[outCount] = x2;
            outVerticesY[outCount] = y2;
            outCount++;
        }
      
        else {
            
            for (int j = 0; j < 4; j++) {
                if ((clipEdges[j] & code1) && (clipEdges[j] & code2)) {
                    
                    int xNew, yNew;
                    if (clipEdges[j] == LEFT) {
                        xNew = X_MIN;
                        yNew = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                    } else if (clipEdges[j] == RIGHT) {
                        xNew = X_MAX;
                        yNew = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                    } else if (clipEdges[j] == BOTTOM) {
                        xNew = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                        yNew = Y_MIN;
                    } else if (clipEdges[j] == TOP) {
                        xNew = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                        yNew = Y_MAX;
                    }

                    outVerticesX[outCount] = xNew;
                    outVerticesY[outCount] = yNew;
                    outCount++;
                }
            }
        }
    }

    
    n = outCount;
    for (int i = 0; i < n; i++) {
        x[i] = outVerticesX[i];
        y[i] = outVerticesY[i];
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Dev-Cpp\\MinGW64\\lib");

    int n;

    
    std::cout << "Enter the number of vertices of the polygon: ";
    std::cin >> n;

    int x[100], y[100]
    
    std::cout << "Enter the coordinates of the polygon vertices (x y): ";
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }


    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    setcolor(WHITE);
    drawpoly(n, x);

 
    int clipEdges[] = {LEFT, RIGHT, BOTTOM, TOP};
    sutherlandHodgmanPolygonClip(clipEdges, n, x, y);
    setcolor(RED);
    drawpoly(n, x);

    delay(5000);
    closegraph();

    return 0;
}

