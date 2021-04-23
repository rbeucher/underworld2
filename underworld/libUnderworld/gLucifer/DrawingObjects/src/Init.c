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
#include <gLucifer/Base/src/Base.h>

#include "DrawingObjects.h"

/* Alias placeholders */
const Type lucSwarmSquares_Type = "lucSwarmSquares";
Dictionary* lucSwarmSquares_MetaAsDictionary() {return Dictionary_New();}
Dictionary* lucSwarmSquares_Type_MetaAsDictionary() {return lucSwarmSquares_MetaAsDictionary();}

Bool lucDrawingObjects_Init()
{
   Stg_ComponentRegister* componentRegister = Stg_ComponentRegister_Get_ComponentRegister();

   Journal_Printf( Journal_Register( Debug_Type, (Name)"Context"  ), "In: %s\n", __func__ ); 

   Stg_ComponentRegister_Add( componentRegister, lucFieldSampler_Type, (Name)"0", _lucFieldSampler_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucIsosurface_Type, (Name)"0", _lucIsosurface_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucIsosurfaceCrossSection_Type, (Name)"0", _lucIsosurfaceCrossSection_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucCrossSection_Type, (Name)"0", _lucCrossSection_DefaultNew );
   Stg_ComponentRegister_Add( componentRegister, lucScalarField_Type, (Name)"0", _lucScalarField_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucVectorArrows_Type, (Name)"0", _lucVectorArrows_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucContourCrossSection_Type, (Name)"0", _lucContourCrossSection_DefaultNew );
   Stg_ComponentRegister_Add( componentRegister, lucSwarmViewer_Type, (Name)"0", _lucSwarmViewer_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucSwarmVectors_Type, (Name)"0", _lucSwarmVectors_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucSwarmShapes_Type, (Name)"0", _lucSwarmShapes_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucSwarmSquares_Type, (Name)"0", _lucSwarmShapes_DefaultNew  );  /* Alias for back compat */
   Stg_ComponentRegister_Add( componentRegister, lucHistoricalSwarmTrajectory_Type, (Name)"0", _lucHistoricalSwarmTrajectory_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucEigenvectorsCrossSection_Type, (Name)"0", _lucEigenvectorsCrossSection_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucEigenvectors_Type, (Name)"0", _lucEigenvectors_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucSwarmRGBColourViewer_Type, (Name)"0", _lucSwarmRGBColourViewer_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucMeshViewer_Type, (Name)"0", _lucMeshViewer_DefaultNew  );
   Stg_ComponentRegister_Add( componentRegister, lucSampler_Type, (Name)"0", _lucSampler_DefaultNew  );


   /* Register Parents for type checking */
   RegisterParent( lucCrossSection_Type,                    lucDrawingObject_Type );
   RegisterParent( lucContourCrossSection_Type,             lucCrossSection_Type );
   RegisterParent( lucIsosurfaceCrossSection_Type,          lucCrossSection_Type );
   RegisterParent( lucEigenvectorsCrossSection_Type,        lucCrossSection_Type );
   RegisterParent( lucScalarField_Type,                     lucCrossSection_Type );
   RegisterParent( lucVectorArrows_Type,                    lucCrossSection_Type );
   RegisterParent( lucEigenvectors_Type,                    lucEigenvectorsCrossSection_Type );
   RegisterParent( lucFieldSampler_Type,                    lucCrossSection_Type );
   RegisterParent( lucIsosurface_Type,                      lucDrawingObject_Type );
   RegisterParent( lucSwarmViewer_Type,               lucDrawingObject_Type );
   RegisterParent( lucSwarmVectors_Type,              lucSwarmViewer_Type );
   RegisterParent( lucSwarmShapes_Type,               lucSwarmViewer_Type );
   RegisterParent( lucHistoricalSwarmTrajectory_Type, lucDrawingObject_Type );
   RegisterParent( lucSwarmRGBColourViewer_Type,      lucSwarmViewer_Type );
   RegisterParent( lucMeshViewer_Type,                lucDrawingObject_Type );
   RegisterParent( lucSampler_Type,                   lucDrawingObject_Type );




   return True;
}


