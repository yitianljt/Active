//
//  SelectScene.cpp
//  Active
//
//  Created by jintao on 14-9-6.
//
//

#include "SelectScene.h"
#include "SelectLayer.h"
USING_NS_CC;

bool SelectScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    SelectLayer* coverLayer = SelectLayer::create();
    addChild(coverLayer);
    return true;
}