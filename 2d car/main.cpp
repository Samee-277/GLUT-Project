#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float playerX = -0.2f;
float roadOffset = 0.0f;
float speed = 0.015f;
const float MAX_SPEED = 0.04f;
int score = 0;
bool gameOver = false;


float obstacles[3][2] = {
    {-0.2f,  1.2f},
    { 0.2f,  1.8f},
    { 0.2f,  2.4f}
};


void drawScore(const char *text, float x, float y) {
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(text); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void resetGame() {
    score = 0;
    speed = 0.015f;
    playerX = -0.2f;
    obstacles[0][0] = -0.2f; obstacles[0][1] = 1.2f;
    obstacles[1][0] =  0.2f; obstacles[1][1] = 1.8f;
    obstacles[2][0] =  0.2f; obstacles[2][1] = 2.4f;
    gameOver = false;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.0f, 0.6f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f); glVertex2f(-0.5f, -1.0f);
        glVertex2f(-0.5f,  1.0f); glVertex2f(-1.0f,  1.0f);

        glVertex2f( 0.5f, -1.0f); glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  1.0f); glVertex2f( 0.5f,  1.0f);
    glEnd();


    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -1.0f); glVertex2f(0.5f, -1.0f);
        glVertex2f( 0.5f,  1.0f); glVertex2f(-0.5f, 1.0f);
    glEnd();


    glColor3f(1.0f, 1.0f, 1.0f);
    for (float y = -1.0f + roadOffset; y < 1.0f; y += 0.4f) {
        glBegin(GL_QUADS);
            glVertex2f(-0.02f, y);
            glVertex2f( 0.02f, y);
            glVertex2f( 0.02f, y + 0.2f);
            glVertex2f(-0.02f, y + 0.2f);
        glEnd();
    }


    glColor3f(1.0f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(playerX - 0.1f, -0.8f);
        glVertex2f(playerX + 0.1f, -0.8f);
        glVertex2f(playerX + 0.1f, -0.5f);
        glVertex2f(playerX - 0.1f, -0.5f);
    glEnd();


    glColor3f(0.6f, 0.2f, 0.7f);
    for (int i = 0; i < 3; i++) {
        glBegin(GL_QUADS);
            glVertex2f(obstacles[i][0] - 0.1f, obstacles[i][1] - 0.15f);
            glVertex2f(obstacles[i][0] + 0.1f, obstacles[i][1] - 0.15f);
            glVertex2f(obstacles[i][0] + 0.1f, obstacles[i][1] + 0.15f);
            glVertex2f(obstacles[i][0] - 0.1f, obstacles[i][1] + 0.15f);
        glEnd();
    }


    glColor3f(1.0f, 1.0f, 1.0f);
    char scoreStr[30];
    sprintf(scoreStr, "Score: %d", score);
    drawScore(scoreStr, 0.55f, 0.8f);

    if (gameOver) {
        drawScore("GAME OVER!", -0.2f, 0.1f);
        drawScore("Press 'R' to Restart", -0.3f, -0.1f);
    }

    glutSwapBuffers();
}

void update(int value) {
    if (!gameOver) {

        roadOffset -= speed;
        if (roadOffset < -0.4f) roadOffset = 0.0f;


        for (int i = 0; i < 3; i++) {
            obstacles[i][1] -= speed;


            if (obstacles[i][1] < -1.2f) {
                obstacles[i][1] = 1.2f + (rand() % 4) * 0.2f;
                score++;


                if (score % 3 == 0 && speed < MAX_SPEED) {
                    speed += 0.003f;
                }
            }


            if (playerX + 0.1f > obstacles[i][0] - 0.1f &&
                playerX - 0.1f < obstacles[i][0] + 0.1f &&
                -0.5f > obstacles[i][1] - 0.15f &&
                -0.8f < obstacles[i][1] + 0.15f) {
                gameOver = true;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

// Key Controls
void specialKeys(int key, int x, int y) {
    if (!gameOver) {
        if (key == GLUT_KEY_LEFT && playerX > -0.35f)  playerX -= 0.1f;
        if (key == GLUT_KEY_RIGHT && playerX < 0.35f) playerX += 0.1f;
    }
}

void keyboard(unsigned char key, int x, int y) {
    if ((key == 'r' || key == 'R') && gameOver) {
        resetGame();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2D Racing Car Game");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
