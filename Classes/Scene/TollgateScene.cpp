#include "TollgateScene.h"
#include "../Layer/BackgroundLayer.h"
//#include "../Layer/TollgateLayer.h"
#include "../Layer/MonsterLayer.h"
#include "SimpleAudioEngine.h"




void TollgateScene::logic(float dt)
{
    m_backgroundLayer->logic(dt);
    m_monsterLayer->logic(dt);
    //m_tollgateLayer->logic(dt);
}

bool TollgateScene::init()
{
    if (!Scene::init())
    {
        return false;
    }
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();

    
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("C2.mp3", true);

    auto backgroundLayer = BackgroundLayer::create();
    this->addChild(backgroundLayer, 0);
    
    auto monsterLayer = MonsterLayer::create();
    this->addChild(monsterLayer);
//    auto layer = TollgateLayer::create();
//    this->addChild(layer);
    
    this->m_backgroundLayer = backgroundLayer;
    this->m_monsterLayer = monsterLayer;

 //  this->m_tollgateLayer = layer;
    
    this->schedule(schedule_selector(TollgateScene::logic));
    return true;
}

