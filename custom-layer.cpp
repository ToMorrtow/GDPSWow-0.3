#include "includes.h"
#include "custom-layer.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <gd.h>
#include <windows.h>

using namespace cocos2d;

void jugarNivel(int levelID, const char* nombre = "", const char* descripcion = "") {
    auto lvl = gd::GJGameLevel::create();
    lvl->m_nLevelID = levelID;
    lvl->m_nLevelID_seed = 5;
    lvl->m_nLevelID_rand = lvl->m_nLevelID + lvl->m_nLevelID_seed;
    lvl->m_eLevelType = gd::kGJLevelTypeSaved;
    lvl->m_bDontSave = true;
    lvl->m_bIsEpic = true;
    lvl->m_sLevelName = nombre;
    lvl->m_sCreatorName = "MasterKilipot";
    lvl->m_sLevelDesc = descripcion;
    lvl->m_nSongID = 589049;

    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, gd::LevelInfoLayer::scene(lvl)));
}

void CustomLayer::customButtonCallBack6(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "No", "ok", nullptr, "You can't get in!");
    flalert->show();
}

void CustomLayer::customButtonCallBack2(CCObject*) {
    jugarNivel(63, "I Love Balls", "Level 1 GDWorld [ GDPSWow ]");
}

void CustomLayer::customButtonCallBack3(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Credits", "okay", nullptr, "Mod by: <cy>ToMorritw</c> \nSupporter by: <co>user666</c>, <cg>ElSai</c>");
    flalert->show();
    gd::GameManager::sharedState()->setGameVariable("1", true);
}

void CustomLayer::waosButton(CCObject*) {
    auto flalert = gd::FLAlertLayer::create(nullptr, "Level 1", "ok", nullptr, "Play <cx>Level 1</c>?");
    flalert->show();
}

void CustomLayer::Levewl1(CCObject*) {
    auto lvl = gd::GJGameLevel::create();
    lvl->setLevelData("H4sIAAAAAAAAA61dW5LsKA7dkNvBQ7xivmYNvYCM-91bmJi1D0aSAQPCVTn9cd1lhBAgDnpg8p-_bTz0x8LHfNTHfsB_tP4Y5z7a4MOWB3z-0p9cppT6hI_-aHf9E3Od-NH_0VcBcdDW7ljoKYtkmAOYHYc05WD8B-ltfrXhYKYc1HsG7nPVlZmUijIb_4KN3nKB-aQETUO6FOQaMUkAtR0Km-uq0_pfVodl89rEnfTEw23GL8oi-C96HyZ1j3_-re2hrofDh8cHHObU9r_qv-ZM18OeoPMDTns93BlCfvgzmPwIp77-iqfCh8NHiPmRTmXKw10PrU5DT7D4TOp66jOWv-1pyhNO7fDpL2baIVPtT-XwaejpFD5TKQ9EH85U2oknlPJ02utpFApuNEpucicvKY09FT29wmdI1xNOpfAJpZ47jcJnkT8_SzvGY29NPE2hSyh_fhZ5rEL5rUb589NEfBb584j7I-Z_w5Gu0Q-Hvh7xmou_bSpTYsq_OFml4N9Q_sVSrfChD_UvfcSUDnNYfdhDK3cYlf_H-sw0HN4dV-10xNxIrnRGSF6lw7pcbC56dXG4lntmkdWHeJTqrhSkA7KynPqArCynOSDkhz8go_MBWZw_-o8-7R_1Z2BkTMfIzBmFTA1ZyqtOOkZpfMdErZgkTz3Vyg48bMdDr3hoA8zEjkxSxwR-1ZtQeYQlA7AdA6N9md4iRJ5ec4SL7fXSuTLpcFP5BxW-DZn3UDcFx3VJxAT_h34Sk-91CBl9qUMkzVc6RDx-qUM4A5nhY_qQt7bp_6CgzOW7mWMu308dcfpy7lieryaPmPx-3WmIk4WXLUFXV1643oRClwvdtdppBq46mfHhMp27_j509Hl7uBDaHXCBsELyvMLNJYipLcfHYmYGeZ8hBvPKRZwYtuLYQgcCLwiq0uirVnKmfXNVKPL5i9o31Ll5fySFzFwzIdirAodf6AaNTfpKN4iJ_27xUYfMd4uPZLHfLz7i1CxjvxbG3MIEf0-vMZ6m1122STvHvJsZZx-dNg_umZOeNdFz6GZwxsH7FRtXFNYQgF7C61Tf1BVnTHy54ox5oDRqNA3HoNG4gqh0sYJYBBDXLK6zbtjrUjZGbZYyiWkjT_xTziKD9SiDn8uQsgF6UWXrNZSZyU6AzRZklrkZbksGFckR6rBjicMCrdo6ZlnHPOugZFYXuybUQca-LURnlbJF8BZa7M9UqmMTKxt4qds0jygslHmE8lo383O_TsF3r_Ng_BVotWVFrcux5We75UhTC0rx1K41vOgS6I0u4UJw_mkc5uV6vbr06qcbac9BG_W9e1E45W5_51-gPFF95WAQZKjvPAzskFa_2kMIvbyZ2Qsm0brPnAXoS-7pORR9SeaVGWFSFJqgFlCLoa6T1CyIalx0r_1090nhufu4H-4-yKHdffxPoAL8BZZWpQyWJKw__sqLg4ZoQnJJey3OLZ2b0xGaWqXvDe9-BQPA3kVhgb3ExzUv4AnGXBCeBahZVhHs5CFcwQ7uKjZL0-4qjreVofPx3SBd3vB0kKgnxd9Ns4qwqKjLcGlyOSATZGCoDIphdrh0mkbsYjniy1FWZCUW5hYuqRzaWDcFRnMUYn4d7UvEbIWoOs738iNJFmV2Uta1cknjyoYDutbQ4E43jINfCs7NpWlzzSjW2veapxLoHQou80JZEsrUrCz4puPTTZco7JbCbynSS4q0b0YksXsS9ZLkwqlNQzKJ35OktyRu35BIYt-SxP24vCARG1IMXBtZZBK_J0kvSeQe-ZedvhB11yORxO9J0pqEkMUYAW0x9roqjLNCshOoFL6LrDGXX0TWnO9NX2b1VVCM-_xdfI5F-W3ssuERYDIvRtgim2kVKeJut6Kw_HTjRAkeZWQoEOfGUOBKcVKJNiRkON-sUJBFWZyV4dowt9G_Wj3GbSkED7SjkHaPmiVZk5iXJOLWUJNLG3HfkEiITQ2JJOYliQjH2JBMEl-SiIhNPRJJzEsSEbGpRyJJXJOQxWuBLN7Ou6jL2yJqtz7TzGvA1NkC_m8e2j2rowts7S6STra0BVqlMIOiu53qujxkbZhcS-Si6SGLEoGW4-t3kPIxGHE_GBJoVkZmyoiADhnNgQ7L5mB2D9MEzGqSc6U1Fl5SSCBj9UsSEUEsvCWR4MHqlyTi2seGXpCIC5tkmZIMagxT5ehFltY_iTwlQUV3uKPA_SIMUUkbZpHAH9tnYYhM_jS4ySzc18FN7lL4KrjJXPQ3wU3uVPxdcJPwKj7CkvgaVOpf01sKPYymOGg36dFPp5q4fBmvZS7fh7K5V9-Fslme34WyaUIM9BOCx4rAYuSLsyGhtE7VszS6bACP80R9VXdX1VkErBriWFMPNU2teZ9kcmGsmZ41b4etE_eq0VW9Ex5AWf5W39wdjuUxjW_TQCUfRwwmaUMopellVhLcY2KYgXtxDgDcLuGD2zkJu-D1GJLGbww_ipqHZlwwvh9vw6B7HTrrgDrsKYmaVkKWkHc2pIqQqQl5U8Oe87hFhxrGlCBO66mgKUUOlyL1c5qgtlyjml2DqesSpgSJAFqJbH2_6CiG5bmfZME1AXvwuAbOlP-LTfE9QgiyY1Ig93JTU401y3ZeezIxHdq-6trXrubUdGG983fUq8LbzxI-xKJN6qafqC5OcLgd5Yc1DKEA8DK1XgY3mGHCeFypqNXZu4iiLONkYYl1DT9S6BC2-WCmtOKhAFL7cB8M7dXeYOl1oPQ6f4oS1kwe1SP11rMFEFyjFKYONNoMg2FZ6WdqpoY2W_AKtzt_K9EPT5x0fBpN0m_PvgD2WZc0vok4hgjy-FJnO6HsTezahaYspGZk-dXExYLIG0834MXBvMvqjonntTw8dszL0L1OG-eV5nDDLAeVccNttBqPG3VayKqLRTPVrafOxkowVELfA66Tc4Emd54grCSThCxpUGQWE88EqtTdIqcCGApMqCz5xNW_OOuZOV2n5Etr55WcLynmsnhC261d5negE5OklW6VJB3oFjlR005ic2iVp-iXbkGvdnqrdqhxwwyKGwYyd9-5hdzPL9xCZvG9W8hd-s4tZC6_cwtpz4gunnCZJ-G5Z8RYd8SYjSqBimAveV46XTQLUjFR4jRmR5WyJ7iKYVH1SlHxL7FJ9ojS6VpNhzbxjQF_SJSofZ4MgKRuSauKJiF5DJVdc4iD3-gRLLHE2AYsue1A0RgYgpdMkbZDFZYBUO7MnUdfHFAjiseGw7XXhiHX9rPaVGYFznbNuZVciIqx_s0jXqnyuHwe11Xc5rBZTUWSbT69aX9HIsQQmUSI_hGJFENkEnHItxlfGheZRMj49hMgdnp7QoAn4AWJOHTbxD13WiTZJu6506IsQuKeoDlZm1F-B-BJ-TPuqVzKW4VAhXAXNVNNHJJCiTjrVHzibKFzqjgZpm4RTrkNtBEvPrSFaOqUGdCUIJiKOghmTmbbFkhHAVMVGO54Abe3EnzaHM4y8RJwq2utYOn9ZoKz1OI0K8NTstY5llfAKJ4tkWSb--URE3CBGpJJhNRj3yMBF7hHIsk2PXzr3L5H-wl4QSJBB_dIJBHSw4gIuSHEjUuVl7jhlEfzcEmFK8RGiYqWi97kVhFBdHwiiNa7Va2nqWPGCx0WJhuVTEy2KutobtHC1Ys8MnbCjBYqggkJs-LHydx5N18l0hsyKcXcTMc8Ryj3kxRNC4lehKy7_gTO9DQBTZx3SeZmxNYk2_wwkYgoo4UcaE_yQlxp2eptIpp7tCeRZRFSyLTytUWLQV752mumWlkMzE-jNSNjhDGbaAfTofkEjedI7RiPuKbN3NQhtTa3Rcl-Z9--HL2pdGEV5Koky68OqBdas-lThhS_I2sRgtAKC2ZoVUctrKRuOq1VdYGdEazZgbsYqap0k8AfYzF1rsNiEuR2IVemUic9Asj9qkMQ0k2jcVdaaQIrTELFXJGxfH4pHwvjZ8J03Vsco0I5QInidnJIWGSEqEbLQ4Qis_a4O80Rkchs_SAWReSydf6YRGxo6_wxyX5s7VwN2h7JJGmtSy2FuCpTj4Dj3my2viyTCGEfluSh1Z0QCGATAdJWVbcBBCZZAEORwlqyZMIivlYpFiYRLUGrcc9bI0YBFgv6JlvteoTZ9YPYwY3FojCmXZx160puqPTs4irIWCmWZxt7spnp-2C0OF0GVVRwi4Ixc-PsmLdtCzpW7fCGNJMtTGWj-IXFOIVp48TI0bC6T-1da4R12TBgC326MK1Zrgu8L4Y-rLbwQ7mk3akymOxO1qwXWU8iLVW7d5Kt4Jj2JFO4p_wIj2D_TcPrxBE1BGE5ZqRMYN9Zg8iJYPBKaNdMrgPgca8FPXM66eLHVCjOHISWQ3_m5slr-cUl4Qd-WD4DHfrkvAWdJ3O9EnSQQjbebzpYM2zGbjDSaztLc7eZls5JQDyBRe6YCjqgIcwHWxDfzj5BceC1UJhmhYRDWLPFIVZO2C3oXrHCbFmDkERvmxEp1mncjodIEdZLuieRgAH2DjTsHWjYe-qw9_eJRAJMCG9J9kO3OH-NOuQox_X8yMm5ONM8WhwuPTGrXUAlioUnGrPL1kaxUCy3tk-5cSc17qXGW5qpgctNGKkJ9aIJ-5ZmKkY3kpIl7tRuMZO00mJ2aweZmdg9k60X6_yeieC-EJO0ZyKkq9sOixRbX9htXRC3Sz7zsG7lkLw1bEXUkb077fa-stv7ym6bhiYSEbrc3hF2e0fYCc5d32kJ9d3e-3fbxDp3eq-RMsk2a86dfkEi6tw-tuL2AQC3j4o44cAB2Wle8HnYZEeaxyfab4800SryjaPPhuPMbvSds_QEdraF_ehLky3sRwecS9b-vB_9-afYeil2TwcLun4s7y82fnfIjGfki7vs0Gj2o3dOBasIgF9FAPwkAqBxbEpaMAynM8k897d53gVkqq3gtWAr-E146EkmB1D8JjwykM0jFbT8_Nazr9q-3Gz9OuLQUUg4UBf5hkSEc78PI_h9GMELYYSHen93bSQvNfO7SANNdXjpGIe9Y1tQKLDr18BPGD37J9d1rio0AYxnM9X9xjUaRh-ZwDEsQwjhZSAljB47OTlhcJSfrNdptrCLjjzpJgmstu89PqFGhnUwiZZpuMM4kwUatu7-PefT6ltHP2wd_bB19MPW0Q97R78q1Y5EMm3CPlwQ9s512McCwj4WEAQXvSeRgDEIEYVBP9VLPbZzul4n1FbwNyR2r3xTEtqfAyTKwvpzTL40Wd1gwhk2hLbR5yUZDVbU8jZMWBhvr2k0canBKH0NiB9SEU057gfNCwNwuolMs4RWI84kHYBIHNGsn5mpWDT52sfFtK6UhkrD8InGzk0mW1g32TL3dFOMaS5SkCh_f9pNhMZPu5rep4bRm-9NH4OwMAyDqm2GetQj3pGFxz4T01CAX2Kw3J6iCPytfjPpmAwLDXFqznvEbSiqqtZko4nbqE0U4inUwPRDguDb9SHwFw4mtPzLvSGrDojbT9zHCuL2ED6T7IdK3BVovCX8JZIpuA6LRr1afXXfmGXJo1J0wmoD1dGY096EkzVUiEmx8Qrb65vt7svKIliqN8NV5aYKvmIpvjGasTTVl9Cga5peJceFWvg0EfUrCQe0ubWZ6qWti1Vv911S7G6hJgpJOu37QpqtpMtBvjTznhPodVmYlOFoejU9mIvSeBWWY0Vl0seDTDK9Yo--9NWL2_oofMFCBknI6fFVEnJtDzNrkFivT79SmZBf8Sotp8QrL5RZoUxNynQjUKgRGa99-Z48jN_LplLMO8XMQPF85edoa1CRHQ0Uz1eJzir5ZaW0rpSGStxQqjspdnZtmJQdm6R29W-8dHikS8N7nHHpqlvUl-lFubh4s3y0eJ_hL2BxEqLrxS7FKqFuLnj2RgA_JnlAMb5cIGoZTFMBmDoyv0QRh2F7DaKXrlIk_lMQprL1FzReuGCRFoiZYR1NgVnjpzcz_KTBk-6983YKIFwoAdf8cjfsqHSBG9UWsNnuAgVeuv6N-M9glQbLCshmZwjFZQLq2RnqIbJZY4_p3aYe1oueNyEQfvzo3SZEMAVrmIIRprjSGhBhCYiwhl4YoZcbagAR3yzgHSqfEfxgAYowgiKqCcwgj5QM1oBJKxJWoNjPXndHyI-um-n5dBffLC-hKrcn5L8wQEySOiX6rHhJlHf7364qyl6i1ctriXD03M4YJYqp_0K_YuceP0ahW87tNLo2aZceax4HAPa-dnGie17lg47i0NcOTd9DfY9SBly47VoOfNt_ncX-h2ncPYvzaySYg3qiQcejhwFDMEBDGtuLduzjZ-g8_cZdKyG8k5B-YVCphj30V_2F-8fvukJqO-hyYrZr270cHayP89PCLLVLtgm2S8r0P-PGX71YeAAA");
    auto TerminoLvl = gd::PlayLayer::scene(lvl);
    auto director = cocos2d::CCDirector::sharedDirector();
    director->replaceScene(cocos2d::CCTransitionFade::create(0.5, TerminoLvl));
    
}


const char* CustomLayer::getEventTimeString()
{
    switch (rand() % 22)
    {
    case 0:
        return "GDPSWow 0.3";
    case 1:
        return  "ToMorritowCode";
    case 2:
        return  "GDPSWow 0.3.2.2";
    case 3:
        return  "Hola";
    case 4:
        return  "Nuevo evento Proximamente . w.";
    case 5:
        return  "Developer by: elSai";
    case 6:
        return  "ToMorritowBot Comming Soon...";
    case 7:
        return  "Hola, soy ToMorritowBot .w.!";
    case 8:
        return  "Geometry Dash World";
    case 10:
        return  "Geometry Dash Wow .w.";
    case 11:
        return  "Antes el GDPS se llamaria GDPS Space :0";
    case 12:
        return  "Test Evento .w.";
    case 13:
        return  "ToMorritow";
    case 14:
        return  "Jorgame";
    case 15:
        return  "Presione algunos de los bottones\n para jugar algunos niveles :D";
    case 16:
        return  "ya te suscribiste a ToMorritow .w.?";
    case 17:
        return  "Bienvenido al Evento\n GDPSWow .w.";
    case 18:
        return  "GDPSWow Referencia:";
    case 19:
        return  "No hay chamba .,.";
    case 20:
        return  "Se viene cositas al GDPSWow 0.4";
    case 21:
        return  "  Si no te carga los Eventos,\n Debe ser falta de Servidores D:";
    default:
        return "Loading Events";
    }
}

CustomLayer* CustomLayer::create() {
    auto ret = new CustomLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        // if `new` or `init` went wrong, delete the object and return a nullptr
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool CustomLayer::init() {

    auto worldlabel = CCSprite::create("worldLabel_01_001.png");
    worldlabel->setPosition({290 , 278});
    worldlabel->setScale(1.0f);
    addChild(worldlabel);

    auto worldbackground = CCSprite::create("worldIsland_01.png");
    worldbackground->setPosition({279 , 119});
    worldbackground->setScale(1.0f);
    addChild(worldbackground);

    worldbackground->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {279 , 119})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {279 , 117})), nullptr)));

    auto sideArt = CCSprite::create("GJ_sideArt_001.png");
    sideArt->setPosition({534 , 34});
    sideArt->setScale(1.0f);
    sideArt->setScaleX(-1.0f);
    addChild(sideArt);

    auto sideArt2 = CCSprite::create("GJ_sideArt_001.png");
    sideArt2->setPosition({35 , 34});
    sideArt2->setScale(1.0f);
    addChild(sideArt2);

    auto CustomSprite = CCSprite::create("GJ_ToMorritwBtn_001.png");
    CustomSprite->setScale(0.6f);

    auto buttonMenu = CCMenu::create();
    auto CustomButton = gd::CCMenuItemSpriteExtra::create(CustomSprite, this, menu_selector(CustomLayer::customButtonCallBack3));
    buttonMenu->setPosition({550 , 300});
    buttonMenu->addChild(CustomButton);
    //addChild(buttonMenu);

    auto waosSprite = CCSprite::create("GJ_arrow_01_001.png");
    waosSprite->setScale(0.6f);

    waosSprite->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCScaleTo::create(1.0f, 1.05f)), 
    CCEaseSineInOut::create(CCScaleTo::create(1.0, 1.0f)), nullptr)));

    auto waosbuttonMenu = CCMenu::create();
    auto waosButton = gd::CCMenuItemSpriteExtra::create(waosSprite, this, menu_selector(CustomLayer::waosButton));
    waosbuttonMenu->setPosition({-222 , 96});
    waosbuttonMenu->setScale({0.35f});
    waosbuttonMenu->setRotation({-90});
    waosbuttonMenu->addChild(waosButton);
    this->addChild(waosbuttonMenu);

    waosbuttonMenu->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {-222 , 96})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {-222 , 94})), nullptr)));

    auto CustomSprite2 = CCSprite::create("GJ_IslasBtn_001.png");
    CustomSprite2->setScale({1.0f});

    auto buttonMenu2 = CCMenu::create();
    auto CustomButton2 = gd::CCMenuItemSpriteExtra::create(CustomSprite2, this, menu_selector(CustomLayer::customButtonCallBack2));
    buttonMenu2->setPosition({116 , 139});
    buttonMenu2->addChild(CustomButton2);
    this->addChild(buttonMenu2);

    buttonMenu2->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {116 , 139})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {116 , 137})), nullptr)));

    auto CustomSprite3 = CCSprite::create("GJ_IslasBtn_lock_001.png");
    CustomSprite3->setScale({1.0f});

    auto buttonMenu3 = CCMenu::create();
    auto CustomButton3 = gd::CCMenuItemSpriteExtra::create(CustomSprite3, this, menu_selector(CustomLayer::customButtonCallBack6));
    buttonMenu3->setPosition({226 , 125});
    buttonMenu3->addChild(CustomButton3);
    this->addChild(buttonMenu3);

    buttonMenu3->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {226 , 125})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {226 , 123})), nullptr)));

    auto CustomSprite4 = CCSprite::create("GJ_IslasBtn_lock_001.png");
    CustomSprite4->setScale({1.0f});

    auto buttonMenu4 = CCMenu::create();
    auto CustomButton4 = gd::CCMenuItemSpriteExtra::create(CustomSprite4, this, menu_selector(CustomLayer::customButtonCallBack6));
    buttonMenu4->setPosition({303 , 140});
    buttonMenu4->addChild(CustomButton4);
    this->addChild(buttonMenu4);

    buttonMenu4->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {303 , 140})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {303 , 138})), nullptr)));

    auto CustomSprite5 = CCSprite::create("GJ_IslasBtn_lock_001.png");
    CustomSprite5->setScale({1.0f});

    auto buttonMenu5 = CCMenu::create();
    auto CustomButton5 = gd::CCMenuItemSpriteExtra::create(CustomSprite5, this, menu_selector(CustomLayer::Levewl1));
    buttonMenu5->setPosition({389 , 132});
    //buttonMenu5->addChild(CustomButton5);
    //this->addChild(buttonMenu5);

    if (gd::GameManager::sharedState()->getGameVariable("1")) {
    addChild(CustomButton5);
    }

    CustomSprite5->runAction(CCRepeatForever::create(CCSequence::create(
				CCTintTo::create(0.5, 255,   0,	  0), 
				CCTintTo::create(0.5, 255, 255,   0), 
				CCTintTo::create(0.5, 0  , 255,   0),
				CCTintTo::create(0.5, 0  , 255, 255), 
				CCTintTo::create(0.5, 0  ,   0, 255), 
				CCTintTo::create(0.5, 255,   0, 255), 
				nullptr)));

    buttonMenu5->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {389 , 132})), 
    CCEaseSineInOut::create(CCMoveTo::create(1.5, {389 , 130})), nullptr)));

    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({ 0, 102, 255 });
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

	CCLabelBMFont* text2 = CCLabelBMFont::create(getEventTimeString(), "bigFont.fnt");
	text2->setPosition({0, -17});
	text2->setScale(0.325f);
	addChild(text2);

    text2->runAction(CCSequence::createWithTwoActions(CCDelayTime::create(20.0f),  CCEaseInOut::create(CCMoveBy::create(1.0f, { 291, 50 }), 2.0f)));

    gd::GameManager::sharedState()->fadeInMusic("menuLoop2.mp3");

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(CustomLayer::backButtonCallback)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void CustomLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void CustomLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void CustomLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = CustomLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.5f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}