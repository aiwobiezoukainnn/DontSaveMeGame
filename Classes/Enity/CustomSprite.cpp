//
//  CustomSprite.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/23/14.
//
//

#include "CustomSprite.h"

CustomSprite::CustomSprite()
:onTouchBegan(nullptr)
,onTouchMoved(nullptr)
,onTouchCancelled(nullptr)
,onTouchEnded(nullptr)
{
    addEventListener();
}

 CustomSprite *CustomSprite::createWithPath(const std::string &path)
{
    auto sprite = new  CustomSprite();
    if(sprite && sprite->initWithFile(path))
    {
        sprite->autorelease();
        return  sprite;
    }
    else
    {
        CC_SAFE_DELETE(sprite);
        return nullptr;
    }
        
}


CustomSprite* CustomSprite::createWithFrameName(const std::string &name)
{
    auto sprite = new  CustomSprite();
    if(sprite && sprite->initWithSpriteFrameName(name))
    {
        sprite->autorelease();
        return  sprite;
    }
    else
    {
        CC_SAFE_DELETE(sprite);
        return nullptr;
    }
    
    
}

bool CustomSprite::initWithSpriteFrameName(const std::string &name)
{
    if(!Sprite::initWithSpriteFrameName(name))
    {
        return false;
        
    }
        
    
    return true;
}

void CustomSprite::addEventListener()
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        cocos2d::Vec2 p = touch->getLocation();
        
        cocos2d::Rect rect = this->getBoundingBox();
        if(rect.containsPoint(p))
        {
            if(onTouchBegan)
                onTouchBegan(touch, event);
            return true; // to indicate that we have consumed it.
        }
        
        return false; // we did not consume this event, pass thru.
    };
    
    
    listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        if(onTouchEnded)
            onTouchEnded(touch, event);
    };

    
    listener->onTouchCancelled = [=](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        if(onTouchCancelled)
            onTouchCancelled(touch, event);
    };
    

    
    
    listener->onTouchMoved = [=](cocos2d::Touch* touch, cocos2d::Event* event)
    {
        if(onTouchMoved)
            onTouchMoved(touch, event);
    };
    
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    

}


bool CustomSprite::initWithFile(const std::string& filename)
{
    if(!Sprite::initWithFile(filename))
    {
        return false;
    }
    
    return true;
    
}


