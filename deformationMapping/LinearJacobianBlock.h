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
#ifndef FLEXIBLE_LinearJacobianBlock_H
#define FLEXIBLE_LinearJacobianBlock_H

#include "../BaseJacobian.h"

namespace sofa
{

namespace defaulttype
{

/** Template class used to implement one jacobian block for linearMapping */
template<class TIn, class TOut>
class LinearJacobianBlock : public BaseJacobianBlock<TIn,TOut> {};


//////////////////////////////////////////////////////////////////////////////////
////  macros
//////////////////////////////////////////////////////////////////////////////////
#define V3(type) StdVectorTypes<Vec<3,type>,Vec<3,type>,type>
#define EV3(type) ExtVectorTypes<Vec<3,type>,Vec<3,type>,type>
#define F331(type)  DefGradientTypes<3,3,0,type>
#define F321(type)  DefGradientTypes<3,2,0,type>
#define F311(type)  DefGradientTypes<3,1,0,type>
#define F332(type)  DefGradientTypes<3,3,1,type>
#define Rigid3(type)  StdRigidTypes<3,type>
#define Affine3(type)  StdAffineTypes<3,type>
#define Quadratic3(type)  StdQuadraticTypes<3,type>

//////////////////////////////////////////////////////////////////////////////////
////  helpers
//////////////////////////////////////////////////////////////////////////////////

template<class Real1, class Real2,  int Dim1, int Dim2>
inline Mat<Dim1, Dim2, Real2> covMN(const Vec<Dim1,Real1>& v1, const Vec<Dim2,Real2>& v2)
{
    Mat<Dim1, Dim2, Real2> res;
    for ( unsigned int i = 0; i < Dim1; ++i)
        for ( unsigned int j = 0; j < Dim2; ++j)
        {
            res[i][j] = (Real2)v1[i] * v2[j];
        }
    return res;
}

template<class _Real>
inline Mat<3, 3, _Real> crossProductMatrix(const Vec<3,_Real>& v)
{
    Mat<3, 3, _Real> res;
    res[0][0]=0;
    res[0][1]=-v[2];
    res[0][2]=v[1];
    res[1][0]=v[2];
    res[1][1]=0;
    res[1][2]=-v[0];
    res[2][0]=-v[1];
    res[2][1]=v[0];
    res[2][2]=0;
    return res;
}


} // namespace defaulttype
} // namespace sofa



#endif
