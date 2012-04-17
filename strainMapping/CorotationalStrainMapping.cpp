/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 RC 1        *
*                (c) 2006-2011 MGH, INRIA, USTL, UJF, CNRS                    *
*                                                                             *
* This library is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This library is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this library; if not, write to the Free Software Foundation,     *
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.          *
*******************************************************************************
*                               SOFA :: Plugins                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#define SOFA_COMPONENT_MAPPING_CorotationalStrainMAPPING_CPP

#include "../initFlexible.h"
#include "../strainMapping/CorotationalStrainMapping.h"
#include <sofa/core/ObjectFactory.h>

#include "../types/DeformationGradientTypes.h"
#include "../types/StrainTypes.h"

namespace sofa
{
namespace component
{

namespace mapping
{
SOFA_DECL_CLASS(CorotationalStrainMapping);

using namespace defaulttype;

// Register in the Factory
int CorotationalStrainMappingClass = core::RegisterObject("Map Deformation Gradients to Corotational Strain (small local deformations).")

#ifndef SOFA_FLOAT
        .add< CorotationalStrainMapping< DefGradient331dTypes, Strain331dTypes > >(true)
        .add< CorotationalStrainMapping< DefGradient332dTypes, Strain332dTypes > >()
#endif
#ifndef SOFA_DOUBLE
        .add< CorotationalStrainMapping< DefGradient331fTypes, Strain331fTypes > >()
        .add< CorotationalStrainMapping< DefGradient332fTypes, Strain332fTypes > >()
#endif
        ;

#ifndef SOFA_FLOAT
template class SOFA_Flexible_API CorotationalStrainMapping< DefGradient331dTypes, Strain331dTypes >;
template class SOFA_Flexible_API CorotationalStrainMapping< DefGradient332dTypes, Strain332dTypes >;
#endif
#ifndef SOFA_DOUBLE
template class SOFA_Flexible_API CorotationalStrainMapping< DefGradient331fTypes, Strain331fTypes >;
template class SOFA_Flexible_API CorotationalStrainMapping< DefGradient332fTypes, Strain332fTypes >;
#endif

} // namespace mapping

} // namespace component

} // namespace sofa
