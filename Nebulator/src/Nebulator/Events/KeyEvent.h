#pragma once

#include "Event.h"
#include "Nebulator/Core/KeyCode.h"

namespace Nebulator
{

//--Base Key Event --------------------
    class KeyEvent : public Event
    {
    public:
        EVENT_CATEGORY_FLAGS(InputEvents | KeyboardEvents)

        KeyCode GetKeyCode() const { return m_KeyCode; }


    protected:
        KeyEvent(KeyCode keyCode)
            : m_KeyCode(keyCode) {}

        KeyCode m_KeyCode;
    };
//-------------------------------------


//--Key Pressed Event -----------------
    class KeyPressed : public KeyEvent
    {
    public:
        KeyPressed(KeyCode keyCode, bool isRepeated)
            : KeyEvent(keyCode), m_IsRepeated(isRepeated) {}

        bool IsRepeated() const { return m_IsRepeated; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (repeated = " << m_IsRepeated << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        bool m_IsRepeated = false;
    };
//-------------------------------------


//--Key Released Event ----------------
    class KeyReleased : public KeyEvent
    {
    public:
        KeyReleased(KeyCode keyCode)
            : KeyEvent(keyCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
//-------------------------------------

} // namespace Nebulator