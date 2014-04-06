#ifndef WOE_EVENT_DISPATCHER_H
#define WOE_EVENT_DISPATCHER_H

#include <Arc/ManagedObject.h>
#include <Arc/Map.h>
#include <Arc/ArrayList.h>

#include "Event.h"
#include "Delegate.h"

using Arc::ManagedObject;
using Arc::ArrayList;
using Arc::Map;

typedef Delegate<void, const Event&> EventDelegate;

typedef ArrayList<EventDelegate*> EventListenerList;
typedef Map<EventType, EventListenerList> EventMap;

class EventDispatcher
    : public ManagedObject
{
private:

    EventMap
        _eventMap;

    bool
        _changed; 

    static ArrayList<EventDispatcher*>
        _sDispatchers;

    void cleanMap( void );

    virtual void doNothing( void ) { }

public:

    EventDispatcher( void );
    virtual ~EventDispatcher( void );

    virtual inline string toString( void ) const { return "Event Dispatcher"; }

    void addEventListener   ( const EventType& eventType, const EventDelegate& functionDelegate );
    void removeEventListener( const EventType& eventType, const EventDelegate& functionDelegate );

    void addEventListener   ( const EventType& eventType, void (*function)(const Event&));
    void removeEventListener( const EventType& eventType, void (*function)(const Event&));

    template <typename ObjectType, typename Method>
    void addEventListener( const EventType& eventType, ObjectType* object, Method method);

    template <typename ObjectType, typename Method>
    void removeEventListener( const EventType& eventType, ObjectType* object, Method method);

    template <typename ObjectType>
    void removeAllMethods( ObjectType* object );

    void removeAllListeners( void );
    void removeAllListeners( const EventType& eventType );

    void dispatchEvent( const Event& event );

    static void cleanEvents( void )
    {
        int length = _sDispatchers.getSize();
        for (int i = 0; i < length; ++i)
            _sDispatchers[i]->cleanMap();
    }

};

template <typename ObjectType, typename Method>
void EventDispatcher::addEventListener( const EventType& eventType, ObjectType* object, Method method )
{
    addEventListener(eventType, EventDelegate(object, method));
}

template <typename ObjectType, typename Method>
void EventDispatcher::removeEventListener( const EventType& eventType, ObjectType* object, Method method )
{
    removeEventListener(eventType, EventDelegate(object, method));
}

template <typename ObjectType>
void EventDispatcher::removeAllMethods( ObjectType* object )
{
    bool needRepeat = true;
    EventMap::Iterator mapIt;
    EventListenerList::Iterator listIt;

    while(needRepeat)
    {
        needRepeat = false;
        for(mapIt = _eventMap.begin(); !needRepeat && mapIt != _eventMap.end(); ++mapIt)
        {
            for(listIt = mapIt->second.begin(); !needRepeat && listIt != mapIt->second.end(); ++listIt)
            {
                if ( *listIt == nullptr )
                    continue;

                if ( (*listIt)->isMethodOf(object) )
                {
                    (*listIt) = nullptr;
                    needRepeat = true;
                    break;
                }
            }
        }
    }
}

#endif // WOE_EVENT_DISPATCHER_H
