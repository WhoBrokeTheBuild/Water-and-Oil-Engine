#ifndef WOE_EVENT_DATA_H
#define WOE_EVENT_DATA_H

#include <Arc/ManagedObject.h>

using Arc::ManagedObject;

class EventData
    : public ManagedObject
{
public:

    virtual inline ~EventData( void ) { }

    virtual inline string getClassName( void ) const { return "Event Data"; };

    virtual EventData* clone( void ) const { return New EventData(); };

};

#endif // WOE_EVENT_DATA_H
