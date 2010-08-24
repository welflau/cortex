//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2010, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef IE_CORE_POINTBOUNDSOP_H
#define IE_CORE_POINTBOUNDSOP_H

#include "IECore/Op.h"
#include "IECore/NumericParameter.h"

namespace IECore
{

IE_CORE_FORWARDDECLARE( ObjectParameter )

/// The PointBoundsOp calculates a bound box for a set of points.
class PointBoundsOp : public Op
{
	public :

		IE_CORE_DECLARERUNTIMETYPED( PointBoundsOp, Op );

		PointBoundsOp();
		virtual ~PointBoundsOp();

		/// The Parameter for the input point cloud.
		ObjectParameter * pointParameter();
		const ObjectParameter * pointParameter() const;

		/// The Parameter for point velocities.
		ObjectParameter * velocityParameter();
		const ObjectParameter * velocityParameter() const;

		FloatParameter * velocityMultiplierParameter();
		const FloatParameter * velocityMultiplierParameter() const;

		/// The Parameter for optional point radii.
		ObjectParameter * radiusParameter();
		const ObjectParameter * radiusParameter() const;

		FloatParameter * radiusMultiplierParameter();
		const FloatParameter * radiusMultiplierParameter() const;

	protected :

		virtual ObjectPtr doOperation( const CompoundObject * operands );

	private :

		ObjectParameterPtr m_pointParameter;
		ObjectParameterPtr m_radiusParameter;
		FloatParameterPtr m_radiusMultiplierParameter;
		ObjectParameterPtr m_velocityParameter;
		FloatParameterPtr m_velocityMultiplierParameter;

};

IE_CORE_DECLAREPTR( PointBoundsOp );

} // namespace IECore

#endif // IE_CORE_POINTBOUNDSOP_H