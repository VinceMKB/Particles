#include "points_on_screen.h"


points_on_screen::points_on_screen()
{
    
    particles = (Particle*)malloc(particleCount * sizeof(Particle));
    squareState = initSquareMState();

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

void points_on_screen::physics(deque <Vector2> points, deque <float> attract_num)
{
    for(long int i = 0; i < particleCount; i++)
    {
        for(int j = 0; (float)j < points.size(); j++)
        {
            particles[i].Attract(points[j], attract_num[j]);
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

void points_on_screen::square_Draw()
{
    DrawCircleV(points_on_screen::square_points(), 5, RED);
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

Vector2 points_on_screen::square_points()
{
    updateSquareMState(squareState);
    return getCurrentPoint(squareState);
}

void points_on_screen::presetOne()
{
    deque <Vector2> preset_one_points;
    deque <float> at_one_points;

    Vector2 one_pos = {400, 225};
    float at_one_pos = 8;
    preset_one_points.push_back(one_pos);
    at_one_points.push_back(at_one_pos);

    Vector2 two_pos = {276.2563133, 523.7436867};
    float at_two_pos = 8;
    preset_one_points.push_back(two_pos);
    at_one_points.push_back(at_two_pos);

    Vector2 three_pos = {523.7436867, 523.7436867};
    float at_three_pos = 8;
    preset_one_points.push_back(three_pos);
    at_one_points.push_back(at_three_pos);


    Vector2 four_pos = points_on_screen::circle_points();
    float at_four_pos = 20;
    preset_one_points.push_back(four_pos);
    at_one_points.push_back(at_four_pos);

    points_on_screen::physics(preset_one_points, at_one_points);

}

void points_on_screen::presetTwo()
{
    deque <Vector2> preset_two_points;
    deque <float> at_two_points;

    Vector2 one_pos = {400, 400};
    float at_one_pos = 10;
    preset_two_points.push_back(one_pos);
    at_two_points.push_back(at_one_pos);

    Vector2 two_pos = {200, 200};
    float at_two_pos = 15;
    preset_two_points.push_back(two_pos);
    at_two_points.push_back(at_two_pos);

    Vector2 three_pos = {600, 600};
    float at_three_pos = 10;
    preset_two_points.push_back(three_pos);
    at_two_points.push_back(at_three_pos);

    Vector2 four_pos = points_on_screen::square_points();
    float at_four_pos = 30;
    preset_two_points.push_back(four_pos);
    at_two_points.push_back(at_four_pos);

    points_on_screen::physics(preset_two_points, at_two_points);
}

void points_on_screen::presetThree()
{

    deque <Vector2> preset_three_points;
    deque <float> at_three_points;

    Vector2 one_pos = {400, 400};
    float at_one_pos = 8;
    preset_three_points.push_back(one_pos);
    at_three_points.push_back(at_one_pos);

    Vector2 two_pos = {600, 200};
    float at_two_pos = 15;
    preset_three_points.push_back(two_pos);
    at_three_points.push_back(at_two_pos);

    Vector2 three_pos = {200, 600};
    float at_three_pos = 15;
    preset_three_points.push_back(three_pos);
    at_three_points.push_back(at_three_pos);

    points_on_screen::physics(preset_three_points, at_three_points);

}
