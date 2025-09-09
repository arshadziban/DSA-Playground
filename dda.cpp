#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

int x1_in, y1_in, x2_in, y2_in;
float m;

void drawLineDDA() {
    float x1 = x1_in, y1 = y1_in, x2 = x2_in, y2 = y2_in;

    glPointSize(10.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);


    if (x2 == x1) {
        if (y1 < y2) {
            for (float i = y1; i <= y2; i += 1.0)
                glVertex2f(x1, i);
        } else {
            for (float i = y1; i >= y2; i -= 1.0)
                glVertex2f(x1, i);
        }
        glEnd();
        glFlush();
        return;
    }


    m = (y2 - y1) / (x2 - x1);

    if (fabs(m) < 1) {
        if (x1 < x2) {
            while (x1 <= x2) {
                glVertex2f(x1, y1);
                x1 = x1 + 1;
                y1 = y1 + m;
            }
        } else {
            while (x1 >= x2) {
                glVertex2f(x1, y1);
                x1 = x1 - 1;
                y1 = y1 - m;
            }
        }
    } else {

        if (y1 < y2) {
            while (y1 <= y2) {
                glVertex2f(x1, y1);
                y1 = y1 + 1;
                x1 = x1 + (1.0 / m);
            }
        } else {
            while (y1 >= y2) {
                glVertex2f(x1, y1);
                y1 = y1 - 1;
                x1 = x1 - (1.0 / m);
            }
        }
    }

    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawLineDDA();
}

void init2D() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1 x2 y2: ";
    cin >> x1_in >> y1_in >> x2_in >> y2_in;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("DDA");

    init2D();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
