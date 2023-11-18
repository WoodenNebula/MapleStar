#pragma once

#include "Nebulator/Core/Core.h"
#include <functional>

namespace Nebulator
{
    enum class EventType
    {
        None = 0,
        WindowClosed, WindowResized, WindowMinimized, WindowMaximized, WindowMoved, WindowFocused, WindowLostFocus,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseWheelScrolled, MouseMoved
    };

    enum EventCategory
    {
        None = 0,
        WindowEvents            = BIT(0),
        InputEvents             = BIT(1),
        KeyboardEvents          = BIT(2),
        MouseEvents             = BIT(3),
        MouseButtonEvents       = BIT(4)
    };


    class Event
    {
    friend class EventDispatcher;

    public:
        virtual ~Event() = default;
        virtual EventType GetEventType() const = 0;
        virtual int GetCategoryFlags() const = 0;

        virtual std::string GetEventName() const = 0;
        virtual std::string ToString() const = 0;

        // To be called from derived Events
        bool IsInEventCategory(EventCategory targetCategory)
        {
            return GetCategoryFlags() & targetCategory;
        }


        bool m_Handled = false;
    };



//--Event Dispatcher-----------------------------
    class EventDispatcher
    {
        template<typename T>
        using EventCbFn = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& e)
            :m_Event(e) {}


        template<typename T>
        bool Dispatch(EventCbFn<T> cbFunc)
        {
            if (m_Event.GetEventType() == T::GetStaticType() )
            {
                m_Event.m_Handled = cbFunc( *(*T)&m_Event ); //converting m_Event from type Event to actual type of the event
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;

    };
//-----------------------------------------------





//--Operator overloading to make logging easier
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        os << e.ToString();
        return os;
    }


//--@param type = Child Class's event type-----------------
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                   virtual EventType GetEventType() const override { return GetStaticType(); }\
                                   virtual std::string GetEventName() const override { return #type; }
//---------------------------------------------------------

//--Macros to make configuring Event Category easier-------
    #define EVENT_CATEGORY_FLAGS(category) virtual int GetCategoryFlags() const override { return category; }
//---------------------------------------------------------

} // namespace Nebulator