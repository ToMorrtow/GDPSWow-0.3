#include "GatoSexoLayer.hpp"
#include "server.hpp"

void GatoSexoLayer::customButtonCallBack4(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Extras Credits", "okay", nullptr, "Jorgame, ElSai,\n User666, Cypher, MigMatos");
    flalert->show();
}

GatoSexoLayer* GatoSexoLayer::create() {
    auto ret = new GatoSexoLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool GatoSexoLayer::init() {

    auto label = CCLabelBMFont::create("GDPSWow Credits", "bigFont.fnt");

    label->setPosition({291, 289});
    label->setScale({0.6f});

    // equivalent to `this->addChild(label)`
    addChild(label);

    auto w = CCSprite::create("version-hd.png");
    w->setPosition({283 , 10});
    w->setScale(0.3f);
    addChild(w);

    auto creditos1 = CCSprite::create("ToMorritow.png");
    creditos1->setPosition({135 , 190});
    creditos1->setScale(0.6f);
    addChild(creditos1);

    auto creditos2 = CCSprite::create("edgajuman.png");
    creditos2->setPosition({442 , 190});
    creditos2->setScale(0.6f);
    addChild(creditos2);

    auto creditos3 = CCSprite::create("elSai.png");
    creditos3->setPosition({281 , 82    });
    creditos3->setScale(0.45f);
    addChild(creditos3);

    auto extraslabel = CCLabelBMFont::create("Extras ( Coming Soon )", "bigFont.fnt");
    extraslabel->setPosition({282 , 29});
    extraslabel->setScale(0.29f);
    addChild(extraslabel);

    auto discord = CCSprite::create("Mw_ServerIcon_001.png");
    discord->setPosition({214 , 154});
    discord->setScale(0.6f);
    addChild(discord);

    auto discord2 = CCSprite::create("Mw_DiscordIcon_001.png");
    discord2->setPosition({520 , 154});
    discord2->setScale(0.6f);
    addChild(discord2);

    auto youtuberw = CCSprite::create("gj_ytIcon_001.png");
    youtuberw->setPosition({190 , 154});
    youtuberw->setScale(0.6f);
    addChild(youtuberw);

    auto CustomSprite = CCSprite::create("GJ_ToMorritwBtn_001.png");
    CustomSprite->setScale(0.6f);

    auto buttonMenu = CCMenu::create();
    auto CustomButton = gd::CCMenuItemSpriteExtra::create(CustomSprite, this, menu_selector(GatoSexoLayer::customButtonCallBack4));
    buttonMenu->setPosition({550 , 300});
    buttonMenu->addChild(CustomButton);
    this->addChild(buttonMenu);

    auto backgroundSprite = CCSprite::create("game_bg_19_001-hd.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});

    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(
        // directly create the sprite here, as its our only use for it
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(GatoSexoLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void GatoSexoLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void GatoSexoLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void GatoSexoLayer::switchToCustomLayerButton(CCObject* object) {

    auto layer = GatoSexoLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);

    auto transition = CCTransitionFade::create(0.5f, scene);

    CCDirector::sharedDirector()->pushScene(transition);
}