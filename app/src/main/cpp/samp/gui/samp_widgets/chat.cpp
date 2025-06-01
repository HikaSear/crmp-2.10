#include "../gui.h"
#include "../../main.h"
#include "../../game/game.h"
#include "../../net/netgame.h"
#include <algorithm>
#include "../settings.h"
#include "java/jniutil.h"
#include "../obfusheader.h"

extern UI* pUI;
extern CGame* pGame;
extern CNetGame* pNetGame;
extern CSettings* pSettings;
extern CJavaWrapper *pJavaWrapper;

bool g_bChatVisible = true;

Chat::Chat() : ListBox()
{

}

void Chat::addChatMessage(const std::string& message, const std::string& nick, const ImColor& nick_color)
{
	addPlayerMessage(message, nick, nick_color);
}

void Chat::addInfoMessage(const std::string& format, ...)
{
	char tmp_buf[512];

	va_list args;
	va_start(args, format);
	vsprintf(tmp_buf, format.c_str(), args);
	va_end(args);

	addMessage(std::string(tmp_buf), ImColor(0x00, 0xc8, 0xc8));
}

void Chat::addDebugMessage(const std::string& format, ...)
{
	char tmp_buf[512];

	va_list args;
	va_start(args, format);
	vsprintf(tmp_buf, format.c_str(), args);
	va_end(args);

	addMessage(std::string(tmp_buf), ImColor(0xbe, 0xbe, 0xbe));
}

void Chat::addClientMessage(const std::string& message, const ImColor& color)
{
	addMessage(message, color);
}

void Chat::addMessage(const std::string& message, const ImColor& color)
{
	if (this->itemsCount() > UISettings::chatMaxMessages())
	{
		this->removeItem(0);
	}

	MessageItem* item = new MessageItem(message, color);
	this->addItem(item);
	/*if(!active())*/ this->setScrollY(1.0f);
}

void Chat::addPlayerMessage(const std::string& message, const std::string& nick, const ImColor& nick_color)
{
	if (this->itemsCount() > UISettings::chatMaxMessages())
	{
		this->removeItem(0);
	}

	PlayerMessageItem* item = new PlayerMessageItem(message, nick, nick_color);
	this->addItem(item);
	/*if(!active())*/ this->setScrollY(1.0f);
}

void Chat::draw(ImGuiRenderer* renderer)
{
	ListBox::draw(renderer);
}

void Chat::activateEvent(bool active)
{
	if (active)
	{
		this->setScrollable(true);
	}
	else
	{
		this->setScrollable(false);
	}
}

void Chat::touchPopEvent()
{
	if (pUI->playertablist()->visible()) return;

	pUI->keyboard()->show(this);
}

void Chat::keyboardEvent(const std::string& input)
{
    if (input.length() > 0 && pNetGame)
    {
        if (input[0] == '/')
        {
            if(!pUI->chat()->commandClient(input.c_str());)
            {
                pNetGame->SendChatCommand(input.c_str());
            }
        }
        else
            pNetGame->SendChatMessage(input.c_str());
    }
}

bool Chat::commandClient(const std::string& command) //--
{
	/*if(command == OBF("/dl"))
    {
        pUI->chat()->addDebugMessage("debug started");

        uint32_t ms_nNoOfVisibleEntities = *(uint32_t*)(g_libGTASA + (VER_x32 ? 0x00960b64 : 0x00bcf8e4)); //.bss:008C162C                 EXPORT _ZN9CRenderer23ms_nNoOfVisibleEntitiesE

        uintptr_t* ms_aVisibleEntityPtrs = (uintptr_t*)(g_libGTASA + (VER_x32 ? 0x00960b80 : 0x00bcf900));//.bss:008C0680                 EXPORT _ZN9CRenderer21ms_aVisibleEntityPtrsE

        uintptr_t m_pEntityPointer = (uintptr_t)ms_aVisibleEntityPtrs[ms_nNoOfVisibleEntities];
        if (m_pEntityPointer) {
            pUI->DrawTextureInfo(m_pEntityPointer);
        }
    }*/

    return false;
}