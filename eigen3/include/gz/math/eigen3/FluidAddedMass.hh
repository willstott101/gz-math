/*
 * Copyright (C) 2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef GZ_MATH_EIGEN3_FLUIDADDEDMASS_HH_
#define GZ_MATH_EIGEN3_FLUIDADDEDMASS_HH_

#include <Eigen/Geometry>

#include <gz/math/config.hh>
#include <gz/math/Matrix3.hh>

namespace gz
{
namespace math
{
namespace eigen3
{
// Inline bracket to help doxygen filtering.
inline namespace GZ_MATH_VERSION_NAMESPACE {
  //
  /// \class FluidAddedMass FluidAddedMass.hh gz/math/eigen/FluidAddedMass.hh
  /// \brief A class for the inertial properties added to a rigid body by its
  /// movement through a fluid. This class contains 21 unique values
  /// expressed in a symmetric 6x6 matrix.
  template<typename T>
  class FluidAddedMass
  {
    /// \brief Default Constructor, which inializes the matrices to zero.
    public: FluidAddedMass()
    {}

    /// \brief Constructor.
    /// \param[in] _xyzBlockDiagonal Block-diagonal symmetric matrix of
    /// translational added mass terms.
    /// \param[in] _pqrBlockDiagonal Block-diagonal symmetric matrix of
    /// rotational added mass terms.
    /// \param[in] _xyzRowColPQR Block-off-diagonal matrix corresponding to
    /// mixed rotational and translational terms.
    public: FluidAddedMass(const Matrix3<T> &_xyzBlockDiagonal,
                        const Matrix3<T> &_pqrBlockDiagonal,
                        const Matrix3<T> &_xyzRowColPQR)
    : xyzBlockDiagonal(_xyzBlockDiagonal),
      pqrBlockDiagonal(_pqrBlockDiagonal),
      xyzRowColPQR(_xyzRowColPQR),
    {}

    /// \brief Copy constructor.
    /// \param[in] _f FluidAddedMass element to copy
    public: FluidAddedMass(const FluidAddedMass<T> &_f) = default;

    /// \brief Destructor.
    public: ~FluidAddedMass() = default;

    /// \brief Equal operator.
    /// \param[in] _f FluidAddedMass to copy.
    /// \return Reference to this object.
    public: FluidAddedMass &operator=(const FluidAddedMass<T> &_f)
      = default;

    /// \brief Get the fluid added mass parameters as a 6x6 spatial matrix
    /// with the rotational block in the upper left and translational block
    /// in the lower right.
    public: Eigen::Matrix<T, 6, 6> SpatialInertiaMatrix() const
    {
      // implementation
    }

    /// \brief Block diagonal symmetric 3x3 matrix corresponding to
    /// translational added mass terms. Only the upper diagonal elements of
    /// this matrix are used.
    private: Matrix3<T> xyzBlockDiagonal;

    /// \brief Block diagonal symmetric 3x3 matrix corresponding to rotational
    /// added mass terms. Only the upper diagonal elements of this matrix are
    /// used.
    private: Matrix3<T> pqrBlockDiagonal;

    /// \brief Block off-diagonal 3x3 matrix corresponding to mixed rotational
    /// and translational terms. The matrix is stored with xyz values constant
    /// in each row and pqr values constant in each column, as in:
    /// xp xq xr
    /// yp yq yr
    /// zp zq zr
    private: Matrix3<T> xyzRowColPQR;
  };

  typedef FluidAddedMass<double> FluidAddedMassd;
  typedef FluidAddedMass<float> FluidAddedMassf;
}
}
}
}
#endif
