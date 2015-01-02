//
//  StartScene.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#include "StartScene.h"
#include "../Layer/StartLayer.h"
#include "SimpleAudioEngine.h"


bool StartScene::init()
{

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images.plist", "Images.png");
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("C1.mp3", true);
    auto layer = StartLayer::create();
    this->m_startLayer = layer;
    this->addChild(layer);
    
    return true;
}
