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
#include "StgFEM/Discretisation/src/Discretisation.h"
#include "StgFEM/SLE/SystemSetup/src/SystemSetup.h"
#include "StgFEM/SLE/ProvidedSystems/Energy/src/Energy.h"
#include "StgFEM/SLE/ProvidedSystems/StokesFlow/src/StokesFlow.h"
#include "Finalise.h"

#include <stdio.h>

Bool StgFEM_SLE_ProvidedSystems_Finalise( void ) {
	Journal_Printf( Journal_Register( DebugStream_Type, (Name)"Context"  ), "In: %s\n", __func__ ); 
	
	StgFEM_SLE_ProvidedSystems_Energy_Finalise();
	StgFEM_SLE_ProvidedSystems_StokesFlow_Finalise();

	return True;
}


