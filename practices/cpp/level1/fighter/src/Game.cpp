#include "Game.h"

Game::Game(World* world)
{
    //ctor
    this->world=world;
}

Game::~Game()
{
    //dtor
}

void Game::play_music()
{
    BGM.play();
}

void Game::pause_music()
{
    BGM.stop();
}

void Game::init()
{
    world->hero->setPosition(400,400);
    world->window->clear();
    world->hero->init();
}

void Game::MainLoop()
{
//    this->play_music();
     while (world->window->isOpen())
     {
         sf::Event event;
         if(this->world->loading==true) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    if(this->world->hero->getPosition().x>0){
                        world->hero->move(sf::Vector2<float>(-1.0,0.0));
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    if(this->world->hero->getPosition().x<this->world->getTextureRect().width-430){
                        world->hero->move(sf::Vector2<float>(1.0,0.0));
                    }
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ){
                    if(this->world->hero->getPosition().y>0){
                        world->hero->move(sf::Vector2<float>(0.0,-1.0));
                    }
                }


                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ){
                    if(this->world->hero->getPosition().y<(this->world->window->getSize().y-this->world->hero->getGlobalBounds().height)){
                        world->hero->move(sf::Vector2<float>(0.0,1.0));
                    }
                }
         }

         while (world->window->pollEvent(event)){

            if (event.type == sf::Event::Closed){
                world->window->close();

                return ;
            }
         }

         world->Refresh();
         world->window->display();
     }
}