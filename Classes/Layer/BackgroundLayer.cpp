//
//  BackgroundLayer.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/21/14.
//
//

#include "BackgroundLayer.h"
#include "SimpleAudioEngine.h"
#include "../Scene/StartScene.h"
BackgroundLayer::BackgroundLayer()
:m_bg1(nullptr)
,m_bg2(nullptr){}
BackgroundLayer::~BackgroundLayer(){}
bool BackgroundLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    m_bg1 = Sprite::create("background.jpg");
    m_bg1->setPosition(Point(visibleSize.width * 0.5f, visibleSize.height * 0.5f));
    this->addChild(m_bg1);
    
    m_bg2 = Sprite::create("background.jpg");
    m_bg2->setPosition(Point(visibleSize.width * 0.5f, -visibleSize.height * 0.5f));
    this->addChild(m_bg2);
    
    auto border = Sprite::create("border.png");
    Size borderSize = border->getContentSize();
    
    auto border1 = createBorder(Point(borderSize.width * 0.5f, borderSize.height * 0.5f));
    this->addChild(border1);
    
    auto border2 = createBorder(Point(visibleSize.width - borderSize.width * 0.5f, borderSize.height * 0.5f));
    border2->setFlippedX(true);
    this->addChild(border2);
    
    auto border3 = createBorder(Point(visibleSize.width * 0.5f, borderSize.width * 0.5f));
    borderSize = border3->getContentSize();
    border3->setRotation(-90.0f);
    this->addChild(border3);
    
    
    
    auto border4 = createBorder(Point(visibleSize.width * 0.5f, visibleSize.height- borderSize.width * 0.5f));
    
    border4->setRotation(90.0f);
    
    this->addChild(border4);
    
    auto btnBack = CustomSprite::createWithPath("Back.png");
    
    btnBack->setScale(0.4f);

    btnBack->onTouchEnded = CC_CALLBACK_2(BackgroundLayer::back, this);
    
    btnBack->setPosition(Vec2(visibleSize - btnBack->getContentSize() / 2));
    btnBack->setPositionX(btnBack->getPositionX() + 20);
    this->addChild(btnBack);
    
    
    return true;
}



void BackgroundLayer::back(Touch  *touch, Event *event)
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    
    
    auto scene = StartScene::create();
    Director::getInstance()->replaceScene(scene);
    
}

Sprite* BackgroundLayer::createBorder(Point pos)
{
    auto border = Sprite::create("border.png");
    Size borderSize = border->getContentSize();
    auto body = PhysicsBody::createBox(borderSize);
    body->setDynamic(false);
    body->setCategoryBitmask(1);    // 0001
    body->setCollisionBitmask(1);   // 0001
    body->setContactTestBitmask(1); // 0001
    border->setPhysicsBody(body);
    border->setPosition(pos);
    return border;
    
    
}


void BackgroundLayer::logic(float dt) {
    int posY1 = m_bg1->getPositionY(); // 背景地图1的Y坐标
    int posY2 = m_bg2->getPositionY(); // 背景地图2的Y坐标
    int iSpeed = 3;    // 地图滚动速度
    /* 两张地图向上滚动（两张地图是相邻的，所以要一起滚动，否则会出现空隙） */
    posY1 += iSpeed;
    posY2 += iSpeed;
    /* 屏幕宽 */
    int iVisibleHeight = Director::getInstance()->getVisibleSize().height;
    /* 当第1个地图完全离开屏幕时，让第2个地图完全出现在屏幕上，同时让第1个地图紧贴在第2个地图后面 */
    if (posY1 > iVisibleHeight * 1.5f) {
        posY2 = iVisibleHeight * 0.5f;
        posY1 = -iVisibleHeight * 0.5f;
    }
    /* 同理，当第2个地图完全离开屏幕时，让第1个地图完全出现在屏幕上，同时让第2个地图紧贴在第1个地图后面 */
    if (posY2 > iVisibleHeight * 1.5f) {
        posY1 = iVisibleHeight * 0.5f;
        posY2 = -iVisibleHeight * 0.5f;
    }
    m_bg1->setPositionY(posY1);
    m_bg2->setPositionY(posY2);
}

