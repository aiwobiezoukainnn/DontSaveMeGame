//
//  SplashScene.cpp
//  DontSaveMeGame
//
//  Created by Mr Gan on 1/2/15.
//
//

#include"SplashScene.h"
#include "StartScene.h"

SplashScene::SplashScene()
{
}
SplashScene::~SplashScene()
{
}

bool SplashScene::init()
{
    

    if (!Scene::init())
    {
        return false;
    }
    
    auto splash = Sprite::create("Splash.png");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    splash->setPosition(visibleSize / 2);
    addChild(splash);
    
    this->schedule(schedule_selector(SplashScene::update), 1, 1, 0);

    
    return true;
    
}

void SplashScene::update(float dt)
{
    
    auto scene = StartScene::create();
    Director::getInstance()->replaceScene(scene);
}



