/*
 * Copyright (C) 2021 Open Source Robotics Foundation
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

#ifndef GZ_MATH_PYTHON__TRIANGLE3_HH_
#define GZ_MATH_PYTHON__TRIANGLE3_HH_

#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

#include <gz/math/Triangle3.hh>

namespace py = pybind11;
using namespace pybind11::literals;

namespace ignition
{
namespace math
{
namespace python
{
/// Define a pybind11 wrapper for an gz::math::Triangle3
/**
 * \param[in] module a pybind11 module to add the definition to
 * \param[in] typestr name of the type used by Python
 */
void defineMathTriangle3(py::module &m, const std::string &typestr);

/// Help define a pybind11 wrapper for an gz::math::Triangle3
/**
 * \param[in] module a pybind11 module to add the definition to
 * \param[in] typestr name of the type used by Python
 */
template<typename T>
void helpDefineMathTriangle3(py::module &m, const std::string &typestr)
{
  using Class = gz::math::Triangle3<T>;
  py::class_<Class>(m,
                    typestr.c_str(),
                    py::buffer_protocol(),
                    py::dynamic_attr())
    .def(py::init<>())
    .def(py::init<const math::Vector3<T> &,
                  const math::Vector3<T> &,
                  const math::Vector3<T> &>())
    .def(py::init<const Class>())
    .def("set",
         py::overload_cast<const unsigned int, const math::Vector3<T> &>
            (&Class::Set),
         "Set one vertex of the triangle.")
    .def("set",
         py::overload_cast<const math::Vector3<T> &,
                           const math::Vector3<T> &,
                           const math::Vector3<T> &>
           (&Class::Set),
         "Set all vertices of the triangle.")
    .def("valid",
         &Class::Valid,
         "Get whether this triangle is valid, based on triangle "
         "inequality: the sum of the lengths of any two sides must be greater "
         "than the length of the remaining side.")
    .def("side",
         &Class::Side,
         "Get a line segment for one side of the triangle.")
    .def("contains",
         py::overload_cast<const Line3<T>&>(&Class::Contains, py::const_),
         "Check if this triangle completely contains the given line "
         "segment.")
    .def("contains",
         py::overload_cast<const Vector3<T>&>(&Class::Contains, py::const_),
         "Get whether this triangle contains the given point")
    .def("intersects",
         &Class::Intersects,
         "Get whether the given line intersects this triangle.")
    .def("perimeter",
         &Class::Perimeter,
         "Get the length of the triangle's perimeter.")
    .def("area", &Class::Area, "Get the area of this triangle.")
    .def("normal", &Class::Normal, "Get the triangle's normal vector.")
    .def("__copy__", [](const Class &self) {
      return Class(self);
    })
    .def("__deepcopy__", [](const Class &self, py::dict) {
      return Class(self);
    }, "memo"_a)
    .def("__getitem__",
         (&Class::operator[]))
    .def("__getitem__",
         py::overload_cast<const std::size_t>(&Class::operator[], py::const_))
    .def("__setitem__",
         [](Class* vec, unsigned index, T val) { (*vec)[index] = val; });
}

}  // namespace python
}  // namespace math
}  // namespace ignition

#endif  // GZ_MATH_PYTHON__TRIANGLE3_HH_
