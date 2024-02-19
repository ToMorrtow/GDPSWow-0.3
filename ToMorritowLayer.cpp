#include "includes.h"
#include "mod_utils.hpp"
#include "gd.h"
#include "ToMorritowLayerc.hpp"

CCRepeatForever* Layer2Waos::getscaleact(float time, float scale)
{
    return CCRepeatForever::create(
        CCSequence::create(
            CCEaseInOut::create(CCScaleTo::create(time, scale), 2.0),
            CCDelayTime::create(0.1),
            CCEaseInOut::create(CCScaleBy::create(time, scale-0.2), 2.0),
            CCDelayTime::create(0.1),
            nullptr
        ));
}

CCRepeatForever* Layer2Waos::getfadeact(float time, GLubyte vally1, GLubyte vally2)
{
    return CCRepeatForever::create(
        CCSequence::create(
            CCEaseInOut::create(CCFadeTo::create(time, vally1), 2.0),
            CCEaseInOut::create(CCFadeTo::create(time, vally2), 2.0),
            nullptr
        ));
}

Layer2Waos* Layer2Waos::create() {
    auto ret = new Layer2Waos();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        // if `new` or `init` went wrong, delete the object and return a nullptr
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool Layer2Waos::init() {

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto textlabelpw = CCLabelBMFont::create("GDPSWow", "chatFont.fnt");
    textlabelpw->setPosition({284 , 11});
    textlabelpw->setScale(0.775f);
    addChild(textlabelpw);

    CCSprite* godray01_001 = ModUtils::createSprite("godray01_001.png");
    addChild(godray01_001);
    godray01_001->setPosition({ 0.0, winSize.height });
    godray01_001->setAnchorPoint({ 0.0,0.5 });
    godray01_001->setRotation(25.0);
    godray01_001->setScaleX(2.800);
    godray01_001->setScaleY(1.700);
    godray01_001->setColor({ 200, 200, 40 });
    godray01_001->setOpacity(80);
    godray01_001->setBlendFunc({ GL_SRC_ALPHA, GL_ONE });
    godray01_001->runAction(getfadeact(4.0, 140, 90));

    auto textlabelpw2 = CCLabelBMFont::create("Te Suscribiste a ToMorritow? uwu", "bigFont.fnt");
    textlabelpw2->setPosition({0, -17});
    textlabelpw2->setScale(0.325f);
    addChild(textlabelpw2);

    textlabelpw2->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(20.0f),  CCEaseInOut::create(CCMoveBy::create(1.0f, { 291, 50 }), 2.0f)));

    auto backgroundSprite = ModUtils::createSprite("game_bg_17_001.png");
    auto size = backgroundSprite->getContentSize();
    backgroundSprite->setScale(winSize.width / size.width);
    backgroundSprite->setAnchorPoint({ 0, 0 });
    backgroundSprite->setPosition({ 0,-75 });
    backgroundSprite->setColor({ 15, 50, 160 });

    backgroundSprite->setZOrder(-2);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"), this, menu_selector(Layer2Waos::backButtonCallback));

    auto menu = CCMenu::create();
    menu->addChild(button);

    auto moveact = CCRepeatForever::create(CCSequence::create(
    CCEaseInOut::create(CCMoveBy::create(3.0, { 0,4 }), 2.0),
    CCEaseInOut::create(CCMoveBy::create(3.0, { 0,-4 }), 2.0), nullptr));

    CCSprite* theTower_01_001 = ModUtils::createSprite("theTower_01_001.png");
    theTower_01_001->setTag(5);
    addChild(theTower_01_001);
    theTower_01_001->setPosition({ winSize.width / 2, winSize.height / 2 });
    theTower_01_001->setScale({1.5f});
    theTower_01_001->runAction(moveact);

    /*
    CSprite* towerShine = ModUtils::createSprite("towerShine.png");
    towerShine->setBlendFunc({ GL_SRC_ALPHA, GL_ONE });
    towerShine->setColor({ 255, 255, 20 });
    towerShine->setPosition({ 58.000, 180.000 });
    towerShine->runAction(getfadeact(3.0, 150, 80));
    theTower_01_001->addChild(towerShine);
    */

    CCMenuItem* doorZone = CCMenuItem::create(this, menu_selector(Layer2Waos::onClickDoor));
    doorZone->setContentSize({ 60.000, 60.000 });
    theTower_01_001->addChild(CCMenu::createWithItem(doorZone),1,000);
    CCMenu* doorZoneMenu = (CCMenu*)doorZone->getParent();
    doorZoneMenu->setPosition({337.2, 208.1});
    doorZoneMenu->setScale({2.0f});


    CCLayerGradient* Gradient = CCLayerGradient::create(ccColor4B({ 0,0,0,0 }), ccColor4B({ 116, 177, 169, 160, }), { 0.0, 1.0 });
    addChild(Gradient);
    Gradient->runAction(getfadeact(5.0, 220, 160));
    Gradient->setBlendFunc({ GL_SRC_ALPHA, GL_ONE });

    gd::GameManager::sharedState()->fadeInMusic("nosong.mp3");
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void Layer2Waos::onClickDoor(CCObject* object) {
    CCSprite* theTower_01_001 = (CCSprite*)getChildByTag(5);
    if (theTower_01_001->numberOfRunningActions() == 1) {
        theTower_01_001->runAction(CCEaseExponentialIn::create(CCScaleTo::create(1.2, 15.000)));
        this->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFuncO::create(this, callfuncO_selector(TheMapAnim::switchToCustomLayerButton), this), nullptr));
    }
}

void Layer2Waos::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void Layer2Waos::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void Layer2Waos::switchToCustomLayerButton(CCObject* object) {
    auto layer = Layer2Waos::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

///Anim The Map

TheMapAnim* TheMapAnim::create() {
    auto ret = new TheMapAnim();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        // if `new` or `init` went wrong, delete the object and return a nullptr
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool TheMapAnim::init() {

    auto winSize = CCDirector::sharedDirector()->getWinSize();

    auto Level1Sprite = CCSprite::create("island_level_001.png");
    Level1Sprite->setPosition({120, 166});
    Level1Sprite->setScale({1.5f});
    addChild(Level1Sprite);

    auto Level2Sprite = CCSprite::create("island_level_002.png");
    Level2Sprite->setPosition({290, 166});
    Level2Sprite->setScale({1.5f});
    Level2Sprite->setColor({100, 100, 100});
    addChild(Level2Sprite);

    auto Level3Sprite = CCSprite::create("island_level_003.png");
    Level3Sprite->setPosition({460, 166});
    Level3Sprite->setScale({1.5f});
    Level3Sprite->setColor({100, 100, 100});
    addChild(Level3Sprite);

    auto sideArt1 = CCSprite::create("GJ_sideArt_001.png");
    sideArt1->setPosition({35 , 34});
    sideArt1->setScale(1.0f);
    sideArt1->setColor({100, 100, 100});
    addChild(sideArt1);

    auto sideArt2 = CCSprite::create("GJ_sideArt_001.png");
    sideArt2->setPosition({34 , 285});
    sideArt2->setScale(1.0f);
    sideArt2->setScaleY(-1.0f);
    sideArt2->setColor({100, 100, 100});
    addChild(sideArt2);
    
    auto Flash = CCSprite::create("GJ_bigStar_glow_001.png");
    Flash->setPosition({284, 100});
    Flash->setZOrder(5);
    Flash->setScale(31.475f);
    addChild(Flash);

    Level1Sprite->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {120, 166})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {120, 164})), nullptr)));

    Flash->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2, 0), CCFadeTo::create(2, 0), nullptr)));

    ///Niveles ----------------------------------------------------------------------------

    auto Level1Button = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Level 1", "bigFont.fnt"),
        this,
        menu_selector(WorldMap::switchToCustomLayerButton)
    );

    Level1Button->setPosition({-50, 51});

    auto Level2Button = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Level 2", "bigFont.fnt"),
        this,
        menu_selector(Layer2Waos::switchToCustomLayerButton)
    );

    Level2Button->setPosition({290, 51});

    auto Level3Button = gd::CCMenuItemSpriteExtra::create(

        CCLabelBMFont::create("Level 3", "bigFont.fnt"),
        this,
        menu_selector(Layer2Waos::switchToCustomLayerButton)
    );

    Level3Button->setPosition({641, 51});

    auto NievelesMenu = CCMenu::create();
    NievelesMenu->addChild(Level1Button);
    NievelesMenu->addChild(Level2Button);
    NievelesMenu->addChild(Level3Button);
    NievelesMenu->setPosition(0, 0);
    NievelesMenu->setScale({0.5f});
    addChild(NievelesMenu);

    ///Fondo

    auto backgroundSprite = CCSprite::create("TheMap\\towerBG_01_001.png");

    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({197, 111, 252});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    //gd::GameManager::sharedState()->fadeInMusic("menuLoop4.mp3");

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(TheMapAnim::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void TheMapAnim::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void TheMapAnim::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void TheMapAnim::switchToCustomLayerButton(CCObject* object) {
    auto layer = TheMapAnim::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}


///The MapLayer

WorldMap* WorldMap::create() {
    auto ret = new WorldMap();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool WorldMap::init() {

    auto LabelSpr = CCSprite::create("worldLabel_01_001.png");
    LabelSpr->setPosition({100 , 100});
    LabelSpr->setScale(1.0f);
    addChild(LabelSpr);

    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({144, 17, 192});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(WorldMap::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void WorldMap::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void WorldMap::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void WorldMap::switchToCustomLayerButton(CCObject* object) {
    auto layer = WorldMap::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}