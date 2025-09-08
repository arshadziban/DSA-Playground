#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

int x1_in, y1_in, x2_in, y2_in;

void bresenham_algo(int x1, int y1, int x2, int y2) {
int dx = x2 - x1;
int dy = y2 - y1;
int p  = 2*dy - dx;

int x = x1, y = y1;


while (x <= x2) {
        glVertex2i(x, y);



if (p < 0) {
x = x + 1;
p = p + 2*dy;
 } else {
 x = x + 1;
y = y + 1;
p = p + 2*dy - 2*dx;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glPointSize(3.0f);

    glBegin(GL_POINTS);
bresenham_algo(x1_in, y1_in, x2_in, y2_in);
    glEnd();

    glFlush();
}

void init2D() {
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    cout << "Enter x1 y1: ";
    cin >> x1_in >> y1_in;
    cout << "Enter x2 y2: ";
    cin >> x2_in >> y2_in;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bresenham (your logic)");
    init2D();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
