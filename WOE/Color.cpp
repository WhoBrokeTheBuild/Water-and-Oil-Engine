#include "Color.h"

void Color::setRGBA( const float& r, const float& g, const float& b, const float& a )
{
	m_R = Arc::Arc_Clamp(r, 0.0f, 1.0f);
	m_G = Arc::Arc_Clamp(g, 0.0f, 1.0f);
	m_B = Arc::Arc_Clamp(b, 0.0f, 1.0f);
	m_A = Arc::Arc_Clamp(a, 0.0f, 1.0f);
}

void Color::setRGBA(const int& r, const int& g, const int& b, const int& a )
{
	m_R = Arc::Arc_Clamp((float)r / 255.0f, 0.0f, 1.0f);
	m_G = Arc::Arc_Clamp((float)g / 255.0f, 0.0f, 1.0f);
	m_B = Arc::Arc_Clamp((float)b / 255.0f, 0.0f, 1.0f);
	m_A = Arc::Arc_Clamp((float)a / 255.0f, 0.0f, 1.0f);
}

void Color::setHex( const string& hex )
{
	if (hex.length() < 6)
		return;

	char hexR[] = { hex[0], hex[1], '\0' };
	char hexG[] = { hex[2], hex[3], '\0' };
	char hexB[] = { hex[4], hex[5], '\0' };

	int r = 0, 
		g = 0,
		b = 0,
		a = 255;

#	if defined(_WOE_WINDOWS)

		sscanf_s(hexR, "%x", &r);
		sscanf_s(hexG, "%x", &g);
		sscanf_s(hexB, "%x", &b);

#	elif defined(_WOE_LINUX)

		sscanf(hexR, "%x", &r);
		sscanf(hexG, "%x", &g);
		sscanf(hexB, "%x", &b);

#	endif


	if (hex.length() > 6) // Has alpha
	{
		char hexA[] = { hex[6], hex[7], '\0' };

#		if defined(_WOE_WINDOWS)

			sscanf_s(hexA, "%x", &a);

#		elif defined(_WOE_LINUX)

			sscanf(hexA, "%x", &a);

#		endif
	}

	setRGBA(r, g, b, a);
}
