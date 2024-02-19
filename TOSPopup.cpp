#include "TOSPopup.hpp"

bool TOSPopup::init() {
	auto winSize = CCDirector::sharedDirector()->getWinSize();

	if (!this->initWithColor({ 0, 0, 0, 75 })) return false;
	m_pLayer = CCLayer::create();
	this->addChild(m_pLayer);

	auto bg = CCScale9Sprite::create("GJ_square01.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 350.0f, 195.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu,5);

	auto title = CCLabelBMFont::create("GDPSWow Updated 0.3", "goldFont.fnt");
	title->setScale(0.775f);
	title->setPosition({284.5, 235});
	m_pLayer->addChild(title);

	auto textBg = CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	textBg->setPosition(winSize.width / 2, winSize.height / 2);
	textBg->setContentSize({ 320.0f, 100.f });
	textBg->setOpacity(60);
	m_pLayer->addChild(textBg);

	auto SpriteLogo = CCSprite::create("icon_game.png");
    SpriteLogo->setPosition({373.270, 161.1});
    SpriteLogo->setScale({0.668f});
	m_pLayer->addChild(SpriteLogo);

	auto text = CCLabelBMFont::create("GDPSWow 0.3", "bigFont.fnt", 320, kCCTextAlignmentCenter);
	m_pLayer->addChild(text);
	text->setScale(0.5f);
	text->setPosition({223.76, 190.1});

	auto textmarca = CCLabelBMFont::create("ToMorritow", "bigFont.fnt", 320, kCCTextAlignmentCenter);
	m_pLayer->addChild(textmarca);
	textmarca->setScale(0.369f);
	textmarca->setPosition({223.76, 134.2});

	auto blueText1bruh = CCLabelBMFont::create("Discord Server", "bigFont.fnt", kCCLabelAutomaticWidth, kCCTextAlignmentCenter);
	m_pButtonMenu->addChild(blueText1bruh);
	blueText1bruh->setPosition({-60, 3});
	blueText1bruh->setColor({ 93, 170, 239 });
	blueText1bruh->setScale(0.5f);
	auto blueText1Btn = CCMenuItem::create(this, menu_selector(TOSPopup::onTermsOfUse));
	blueText1Btn->setContentSize({ blueText1bruh->getContentSize().width / 2, blueText1bruh->getContentSize().height / 2 });
	blueText1Btn->setPosition(blueText1bruh->getPositionX(), blueText1bruh->getPositionY());
	m_pButtonMenu->addChild(blueText1Btn);

	auto closeBtn = gd::CCMenuItemSpriteExtra::create(
		gd::ButtonSprite::create("OK", 30, true, "goldFont.fnt", "GJ_button_01.png", 0.0f, 1.0f),
		this,
		menu_selector(TOSPopup::onOk)
	);
	m_pButtonMenu->addChild(closeBtn);
	closeBtn->setPosition({ 0, -74.000f });

	//this->setKeypadEnabled(true);
	this->setTouchEnabled(true);

	return true;
}

void TOSPopup::onOk(cocos2d::CCObject*) {
	this->removeFromParentAndCleanup(true);
}

void TOSPopup::onTermsOfUse(cocos2d::CCObject*) {CCApplication::sharedApplication()->openURL("https://discord.gg/THmJJ75Kcc");}
void TOSPopup::onPrivacyPolicy(cocos2d::CCObject*) { CCApplication::sharedApplication()->openURL("https://www.youtube.com/channel/UCJ73MdeBMcrLuSRE-A5TQqg"); }

TOSPopup* TOSPopup::create() {
	TOSPopup* pRet = new TOSPopup();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return nullptr;
	}
}