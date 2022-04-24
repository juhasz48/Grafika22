#include "ball.h"

#include <GL/gl.h>

#include <math.h>

#include <stdlib.h>

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

int ball_speed = 300;

void init_ball(Ball* ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
    ball->radius = 50;
    ball->speed_x = 100;
    ball->speed_y = 100;
}

void set_ball_radius(Ball *ball, int radius)
{
    ball->radius = max(min(radius, 100), 30);
}

void set_ball_position(Ball *ball, int x, int y)
{
    ball->x = x;
    ball->y = y;
}

void stop_ball(Ball *ball)
{
    ball->speed_x = 0;
    ball->speed_y = 0;
}

void start_ball(Ball *ball)
{
    ball->speed_x = ball_speed;
    ball->speed_y = ball_speed;
}
void update_ball(Ball* ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
}

void render_ball(Ball* ball)
{
    double angle;
    double x;
    double y;

    glPushMatrix();
    glTranslatef(ball->x, ball->y, 0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.9, 0.8);
    glVertex2f(0, 0);
    angle = 0;
    while (angle < 2.0 * M_PI + 1) {
        x = cos(angle) * ball->radius;
        y = sin(angle) * ball->radius;
        glVertex2f(x, y);
        angle += 0.8;
    }
    glEnd();
    glPopMatrix();
}
