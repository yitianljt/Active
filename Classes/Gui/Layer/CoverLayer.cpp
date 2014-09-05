//
//  CoverLayer.cpp
//  Active
//
//  Created by jintao on 14-9-4.
//
//

#include "CoverLayer.h"
#include "ComUtil.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CCActionManagerEx.h"
#include "editor-support/cocostudio/CCSGUIReader.h"

using namespace std;

USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;


bool CoverLayer::init()
{
    if (!Layer::init()) {
        return false;
    }

    _fWidth = COMWinSize().width/2;
    _fHeight = 0.75*COMWinSize().width/2;
    
    

    _menuLayer = Layer::create();
    _menuLayer->setVisible(false);
    addChild(_menuLayer);
    _LayerBtnStart = LayerColor::create(Color4B(101,233,232,255), _fWidth, _fHeight);
    _LayerBtnRecord = LayerColor::create(Color4B(70,187,242,255), _fWidth, _fHeight);
    _LayerBtnSet = LayerColor::create(Color4B(250,138,73,255), _fWidth, _fHeight);
    _LayerBtnComment = LayerColor::create(Color4B(159,213,111,255), _fWidth, _fHeight);
    
    _LayerBtnStart->setPosition(Point(0-_fWidth,_fHeight));
    _menuLayer->addChild(_LayerBtnStart);
    _LayerBtnRecord->setPosition(Point(_fWidth+_fWidth,_fHeight));
    _menuLayer->addChild(_LayerBtnRecord);
    _LayerBtnSet->setPosition(Point(0-_fWidth,0));
    _menuLayer->addChild(_LayerBtnSet);
    _LayerBtnComment->setPosition(Point(_fWidth+_fWidth,0));
    _menuLayer->addChild(_LayerBtnComment);

    
    
    return true;
}


void CoverLayer::onEnter()
{
    Layer::onEnter();
    showIn([]{});
}

void CoverLayer::onExit()
{
    Layer::onExit();
}

void CoverLayer::showIn(const function<void()> &aCall)
{
    _menuLayer->setVisible(true);
    MoveBy* moveByRight = MoveBy::create(0.3+0.3*CCRANDOM_0_1(), Point(_fWidth,0));
    ActionInterval * easeMoveByRight=EaseSineIn::create(moveByRight);
    
    MoveBy* moveByRight2 = MoveBy::create(0.3+0.3*CCRANDOM_0_1(), Point(_fWidth,0));
    ActionInterval * easeMoveByRight2=EaseSineIn::create(moveByRight2);
    
    MoveBy* moveByLeft = MoveBy::create(0.3+0.3*CCRANDOM_0_1(), Point(-_fWidth,0));
    ActionInterval * easeMoveByLeft=EaseSineIn::create(moveByLeft);
    
    MoveBy* moveByLeft2 = MoveBy::create(0.3+0.3*CCRANDOM_0_1(), Point(-_fWidth,0));
    ActionInterval * easeMoveByLeft2=EaseSineIn::create(moveByLeft2);
    
    _LayerBtnStart->runAction(easeMoveByRight);
    _LayerBtnSet->runAction(easeMoveByRight2);
    _LayerBtnRecord->runAction(easeMoveByLeft);
    _LayerBtnComment->runAction(easeMoveByLeft2);
    
    Sprite* spStartNor = Sprite::create("image/cover_btn_start.png");
    Sprite* spStartSel = Sprite::create("image/cover_btn_start.png");
    spStartSel->setColor(Color3B(150,150,150));
    MenuItemSprite* itemStrat = MenuItemSprite::create(spStartNor,spStartSel,[this](Ref* f){
        CCLOG("start game");
    });
    Menu* menuStart = Menu::create(itemStrat,nullptr);
    menuStart->setPosition(Point(_LayerBtnStart->getContentSize().width/2,_LayerBtnStart->getContentSize().height/2));
    _LayerBtnStart->addChild(menuStart);
    
    
    
    Sprite* spRecordNor = Sprite::create("image/cover_btn_record.png");
    Sprite* spRecordSel = Sprite::create("image/cover_btn_record.png");
    spRecordSel->setColor(Color3B(150,150,150));
    MenuItemSprite* itemRecord = MenuItemSprite::create(spRecordNor,spRecordSel,[this](Ref* f){
        CCLOG("start spRecordNor");
    });
    Menu* menuRecord = Menu::create(itemRecord,nullptr);
    menuRecord->setPosition(Point(_LayerBtnRecord->getContentSize().width/2,_LayerBtnRecord->getContentSize().height/2));
    _LayerBtnRecord->addChild(menuRecord);
    
    
    
    Sprite* spSetNor = Sprite::create("image/cover_btn_set.png");
    Sprite* spSetSel = Sprite::create("image/cover_btn_set.png");
    spSetSel->setColor(Color3B(150,150,150));
    MenuItemSprite* itemSet = MenuItemSprite::create(spSetNor,spSetSel,[this](Ref* f){
        CCLOG("start spSetSel");
    });
    Menu* menuSet = Menu::create(itemSet,nullptr);
    menuSet->setPosition(Point(_LayerBtnSet->getContentSize().width/2,_LayerBtnSet->getContentSize().height/2));
    _LayerBtnSet->addChild(menuSet);
    
    
    Sprite* spComNor = Sprite::create("image/cover_btn_comment.png");
    Sprite* spComSel = Sprite::create("image/cover_btn_comment.png");
    spStartSel->setColor(Color3B(150,150,150));
    MenuItemSprite* itemCom = MenuItemSprite::create(spComNor,spComSel,[this](Ref* f){
        CCLOG("start spComSel");
    });
    Menu* menuComment = Menu::create(itemCom,nullptr);
    menuComment->setPosition(Point(_LayerBtnComment->getContentSize().width/2,_LayerBtnComment->getContentSize().height/2));
    _LayerBtnComment->addChild(menuComment);
    
}

void CoverLayer::showOut(const function<void()> &aCall)
{
    
}