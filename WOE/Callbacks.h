#ifndef WOE_CALLBACKS_H
#define WOE_CALLBACKS_H

#include <Arc/ManagedObject.h>

using Arc::ManagedObject;

template <typename ReturnType, typename Param = void>
class Callback
    : public ManagedObject
{

    friend bool operator==( const Callback<ReturnType, Param>& lhs, const Callback<ReturnType, Param>& rhs ) { return lhs.equalTo(rhs); };
    friend bool operator!=( const Callback<ReturnType, Param>& lhs, const Callback<ReturnType, Param>& rhs ) { return !lhs.equalTo(rhs); };

public:

    virtual inline ~Callback( void ) { }

    virtual ReturnType invoke( Param param ) = 0;
    virtual Callback*  clone ( void )        = 0;
    virtual bool isMethodOf  ( void* object) = 0;

protected:

	inline virtual bool equalTo( const Callback<ReturnType, Param>& rhs ) const { return false; };

};

template <typename ReturnType, typename Param = void>
class StaticFunctionCallback
    : public Callback<ReturnType, Param>
{
public:

    StaticFunctionCallback(ReturnType (*function)(Param))
    {
        _function = function;
    }

    inline virtual ReturnType invoke( Param param ) { return (*_function)(param); }

    inline virtual StaticFunctionCallback* clone( void ) { return New StaticFunctionCallback(_function); }

    inline virtual bool isMethodOf( void* object ) { return false; }

    inline virtual string getClassName( void ) const { return "Static Function Callback"; };

protected:

	virtual bool equalTo( const Callback<ReturnType, Param>& rhs ) const
	{
		if ( const StaticFunctionCallback<ReturnType, Param>* convert = dynamic_cast<const StaticFunctionCallback<ReturnType, Param>*>(&rhs) )
		{
			return ( _function == convert->_function );
		}
		return false;
	}

private:

	// Pointer to the static function
	ReturnType
		(*_function)(Param);

};

template <typename ReturnType, typename Param = void, typename ObjectType = void, typename Method = void>
class MethodCallback
    : public Callback<ReturnType, Param>
{
public:

    MethodCallback( void* object, Method method )
    {
        _object = object;
        _method = method;
    }

    inline virtual ReturnType invoke( Param param ) { return (static_cast<ObjectType*>(_object)->*_method)(param); }

    inline virtual MethodCallback* clone( void )    { return New MethodCallback(_object, _method); }

    inline virtual bool isMethodOf( void* object )  { return _object == object; }

    inline virtual string getClassName( void ) const { return "Method Callback"; };

protected:

	virtual bool equalTo( const Callback<ReturnType, Param>& rhs ) const
	{
		if ( const MethodCallback<ReturnType, Param, ObjectType, Method>* convert = dynamic_cast<const MethodCallback<ReturnType, Param, ObjectType, Method>*>(&rhs) )
		{
			return ( _object == convert->_object && _method == convert->_method );
		}
		return false;
	}

private:

	void*
		_object;

	Method
		_method;

};

#endif // WOE_CALLBACKS_H
