#include "points_on_screen.h"


points_on_screen::points_on_screen()
{
    
    particles = (Particle*)malloc(particleCount * sizeof(Particle));

}

points_on_screen::~points_on_screen()
{
    free(particles);
}

void points_on_screen::particle_init()
{
    for(long int i = 0;i < particleCount; i++)
    {
        particles[i] = Particle(screen_Width, screen_Height);
    }
}

void points_on_screen::physics(deque <Vector2> points)
{
    for(long int i = 0; i < particleCount; i++)
    {
        for(int j = 0; (float)j < points.size(); j++)
        {
            particles[i].Attract(points[j], 1);
        }
        
        particles[i].Friction(0.997);
        particles[i].Move(screen_Width, screen_Height);
    }
}

void points_on_screen::particles_Draw()
{
    for(int i = 0; i < particleCount; i++)
    {
        particles[i].Draw(i);
    }
}

void points_on_screen::circle_Draw()
{
    DrawCircleV(points_on_screen::circle_points(), 10 , BLACK);
}

Vector2 points_on_screen::circle_points()
{
    
    static float angle = 0.0f;
    const float speed = 0.01f;
    
    Vector2 circle_center = {screen_Width/2, screen_Height/2};
    float radius = 175.0f;

    angle += speed;

    float x = circle_center.x + radius *cosf(angle);
    float y = circle_center.y + radius *sinf(angle);
    
    Vector2 point_circle = {x, y};
    
    return point_circle;
}

void points_on_screen::presetOne()
{
    deque <Vector2> preset_one_points;

    Vector2 one_pos = {400, 225};
    preset_one_points.push_back(one_pos);
    Vector2 two_pos = {276.2563133, 523.7436867};
    preset_one_points.push_back(two_pos);
    Vector2 three_pos = {523.7436867, 523.7436867};
    preset_one_points.push_back(three_pos);
    Vector2 four_pos = points_on_screen::circle_points();
    preset_one_points.push_back(four_pos);

    points_on_screen::physics(preset_one_points);

}

