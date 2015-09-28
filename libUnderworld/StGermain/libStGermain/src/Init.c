/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**                                                                                  **
** This file forms part of the Underworld geophysics modelling application.         **
**                                                                                  **
** For full license and copyright information, please refer to the LICENSE.md file  **
** located at the project root, or contact the authors.                             **
**                                                                                  **
**~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

#include <stdarg.h>
#include <mpi.h>
#include "Base/Foundation/Foundation.h"
#include "Base/IO/IO.h"
#include "Base/IO/Journal.h"
#include "Base/Container/Container.h"
#include "Base/Automation/Automation.h"
#include "Base/Extensibility/Extensibility.h"
#include "Base/Context/Context.h"
#include "Utils/Utils.h"

#include "Init.h"

#include <stdio.h>

Bool StGermain_Init( int* argc, char** argv[] ) {
   char* directory;
   int   tmp;

   /* lets init python if we have it */
   #ifdef HAVE_PYTHON
      Py_Initialize();
   #endif   

   /* Initialise enough bits and pieces to get IO going */
   BaseFoundation_Init( argc, argv );
   BaseIO_Init( argc, argv );

   /* Initialise the remaining bits and pieces */
   BaseContainer_Init( argc, argv );
   BaseAutomation_Init( argc, argv );
   BaseExtensibility_Init( argc, argv );
   BaseContext_Init( argc, argv );

   /* Init the StGermain Utils folder */
   StGermainUtils_Init( argc, argv );

   /* Write out the copyright message */
   
   

   Stream_Flush( Journal_Register( InfoStream_Type, "Context" ) );
   Stream_SetPrintingRank( Journal_Register( InfoStream_Type, "Context" ), tmp );
   
   /* Add the StGermain path to the global xml path dictionary */
   directory = Memory_Alloc_Array( char, 200, "xmlDirectory" );
   sprintf( directory, "%s%s", LIB_DIR, "/StGermain" );
   XML_IO_Handler_AddDirectory( "StGermain", directory );
   Memory_Free( directory );
   
   /* Add the plugin path to the global plugin list */
   ModulesManager_AddDirectory( "StGermain", LIB_DIR );

   
   return True;
}


