#include "application.h"

void Application::leave(conn_ptr conn) 
{
	lobby_.leave(conn);
	// potentially more clean up based on the specific class
}
