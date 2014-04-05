#ifndef WOE_BASE_RENDER_TARGET_H
#define WOE_BASE_RENDER_TARGET_H

#include <Arc/ManagedObject.h>

using Arc::ManagedObject;

class BaseRenderTarget :
	public ManagedObject
{
public:

protected:

	BaseRenderTarget( void );
	BaseRenderTarget( const BaseRenderTarget& rhs );


};

#endif // WOE_BASE_RENDER_TARGET_H