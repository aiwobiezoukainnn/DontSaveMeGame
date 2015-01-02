//  StartLayer.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/22/14.
//
//

#include "StartLayer.h"
#include "../Enity/CustomSprite.h"
#include "../Scene/TollgateScene.h"
StartLayer::StartLayer(){}
StartLayer::~StartLayer(){
    
}
bool StartLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Images.plist", "Images.pvr.ccz");
//    
//    auto texture = Director::getInstance()->getTextureCache()->getTextureForKey("Images.png");
//    
//    
//    auto spriteBatch = SpriteBatchNode::createWithTexture(texture);
//    addChild(spriteBatch);
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto orign = Director::getInstance()->getVisibleOrigin();
    auto bg = Sprite::create("LittleGirl.jpg");
    bg->setPosition(Vec2(orign + visibleSize / 2));
    this->addChild(bg);
    
    auto start =  CustomSprite::createWithPath("StartButton.jpg");
    start->setPosition(Vec2(start->getContentSize().width / 2 + 20, visibleSize.height / 2));

    
    start->onTouchEnded = CC_CALLBACK_2(StartLayer::onBeginTouchStartButton, this);
    addChild(start);
    auto exit = CustomSprite::createWithPath("ExitButton.jpg");
    exit->setPosition(Vec2(start->getPositionX(), start->getPositionY() - 70));

    exit->onTouchEnded =  CC_CALLBACK_2(StartLayer::onBeginTouchExitButton, this);
    addChild(exit);

    
    return true;
}


void StartLayer::onBeginTouchStartButton(Touch* touch, Event* event)
{
    
    StartGame(nullptr);
}

void StartLayer::onBeginTouchExitButton(Touch* touch, Event* event)
{
   ExitGame(nullptr);

}


void StartLayer::StartGame(cocos2d::Ref *ref)
{
    
    auto tollScene = TollgateScene::create();
    Director::getInstance()->replaceScene(tollScene);
    
}

void StartLayer::ExitGame(cocos2d::Ref *ref)
{
    
    Director::getInstance()->end();
    
}


void StartLayer::logic(float dt) {
   
}

