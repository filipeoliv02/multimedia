#include "glm.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

void init();
void displayMe(void);
void desenhar_circunferencia(void);

typedef struct
{
    float x;
    float y;
} Ponto;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world");
    init();
    glutDisplayFunc(desenhar_circunferencia);
    glutMainLoop();
    return 0;
}

void init()
{
    glClearColor(0.0, 0.10, 0.15, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(1.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.6, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 1.0, 0.0);
    glEnd();
    glFlush();
}

void desenhar_circunferencia(void)
{
    int n = 50;
    float d, r;
    Ponto p0, p1, c;
    p0.x = p0.y = 0.0;
    p1.x = p1.y = 0.8;
    Ponto array1[n];
    float ang = (2 * M_PI / n);
    c.x = 0;
    c.y = 0;
    d = sqrt((pow((p1.x - p0.x), 2) + (pow((p1.y - p0.y), 2))));
    r = d / 2;
    float a = 0;
    for (int i = 0; i < n; i++)
    {

        array1[i].x = r * cos(a) + c.x;
        array1[i].y = r * sin(a) + c.y;
        a += ang;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.6, 0.0);
    glBegin(GL_POLYGON);

    for (int j = 0; j < n; j++)
    {
        glVertex2d(array1[j].x, array1[j].y);
        printf("%f, %f", array1[j].x, array1[j].y);
    }
    glEnd();
    glFlush();
}