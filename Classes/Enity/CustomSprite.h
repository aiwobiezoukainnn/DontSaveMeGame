//
//  CustomSprite.h
//  DontSaveMe
//
//  Created by Mr Gan on 12/23/14.
//
//

#ifndef __DontSaveMe__CustomSprite__
#define __DontSaveMe__CustomSprite__

#include "cocos2d.h"
#include <string>
#include <stdio.h>
#include <functional>
USING_NS_CC;

class CustomSprite : public Sprite
{
public:
    CustomSprite();
    virtual ~CustomSprite(){}
    static CustomSprite* createWithPath(const std::string &path);
    static CustomSprite* createWithFrameName(const std::string &name);

    std::function<bool(Touch*, Event*)> onTouchBegan;
    std::function<void(Touch*, Event*)> onTouchMoved;
    std::function<void(Touch*, Event*)> onTouchEnded;
    std::function<void(Touch*, Event*)> onTouchCancelled;
protected:
    
    void addEventListener();
    virtual bool initWithFile(const std::string& filename) override;
    virtual bool initWithSpriteFrameName(const std::string &name) override;
    
};


#endif /* defined(__DontSaveMe__CustomSprite__) */

