/******************************************************************************
*       SOFA, Simulation Open-Framework Architecture, version 1.0 beta 4      *
*                (c) 2006-2009 MGH, INRIA, USTL, UJF, CNRS                    *
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
*                               SOFA :: Modules                               *
*                                                                             *
* Authors: The SOFA Team and external contributors (see Authors.txt)          *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#define SOFA_HookeFORCEFIELD_CPP

#include "../initFlexible.h"
#include "../material/HookeForceField.h"
#include "../types/StrainTypes.h"
#include <sofa/core/ObjectFactory.h>

namespace sofa
{
namespace component
{
namespace forcefield
{

SOFA_DECL_CLASS(HookeForceField);

using namespace defaulttype;

// Register in the Factory
int HookeForceFieldClass = core::RegisterObject("Hooke's Law for isotropic homogeneous materials")

#ifndef SOFA_FLOAT
        .add< HookeForceField< Strain331dTypes > >(true)
//.add< HookeForceField< Strain332dTypes > >()
//.add< HookeForceField< Strain333dTypes > >()
#endif
#ifndef SOFA_DOUBLE
        .add< HookeForceField< Strain331fTypes > >()
//.add< HookeForceField< Strain332fTypes > >()
//.add< HookeForceField< Strain333fTypes > >()
#endif
        ;

#ifndef SOFA_FLOAT
template class SOFA_Flexible_API HookeForceField< Strain331dTypes >;
//template class SOFA_Flexible_API HookeForceField< Strain332dTypes >;
//template class SOFA_Flexible_API HookeForceField< Strain333dTypes >;
#endif
#ifndef SOFA_DOUBLE
template class SOFA_Flexible_API HookeForceField< Strain331fTypes >;
//template class SOFA_Flexible_API HookeForceField< Strain332fTypes >;
//template class SOFA_Flexible_API HookeForceField< Strain333fTypes >;
#endif

}
}
}
