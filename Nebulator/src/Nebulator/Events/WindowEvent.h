#include "nrpch.h"
#include "Event.h"

namespace Nebulator {
//--Base Window Event----------------------------
    class WindowEvent : public Event
    {
    public:
        EVENT_CATEGORY_FLAGS(WindowEvents)
        
    protected:
        WindowEvent() {}
    };
//-----------------------------------------------



//--Window Close Event---------------------------
    class WindowClosedEvent : public WindowEvent
    {
    public:
        WindowClosedEvent(const std::string& windowTitle) : m_WindowTitle(windowTitle) {}

        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowClosedEvent: " << m_WindowTitle;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowClosed)

    private:
        std::string m_WindowTitle;
    };
//-----------------------------------------------


//--Window Resize Event--------------------------
    class WindowResizedEvent : public WindowEvent
    {
    public:
        WindowResizedEvent(uint32_t width, uint32_t height)
            : m_Width(width), m_Height(height) {}


        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizedEvent: to (width, height) = (" << m_Width << ", " << m_Height << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResized)

    private:
        uint32_t m_Width, m_Height;
    };
//-----------------------------------------------


//--Window Moved Event---------------------------
    class WindowMovedEvent : public WindowEvent
    {
    public:
        WindowMovedEvent(uint32_t xPos, uint32_t yPos)
            : m_xPos(xPos), m_yPos(yPos) {}

        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowMovedEvent: to (x, y) = (" << m_xPos << ", " << m_yPos << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMoved)

    private:
        uint32_t m_xPos, m_yPos;
    };
//-----------------------------------------------


//--Window Minimize Event------------------------
    class WindowMinimizedEvent : public WindowEvent
    {
    public:
        WindowMinimizedEvent(const std::string& windowTitle) : m_WindowTitle(windowTitle) {}

        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowMinimizedEvent: " << m_WindowTitle;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMinimized)

    private:
        std::string m_WindowTitle;
    };
//-----------------------------------------------


//--Window Maximize Event------------------------
    class WindowMaximizedEvent : public WindowEvent
    {
    public:
        WindowMaximizedEvent(const std::string& windowTitle) : m_WindowTitle(windowTitle) {}

        virtual std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowMaximizedEvent: " << m_WindowTitle;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMaximized)

    private:
        std::string m_WindowTitle;
    };
//-----------------------------------------------


/*
*** TODO: IMPLEMENT MORE WINDOW EVENTS
    class WindowFocusedEvent : public WindowEvent
    {
    public:
        EVENT_CLASS_TYPE(WindowFocused)
    };


    class WindowLostFocusEvent : public WindowEvent
    {
    public:
        EVENT_CLASS_TYPE(WindowLostFocus)

    };

*/
} // namespace Nebulator