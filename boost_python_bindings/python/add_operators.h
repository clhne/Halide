#ifndef ADD_OPERATORS_H
#define ADD_OPERATORS_H

#include <boost/python/operators.hpp>
#include <boost/python/self.hpp>
//#include <boost/python/def.hpp>

template<typename PythonClass, typename T>
void add_operators_with(PythonClass &class_instance)
{
    using namespace boost::python;

    class_instance
            .def(self + T())
            .def(T() + self)

            .def(self - T())
            .def(T() - self)

            .def(self * T())
            .def(T() * self)

            .def(self / T())
            .def(T() / self)

            .def(self % T())
            .def(T() % self)

            .def(pow(self, T()))
            .def(pow(T(), self))

            .def(self & T())
            .def(T() & self)

            .def(self | T())
            .def(T() | self)

            .def(self < T())
            .def(T() < self)

            .def(self <= T())
            .def(T() <= self)

            .def(self == T())
            .def(T() == self)

            .def(self != T())
            .def(T() != self)

            .def(self > T())
            .def(T() > self)

            .def(self >= T())
            .def(T() >= self);

    return;
}

template<typename PythonClass>
void add_operators(PythonClass &class_instance)
{
    using namespace boost::python;

    class_instance
            .def(self + self)
            .def(self - self)
            .def(self * self)
            .def(self / self)
            .def(self % self)
            //.def(pow(self, p::other<float>))
            .def(pow(self, self))
            .def(self & self) // and
            .def(self | self) // or
            .def(-self) // neg
            .def(~self) // invert
            .def(self < self)
            .def(self <= self)
            .def(self == self)
            .def(self != self)
            .def(self > self)
            .def(self >= self);

    add_operators_with<PythonClass, int>(class_instance);
    add_operators_with<PythonClass, float>(class_instance);
    return;
}

#endif // ADD_OPERATORS_H
