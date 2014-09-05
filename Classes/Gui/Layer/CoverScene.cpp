//
//  CoverScene.cpp
//  Active
//
//  Created by jintao on 14-9-4.
//
//

#include "CoverScene.h"
#include "CoverLayer.h"
USING_NS_CC;

bool CoverScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    CoverLayer* coverLayer = CoverLayer::create();
    addChild(coverLayer);
    return true;
}

