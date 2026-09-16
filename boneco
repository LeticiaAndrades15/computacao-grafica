#include <GL/glut.h>
#include <math.h>

int estado = -1;

// Desenha um bloco 3D
void Cubo(float x1, float x2,
          float y1, float y2,
          float z1, float z2) {

    glBegin(GL_QUADS);

        // Frente
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y2, z1);
        glVertex3f(x1, y2, z1);

        // Trás
        glVertex3f(x1, y1, z2);
        glVertex3f(x1, y2, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y1, z2);

        // Esquerda
        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y1, z2);
        glVertex3f(x1, y2, z2);
        glVertex3f(x1, y2, z1);

        // Direita
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y2, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y1, z2);

        // Cima
        glVertex3f(x1, y2, z1);
        glVertex3f(x1, y2, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y2, z1);

        // Baixo
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y1, z2);
        glVertex3f(x1, y1, z2);

    glEnd();
}


void Head() {
    glColor3f(0.0f, 0.8f, 0.7f);

    Cubo(
        -0.39f, 0.39f,
         1.0f, 1.86f,
        -0.25f, 0.25f
    );
}


void Belly() {
    glColor3f(1.0f, 0.2f, 0.6f);

    Cubo(
        -0.5f, 0.5f,
        -1.0f, 1.0f,
        -0.3f, 0.3f
    );
}


void RightArm() {
    glColor3f(0.0f, 0.8f, 0.7f);

    Cubo(
         0.5f, 0.9f,
        -1.0f, 1.0f,
        -0.2f, 0.2f
    );
}


void LeftArm() {
    glColor3f(0.0f, 0.8f, 0.7f);

    Cubo(
        -0.9f, -0.5f,
        -1.0f, 1.0f,
        -0.2f, 0.2f
    );
}


void RightLeg() {
    glColor3f(0.55f, 0.0f, 0.8f);

    Cubo(
         0.0f, 0.5f,
        -3.0f, -1.0f,
        -0.25f, 0.25f
    );
}


void LeftLeg() {
    glColor3f(0.55f, 0.0f, 0.8f);

    Cubo(
        -0.5f, 0.0f,
        -3.0f, -1.0f,
        -0.25f, 0.25f
    );
}

float posX = 0.0f;
float posY = 0.0f;

float angle = 0.0f;
float escala = 0.25f;
bool espelhado = false;
char operacao = 't';


void operacoes(unsigned char tecla, int x , int y){

    if (estado == 0){
        switch ( tecla ) {
        case GLUT_KEY_UP:     
            posY += 0.1f;
            break;
        case GLUT_KEY_DOWN:   
            posY -= 0.1f;
            break;
        case GLUT_KEY_RIGHT:  
            posX += 0.1f;
            break;
        case GLUT_KEY_LEFT:  
            posX -= 0.1f;
            break;
        default:
            break;
        }

    }else if (estado == 1){
        switch ( tecla ) {
        case GLUT_KEY_UP:     
            angle += 0.1f;
            break;
        case GLUT_KEY_DOWN:  
            angle -= 0.1f;
            break;
        default:
            break;
        }

    }else if (estado == 2){
        switch ( tecla ) {
        case GLUT_KEY_UP:     
            escala += 0.1f;
            break;
        case GLUT_KEY_DOWN:  
            escala -= 0.1f;
            break;
        default:
            break;
        }
    }

    glutPostRedisplay();
    
}


void teclado(int tecla, int , int ) {
    if( operacao == 't'){
        estado = 0;        
    }else if(operacao == 'r'){
        estado = 1;
    }else if(operacao == 's'){
        estado = 2;
    }
    glutPostRedisplay();
}




void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(posX, posY, 0.0f);

    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glScalef(espelhado ? escala : -escala, escala, escala);

    glPushMatrix();

        LeftLeg();
        RightLeg();

        LeftArm();
        RightArm();

        Head();
        Belly();

    glPopMatrix();

    glutSwapBuffers();
}


void reshape(int largura, int altura) {

    if (altura == 0)
        altura = 1;

    glViewport(0, 0, largura, altura);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(
        45.0,
        (float)largura / altura,
        0.1,
        100.0
    );

    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {

    glutInit(&argc, argv);

    // Double buffer + RGB + Depth
    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(800, 600);

    glutCreateWindow("Personagem 3D");

    // Ativa o teste de profundidade
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(operacoes);
    glutSpecialFunc(teclado);
    // Configura a perspectiva quando a janela muda de tamanho

    glutMainLoop();

    return 0;
}
