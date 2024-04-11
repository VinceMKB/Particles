#include "particles.h"

Particle::Particle(int w_screen, int h_screen)
{
    position.x = GetRandomValue(0, w_screen - 1);
    position.y = GetRandomValue(0, h_screen - 1);
    velocity.x = GetRandomValue(-100, 100) / 50.f;
    velocity.y = GetRandomValue(-100, 100) / 50.f;
    //color = {0, 255, 0, 100};//Green
    color = {0, 64, 255, 100};//Blue

}

Particle::Particle(Vector2 m_postion, Vector2 m_velocity, Color m_color)
{
    
    position = m_postion;
    velocity = m_velocity;
    color = m_color;

}

float Particle::getDistance(Vector2 sec_position)
{
    const float x_diff = position.x - sec_position.x;
    const float y_diff = position.y - sec_position.y;

    return sqrt((x_diff*x_diff) + (y_diff*y_diff));
}

Vector2 Particle::getNormal(Vector2 sec_position)
{
    float distance = getDistance(sec_position);

    if(distance == 0.0f)
    {
        distance = 1;
    }

    const float x_diff = position.x - sec_position.x;
    const float y_diff = position.y - sec_position.y;

    Vector2 normal = {x_diff*(1/distance), y_diff*(1/distance)};

    return normal;
}

void Particle::Attract(Vector2 attract_to_position, float multiplier)
{
    
    float distance = fmax(getDistance(attract_to_position), 0.5);
    Vector2 normal = getNormal(attract_to_position);

    velocity.x -= normal.x/distance;
    velocity.y -= normal.y/distance;

}

void Particle::Friction(float amount)
{
    
    velocity.x *= amount;
    velocity.y *= amount;

}

void Particle::Move(int w_screen, int h_screen)
{
    
    position.x += velocity.x;
    position.y += velocity.y;

    if(position.x < 0)
    {
        position.x += w_screen;
    }

    if(position.x >= w_screen)
    {
        position.x -= w_screen;
    }

    if(position.y < 0)
    {
        position.y += h_screen;
    }

    if(position.y >= h_screen)
    {
        position.y -= h_screen;
    }
    
}

void Particle::Draw()
{
    DrawPixelV(position, color);
}