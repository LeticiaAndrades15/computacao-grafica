#include <GL/glut.h>
#include <math.h>

void desenhaAsaEsquerda(){
    glBegin(GL_TRIANGLES); 
        glColor3f(0.55f, 0.0f, 0.8f);      
        glVertex2f(-0.5f, -1.0f);
        glVertex2f(-0.5f, -0.2f);
        glVertex2f(-0.8f, -1.0f);
    glEnd();
}

void desenhaAsaDireita(){
    glBegin(GL_TRIANGLES); 
        glColor3f(0.55f, 0.0f, 0.8f);
        glVertex2f(0.5f, -1.0f);
        glVertex2f(0.5f, -0.2f);
        glVertex2f(0.8f, -1.0f);
    glEnd();
}

void desenhaBico(){
    glBegin(GL_TRIANGLES); 
        glColor3f(0.0f, 0.8f, 0.7f);       
        glVertex2f(-0.5f, 1.0f);
        glVertex2f(0.5f, 1.0f);
        glVertex2f(0.0f, 2.0f);
    glEnd();
}

void desenhaCorpo(){
    glBegin(GL_QUADS);
        glColor3f(1, 0.2, 0.6); 
        glVertex2f(-0.5f, -1.0f);
        glVertex2f(0.5f, -1.0);
        glVertex2f(0.5f, 1.0f);
        glVertex2f(-0.5f, 1.0f);        
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

        float tempo = glutGet(GLUT_ELAPSED_TIME) * 0.004f;

        glTranslatef(0.0f, tempo * 0.2f - 1.0f, 0.0f);

        glScalef(0.2f, 0.2f, 0.2f);

        desenhaCorpo();
        desenhaBico();
        desenhaAsaEsquerda();
        desenhaAsaDireita();
    glPopMatrix();
 
    glFlush();

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);    
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
