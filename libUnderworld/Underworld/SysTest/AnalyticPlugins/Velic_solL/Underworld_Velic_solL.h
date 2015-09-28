/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**                                                                                  **
** This file forms part of the Underworld geophysics modelling application.         **
**                                                                                  **
** For full license and copyright information, please refer to the LICENSE.md file  **
** located at the project root, or contact the authors.                             **
**                                                                                  **
**~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

#include <mpi.h>
#include <StGermain/StGermain.h>
#include <StgDomain/StgDomain.h>
#include <StgFEM/StgFEM.h>
#include <PICellerator/PICellerator.h>
#include <Underworld/Underworld.h>

#ifndef __Underworld_Velic_solL_h__
#define __Underworld_Velic_solL_h__

   extern const Type Underworld_Velic_solL_Type;

   typedef struct {
      __Codelet;
      double sigmaB;
      double sigmaA;
      double eta; 
   } Underworld_Velic_solL;

   Index Underworld_Velic_solL_Register( PluginsManager* pluginsManager );

   void* _Underworld_Velic_solL_DefaultNew( Name name );

   void _Underworld_Velic_solL_AssignFromXML( void* analyticSolution, Stg_ComponentFactory* cf, void* data );

   void _Underworld_Velic_solL_Init( Underworld_Velic_solL* self, double sigmaB, double sigmaA, double eta );

   void Underworld_Velic_solL_VelocityFunction( void* _context, double* coord, double* velocity );

   void Underworld_Velic_solL_PressureFunction( void* _context, double* coord, double* pressure );

   void Underworld_Velic_solL_StressFunction( void* _context, double* coord, double* stress );

   void Underworld_Velic_solL_StrainRateFunction( void* _context, double* coord, double* strainRate );

   void _Velic_solL( 
      double  pos[],
      double  _sigma_B,
      double  _sigma_A, /* density B, density A */
      double  _eta, /* viscosity */
      double  vel[],
      double* presssure, 
      double  total_stress[],
      double  strain_rate[] );

#endif
