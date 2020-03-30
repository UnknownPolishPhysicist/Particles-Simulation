#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>
#include "windows.h"
#include "particle.h"

int main()
{
    sf::Clock clock;
    const int width=900;
    const int height=900;
    int r=0;
    int g=0;
    int b=0;
    int n=2;  //number of particles
    int max_vel = 2;
    int radius = 2;

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, width);
    std::uniform_int_distribution<> distr2(-max_vel, max_vel);
    std::uniform_int_distribution<> distr_mass(1,3);
    std::uniform_int_distribution<> distr_color(0,255);  //random color every frame for each particle

    sf::CircleShape c(radius);

    std::vector<particle> vec1(n);
    vec1.shrink_to_fit();

    for(int i=0; i<(int)vec1.size(); i++) //(int)vec1.size() = circles.size() = n
           vec1[i] = particle(distr(eng),distr(eng),distr2(eng),distr2(eng),distr_mass(eng));

           //checking if collisions work
           vec1[0] = particle(100,200,1,0,1);
           vec1[1] = particle(700,200,0,0,1);
           //vec1[2] = particle(200,200,0,0,3);

    sf::RenderWindow okno;
    okno.create(sf::VideoMode(width,height),"Hejka");
    okno.setFramerateLimit(0);

   while(okno.isOpen())
   {
       sf::Event zdarzenie;
       while(okno.pollEvent(zdarzenie))
       {
           if((zdarzenie.type==sf::Event::Closed) || (zdarzenie.type==sf::Event::KeyReleased && zdarzenie.key.code==sf::Keyboard::Escape) || (zdarzenie.type==sf::Event::KeyReleased && zdarzenie.key.code==sf::Keyboard::Enter) || (zdarzenie.type==sf::Event::KeyReleased && zdarzenie.key.code==sf::Keyboard::Enter))
               okno.close();
       }

        for(int i=0; i<(int)vec1.size(); i++) //(int)vec1.size() = n    || for(auto &i:vec1) {}
        {
            //random walk

//            std::uniform_int_distribution<> distr_x(vec1[i].pos_x-1,vec1[i].pos_x+1);
//            std::uniform_int_distribution<> distr_y(vec1[i].pos_y-1,vec1[i].pos_y+1);
//            vec1[i].pos_x = distr_x(eng);
//            vec1[i].pos_y = distr_y(eng);

            //normal walk
            vec1[i].pos_x = vec1[i].pos_x + vec1[i].vel_x;
            vec1[i].pos_y = vec1[i].pos_y + vec1[i].vel_y;

            //boundary conditions
            if(vec1[i].pos_x >= width-max_vel || vec1[i].pos_x <= 1-max_vel)
                vec1[i].vel_x = -vec1[i].vel_x;

            if(vec1[i].pos_y >= height-max_vel || vec1[i].pos_y <= 1-max_vel)
                vec1[i].vel_y = -vec1[i].vel_y;


            //collisions between particles (primitive)
            for(int j=0; j<n; j++)
            {
                if(i!=j && (sqrt( (vec1[i].pos_x - vec1[j].pos_x)*(vec1[i].pos_x - vec1[j].pos_x) + (vec1[i].pos_y - vec1[j].pos_y)*(vec1[i].pos_y - vec1[j].pos_y) ) <=2*radius))
                {
//                    vec1[i].vel_x = - vec1[i].vel_x;
//                    vec1[i].vel_y = - vec1[i].vel_y;

//conserving momentum (in progress)
                      vec1[i].vel_x = (vec1[i].vel_x*(vec1[i].mass - vec1[j].mass) + 2*vec1[j].mass*vec1[j].vel_x) / (vec1[i].mass + vec1[j].mass) ;
                      vec1[i].vel_y = (vec1[i].vel_y*(vec1[i].mass - vec1[j].mass) + 2*vec1[j].mass*vec1[j].vel_y) / (vec1[i].mass + vec1[j].mass) ;
                      vec1[j].vel_x = (vec1[j].vel_x*(vec1[j].mass - vec1[i].mass) + 2*vec1[i].mass*vec1[i].vel_x) / (vec1[i].mass + vec1[j].mass) ;
                      vec1[j].vel_y = (vec1[j].vel_y*(vec1[j].mass - vec1[i].mass) + 2*vec1[i].mass*vec1[i].vel_y) / (vec1[i].mass + vec1[j].mass) ;
                }
            }

            Sleep(5/n);
        }

       okno.clear(sf::Color(r,g,b));
       for(int i=0; i<n; i++)
       {
           c.setPosition(vec1[i].pos_x,vec1[i].pos_y);
           c.setFillColor(sf::Color(255,0,0));
           okno.draw(c);
       }

       float fps = 1.f / clock.getElapsedTime().asSeconds();
       clock.restart();
       std::cout<<"FPS = "<<fps<<std::endl;
       okno.display();
   }

    return 0;
}
//LEFT TO FURTHER IMPLEMENTATION:

//MAKING AN ARRAY CONTAINING EVERY PIXEL (RECTANGLE SHAPE) SO IT CHANGES COLOR (ONCE OR COLOR(0,i++,0) ) EVERY TIME PARTICLE "STEPS" ON IT (DRAWING THE PATH OF RANDOM WALK)

//CONSERVING MOMENTUM

//GRAVITY BETWEEN EACH PARTICLE (MUCH COMPUTER POWER NEEDED)


//ctr+shift+c comments whole section
//ctrl+shift+x uncomments whole section


//sth is wrong with conserving momentum
