//
//  Player.cpp
//  DontSaveMe
//
//  Created by Mr Gan on 12/21/14.
//
//

#include "Player.h"
#include "Player.h"
Player::Player()
{
    m_iHP = 100;
}
Player::~Player()
{
}


void Player::moveToRight()
{
    this->getPhysicsBody()->applyImpulse(Vect(50000, 0));
}
void Player::moveToLeft()
{
    this->getPhysicsBody()->applyImpulse(Vect(-50000, 0));
    
}
void Player::quickMove()
{
    this->getPhysicsBody()->applyImpulse(Vect(0, -200000));
    
}

void  Player::beAtked(int n)
{
    
}


bool Player::init()
{

    this->setTag(ObjectTag_Player);
    auto playerSp = Sprite::create("player.png");
    this->addChild(playerSp);
    auto body = PhysicsBody::createCircle(playerSp->getContentSize().width * 0.4f);
    body->getShape(0)->setFriction(0);
    body->getShape(0)->setRestitution(1.0f);
    body->setCategoryBitmask(1);    // 0001
    body->setCollisionBitmask(1);   // 0001
    body->setContactTestBitmask(1); // 0001
    this->setPhysicsBody(body);
    /* 给角色添加推力 */
    this->getPhysicsBody()->applyImpulse(Vect(0, -40000));
    return true;
}
void Player::logic(float dt)
{
}
