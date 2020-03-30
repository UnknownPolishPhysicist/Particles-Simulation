#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <chrono>
#include "windows.h"
//#include <fstream>

static int counter=0;

void change(sf::RectangleShape** tab,int m_pos_x, int m_pos_y,int radius);

int main()
{
    int width=150;
    int height=150;
    int r=255;
    int g=0;
    int b=0;
    int m_pos_x=75;
    int m_pos_y=75;
    int radius = 1;

    //std::cout<<"Podaj rozmiar okienka [szerokosc]x[wysokosc]..."<<std::endl;
    //std::cin>>width;
    //std::cin>>height;

    sf::RectangleShape** tab = new sf::RectangleShape*[height];
    for(int i = 0; i < height; ++i)
    {
        tab[i] = new sf::RectangleShape[width];
    }
    /*
    std::ofstream plik("WYNIK.txt");
    if(!plik)
    {
        std::cout<<"Nie udalo sie otworzyc pliku";
        return 1;
    }
    */
    sf::RenderWindow okno;
    okno.create(sf::VideoMode(width,height),"Hejka");

    //auto start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            //int proportion = (int)j*255/height;
            tab[i][j].setSize(sf::Vector2f(1,1));
            tab[i][j].setFillColor(sf::Color::Red);
            tab[i][j].setPosition(i,j);
            //plik<<"j = "<<j<<" i = "<<i<<" Position ["<<tab[i][j].getPosition().x<<","<<tab[i][j].getPosition().y<<"] \n";
            counter++;
        }
    }

    //auto finish = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> elapsed = finish - start;
    //plik<< "Elapsed time: " << elapsed.count() << " s\n";
    //plik<<counter;

   while(okno.isOpen())
   {
       sf::Event zdarzenie;
       while(okno.pollEvent(zdarzenie))
       {
           if(zdarzenie.type==sf::Event::Closed)
           {
               okno.close();
           }

           if(zdarzenie.type==sf::Event::KeyReleased && zdarzenie.key.code==sf::Keyboard::Escape)
           {
               okno.close();
           }

           if(zdarzenie.type==sf::Event::KeyReleased && zdarzenie.key.code==sf::Keyboard::Enter)
           {
               okno.close();
           }

           if(zdarzenie.type==sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button==sf::Mouse::Right)
           {
               okno.close();
           }

       }
       okno.clear(sf::Color::Black);
       for(int i=0; i<height; i++)
       {
           for(int j=0;j<width;j++)
           {
              okno.draw(tab[i][j]);
           }
       }
       okno.display();
       //m_pos_x=(int)sf::Mouse::getPosition(okno).x;
       //m_pos_y=(int)sf::Mouse::getPosition(okno).y;
       change(tab,m_pos_x,m_pos_y,(++radius)%(width/2));
   }

    //plik.close();
    delete[] tab;
    return 0;
}

void change(sf::RectangleShape** tab,int m_pos_x, int m_pos_y,int radius)
{
    for(int y=0; y< 150; y++)
    {
       for(int x=0; x< 150; x++)
       {
           if((x - m_pos_x)*(x - m_pos_x) + (y - m_pos_y)*(y - m_pos_y) <= radius*radius) tab[x][y].setFillColor(sf::Color::Blue);
           else tab[x][y].setFillColor(sf::Color::Red);
       }
    }
}






////////////////////////////








#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <chrono>
#include "windows.h"
//#include <fstream>

static int counter=0;

void change(sf::RectangleShape**& tab,int m_pos_x, int m_pos_y,int radius);

int main()
{
    int width=150;
    int height=150;
    int r=255;
    int g=0;
    int b=0;
    int m_pos_x=0;
    int m_pos_y=0;

    //std::cout<<"Podaj rozmiar okienka [szerokosc]x[wysokosc]..."<<std::endl;
    //std::cin>>width;
    //std::cin>>height;

    sf::RectangleShape** tab = new sf::RectangleShape*[height];
    for(int i = 0; i < width; ++i)
    {
        tab[i] = new sf::RectangleShape[width];
    }
    /*
    std::ofstream plik("WYNIK.txt");
    if(!plik)
    {
        std::cout<<"Nie udalo sie otworzyc pliku";
        return 1;
    }
    */
    sf::RenderWindow okno;
    okno.create(sf::VideoMode(width,height,32),"Hejka");
    okno.setFramerateLimit(0);

    //auto start = std::chrono::high_resolution_clock::now();

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            //int proportion = (int)j*255/height;
            tab[i][j].setSize(sf::Vector2f(1,1));
            tab[i][j].setFillColor(sf::Color(r,g,b));
            tab[i][j].setPosition(i,j);
            //plik<<"j = "<<j<<" i = "<<i<<" Position ["<<tab[i][j].getPosition().x<<","<<tab[i][j].getPosition().y<<"] \n";
            counter++;
        }
    }

    //auto finish = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> elapsed = finish - start;
    //plik<< "Elapsed time: " << elapsed.count() << " s\n";
    //plik<<counter;

   while(okno.isOpen())
   {
       sf::Event zdarzenie;
       while(okno.pollEvent(zdarzenie))
       {
           if(zdarzenie.type==sf::Event::Closed)
           {
               okno.close();
           }

           if(zdarzenie.type==sf::Event::KeyReleased && zdarzenie.key.code==sf::Keyboard::Escape)
           {
               okno.close();
           }

           if(zdarzenie.type==sf::Event::KeyReleased && zdarzenie.key.code==sf::Keyboard::Enter)
           {
               okno.close();
           }

           if(zdarzenie.type==sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button==sf::Mouse::Right)
           {
               okno.close();
           }

       }

       okno.clear(sf::Color(0,0,0));
       for(int i=0; i<height; i++)
       {
           for(int j=0;j<width;j++)
           {
              okno.draw(tab[i][j]);
           }
       }

       //m_pos_x=(int)sf::Mouse::getPosition(okno).x;
       //m_pos_y=(int)sf::Mouse::getPosition(okno).y;

       m_pos_x = 75;
       m_pos_y = 75;

        if(m_pos_x<=width && m_pos_x>=0 && m_pos_y<=height && m_pos_y>=0)
        {
            //tab[m_pos_x][m_pos_y].setFillColor(sf::Color::White);
            int radius = 1;
            for(int i=0; i<width/2-1; i++)
            {
                change(*&tab,m_pos_x,m_pos_y,radius+i);
                Sleep(500);
            }
        }
       okno.display();
   }

    //plik.close();

    for(int i = 0; i < width; ++i)
    {
        delete[] tab[i];
    }

    delete[] tab;
    return 0;
}

void change(sf::RectangleShape**& tab,int m_pos_x, int m_pos_y,int radius)
{
    for(int y=-radius; y<=radius; y++)
    {
       for(int x=-radius; x<=radius; x++)
       {
          if(x*x+y*y <= radius*radius)
            tab[m_pos_x+x][m_pos_y+y].setFillColor(sf::Color::Blue);
       }
    }
}
