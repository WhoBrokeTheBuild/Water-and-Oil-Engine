#include "EventDispatcher.h"
#include "Event.h"

ArrayList<EventDispatcher*> EventDispatcher::_sDispatchers = ArrayList<EventDispatcher*>();

EventDispatcher::EventDispatcher( void )
	: _eventMap(),
	  _changed(false)
{
    _sDispatchers.add(this);
}

EventDispatcher::~EventDispatcher( void )
{
    _sDispatchers.remove(this);
    removeAllListeners();
}

void EventDispatcher::addEventListener( const EventType& eventType, const EventDelegate& functionDelegate )
{
    if ( ! _eventMap.containsKey(eventType))
        _eventMap[eventType] = EventListenerList();

    int length = _eventMap[eventType].getSize();

    for(int i = 0; i < length; ++i)
    {
        if (_eventMap[eventType][i] == nullptr)
            continue;
        if (*(_eventMap[eventType][i]) == functionDelegate)
            return;
    }

    _eventMap[eventType].add(New EventDelegate(functionDelegate));
}

void EventDispatcher::removeEventListener( const EventType& eventType, const EventDelegate& functionDelegate )
{
    if ( ! _eventMap.containsKey(eventType))
        return;

    int length = _eventMap[eventType].getSize();

    for(int i = 0; i < length; ++i)
    {
        if (_eventMap[eventType][i] == nullptr)
            continue;
        if (*(_eventMap[eventType][i]) == functionDelegate)
        {
            delete _eventMap[eventType][i];
            _eventMap[eventType][i] = nullptr;
            _changed = true;
            return;
        }
    }
}

void EventDispatcher::removeEventListener( const EventType& eventType, void (*function)(const Event&) )
{
    removeEventListener(eventType, EventDelegate(function));
}

void EventDispatcher::addEventListener( const EventType& eventType, void (*function)(const Event&) )
{
    addEventListener(eventType, EventDelegate(function));
}

void EventDispatcher::removeAllListeners( void )
{
    EventMap::Iterator          mapIt;
    EventListenerList::Iterator listIt;

    int length;
    for (mapIt = _eventMap.itBegin(); mapIt != _eventMap.itEnd(); ++mapIt)
    {
        length = mapIt->second.getSize();
        for (int i = 0; i < length; ++i)
        {
            if (mapIt->second[i] != nullptr)
            {
                delete mapIt->second[i];
                mapIt->second[i] = nullptr;
            }
        }
    }

    _eventMap.clear();
}

void EventDispatcher::removeAllListeners( const EventType& eventType )
{
    if ( ! _eventMap.containsKey(eventType))
        return;

    int length = _eventMap[eventType].getSize();
    for(int i = 0; i < length; ++i)
    {
        if ( _eventMap[eventType][i] != nullptr )
        {
            delete _eventMap[eventType][i];
            _eventMap[eventType][i] = nullptr;
        }
    }

    _eventMap.removeKey(eventType);

    _changed = true;
}

void EventDispatcher::dispatchEvent( const Event& event )
{
    EventType type = event.getType();

    if ( ! _eventMap.containsKey(type))
        return;

    Event tmp = Event(event);

    tmp.setTarget(this);

    unsigned int length = _eventMap[type].getSize();
    for(unsigned int i = 0; i < length; ++i)
    {
        if (_eventMap[type][i] != nullptr)
            _eventMap[type][i]->invoke(event);
    }
}

void EventDispatcher::cleanMap( void )
{
    if ( ! _changed)
        return;

    bool needRepeat = true;
    EventMap::Iterator mapIt;
    EventListenerList* list;

    while (needRepeat)
    {
        needRepeat = false;
        for (mapIt = _eventMap.itBegin(); !needRepeat && mapIt != _eventMap.itEnd(); ++mapIt)
        {
            list = &mapIt->second;
            for (unsigned int i = 0; !needRepeat && i < list->getSize(); ++i)
            {
                if (list->at(i) == nullptr)
                {
                    list->removeAt(i);
                    needRepeat = true;
                    break;
                }
            }
        }
    }

    _changed = false;
}
