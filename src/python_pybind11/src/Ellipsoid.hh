/*
 * Copyright (C) 2022 Open Source Robotics Foundation
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

#ifndef GZ_MATH_PYTHON__Ellipsoid_HH_
#define GZ_MATH_PYTHON__Ellipsoid_HH_

#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

#include <gz/math/Ellipsoid.hh>
#include <gz/math/Vector3.hh>

namespace py = pybind11;
using namespace pybind11::literals;

namespace ignition
{
namespace math
{
namespace python
{
/// Define a pybind11 wrapper for an gz::math::Ellipsoid
/**
 * \param[in] module a pybind11 module to add the definition to
 * \param[in] typestr name of the type used by Python
 */
template<typename T>
void helpDefineMathEllipsoid(py::module &m, const std::string &typestr)
{
  using Class = gz::math::Ellipsoid<T>;
  std::string pyclass_name = typestr;
  py::class_<Class>(m,
                    pyclass_name.c_str(),
                    py::buffer_protocol(),
                    py::dynamic_attr())
    .def(py::init<>())
    .def(py::init<gz::math::Vector3<T>>())
    .def(py::init<gz::math::Vector3<T>,
                  const gz::math::Material&>())
    .def(py::self == py::self)
    .def("radii",
         &Class::Radii,
         "Get the radius in meters.")
    .def("set_radii",
         &Class::SetRadii,
         "Set the radius in meters.")
    .def("material",
         &Class::Mat,
         "Get the material associated with this Ellipsoid.")
    .def("set_material",
         &Class::SetMat,
         "Set the material associated with this Ellipsoid.")
    .def("mass_matrix",
         &Class::MassMatrix,
         "Get the mass matrix for this box. This function "
         "is only meaningful if the box's size and material "
         "have been set.")
    .def("volume",
         &Class::Volume,
         "Get the volume of the Ellipsoid in m^3.")
    .def("density_from_mass",
         &Class::DensityFromMass,
         "Compute the box's density given a mass value.")
    .def("set_density_from_mass",
         &Class::SetDensityFromMass,
         "Set the density of this box based on a mass value.")
    .def("__copy__", [](const Class &self) {
      return Class(self);
    })
    .def("__deepcopy__", [](const Class &self, py::dict) {
      return Class(self);
    }, "memo"_a);
}

/// Define a pybind11 wrapper for an gz::math::Ellipsoid
/**
 * \param[in] module a pybind11 module to add the definition to
 * \param[in] typestr name of the type used by Python
 */
void defineMathEllipsoid(py::module &m, const std::string &typestr);

}  // namespace python
}  // namespace math
}  // namespace ignition

#endif  // GZ_MATH_PYTHON__BOX_HH_
