/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**                                                                                  **
** This file forms part of the Underworld geophysics modelling application.         **
**                                                                                  **
** For full license and copyright information, please refer to the LICENSE.md file  **
** located at the project root, or contact the authors.                             **
**                                                                                  **
**~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

#include <mpi.h>
#include <StGermain/libStGermain/src/StGermain.h>
#include <StgDomain/libStgDomain/src/StgDomain.h>
#include <StgFEM/libStgFEM/src/StgFEM.h>
#include <PICellerator/libPICellerator/src/PICellerator.h>
#include <Underworld/libUnderworld/src/Underworld.h>
#include "Toolbox.h"

const Type Underworld_Toolbox_Type = "Underworld_Toolbox";

void _Underworld_Toolbox_AssignFromXML( void* component, Stg_ComponentFactory* cf, void* data ) { }

void* _Underworld_Toolbox_DefaultNew( Name name ) {
   return Codelet_New(
      Underworld_Toolbox_Type,
      _Underworld_Toolbox_DefaultNew,
      _Underworld_Toolbox_AssignFromXML,
      _Codelet_Build,
      _Codelet_Initialise,
      _Codelet_Execute,
      _Codelet_Destroy,
      name );
}

void Underworld_Toolbox_Initialise( ToolboxesManager* toolboxesManager, int* argc, char*** argv ) {
   Underworld_Init( argc, argv );
}

void Underworld_Toolbox_Finalise( ToolboxesManager* toolboxesManager ) {
   Underworld_Finalise();
}

Index Underworld_Toolbox_Register( ToolboxesManager* toolboxesManager ) {
   return ToolboxesManager_Submit( toolboxesManager, Underworld_Toolbox_Type, (Name)"0", _Underworld_Toolbox_DefaultNew );
}

