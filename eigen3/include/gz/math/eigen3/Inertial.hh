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
#ifndef GZ_MATH_EIGEN3_INERTIAL_HH_
#define GZ_MATH_EIGEN3_INERTIAL_HH_

#include <optional>

#include <Eigen/Geometry>

#include <gz/math/config.hh>
#include <gz/math/Inertial.hh>
#include <gz/math/eigen3/FluidAddedMass.hh>

namespace gz
{
namespace math
{
namespace eigen3
{
// Inline bracket to help doxygen filtering.
inline namespace GZ_MATH_VERSION_NAMESPACE {
  //
  /// \class Inertial Inertial.hh gz/math/eigen/Inertial.hh
  /// \brief A class for the inertial properties added to a rigid body by its
  /// movement through a fluid. This class contains 21 unique values
  /// expressed in a symmetric 6x6 matrix.
  template<typename T>
  class Inertial
  {
    /// \brief Default Constructor, which inializes the matrices to zero.
    public: Inertial()
    {}

    /// \brief Constructor.
    /// \param[in] _inertial Rigid body inertial properties
    public: Inertial(const math::Inertial<T> &_inertial)
    : inertial(_inertial)
    {}

    /// \brief Constructor.
    /// \param[in] _inertial Rigid body inertial properties
    public: Inertial(const math::Inertial<T> &_inertial,
                     const FluidAddedMass<T> &_fluidAddedMass)
    : inertial(_inertial), fluidAddedMass(_fluidAddedMass)
    {}

    /// \brief Copy constructor.
    /// \param[in] _i Inertial element to copy
    public: Inertial(const Inertial<T> &_i) = default;

    /// \brief Destructor.
    public: ~Inertial() = default;

    /// \brief Equal operator.
    /// \param[in] _inertial Inertial to copy.
    /// \return Reference to this object.
    public: Inertial &operator=(const Inertial<T> &_inertial)
      = default;

    /// \brief Get the combination of rigid body inertial parameters with
    /// fluid added mass parameters as a 6x6 spatial matrix
    /// with the rotational block in the upper left and translational block
    /// in the lower right.
    public: Eigen::Matrix<T, 6, 6> SpatialInertiaMatrix() const
    {
      // implementation
    }

    /// \brief Rigid body inertial properties.
    private: math::Inertial<T> inertial;

    /// \brief 
    private: std::optional<FluidAddedMass> fluidAddedMass;
  };

  typedef Inertial<double> Inertiald;
  typedef Inertial<float> Inertialf;
}
}
}
}
#endif
