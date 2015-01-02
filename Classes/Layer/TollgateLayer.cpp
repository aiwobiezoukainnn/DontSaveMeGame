//
//  TollgateLayer.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/24/14.
//
//

#include "TollgateLayer.h"

TollgateLayer::TollgateLayer()
{
}
TollgateLayer::~TollgateLayer()
{
}

bool TollgateLayer::init()
{
    if (!Node::init())
    {
        return false;
        
    }
    
    auto sprite = cocos2d::Sprite::create("player.png");
    auto pos = Director::getInstance()->getVisibleMiddle();
    sprite->setPosition(pos);
    addChild(sprite);

    return true;
    
}


void TollgateLayer::logic(float dt)
{
    
}
