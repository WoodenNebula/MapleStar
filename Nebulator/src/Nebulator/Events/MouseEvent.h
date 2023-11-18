#pragma once
#include "Event.h"
#include "Nebulator/Core/MouseCode.h"

#include <sstream>

namespace Nebulator {

//--Base Mouse Button Event----------------------
    class MouseButtonEvent : public Event
    {
    public:
        MouseCode GetMouseCode() const { return m_MouseCode; }

        EVENT_CATEGORY_FLAGS(InputEvents | MouseEvents | MouseButtonEvents)

    protected:
        MouseButtonEvent(MouseCode mouseCode) 
            : m_MouseCode(mouseCode) {}

        MouseCode m_MouseCode;
    };
//-----------------------------------------------


//--Mouse Button Press Event---------------------
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(MouseCode mouseCode)
            : MouseButtonEvent(mouseCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_MouseCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };
//-----------------------------------------------


//--Mouse Button Release Event-------------------
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(MouseCode mouseCode)
            : MouseButtonEvent(mouseCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_MouseCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
//-----------------------------------------------


//--Mouse Scroll Event---------------------------
    class MouseWheelScrolledEvent : public Event
    {
    public:
        MouseWheelScrolledEvent(float scrollOffset)
            :m_ScrollOffset(scrollOffset) {}

        inline float GetScrollOffset() const { return m_ScrollOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseWheelScrolledEvent: by " << m_ScrollOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseWheelScrolled)
        EVENT_CATEGORY_FLAGS(InputEvents | MouseEvents)

    private:
        float m_ScrollOffset;

    };
//-----------------------------------------------


//--Mouse Move Event-----------------------------
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float xPos, float yPos)
            :m_xPos(xPos), m_yPos(yPos) {}

        inline float GetX() const { return m_xPos; }
        inline float GetY() const { return m_yPos; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: to (x, y) = (" << m_xPos << ", " << m_yPos << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CATEGORY_FLAGS(InputEvents | MouseEvents)

    private:
        float m_xPos, m_yPos;
    };
//-----------------------------------------------


} // namepsace Nebulator