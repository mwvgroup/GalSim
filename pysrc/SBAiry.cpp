// -*- c++ -*-
/*
 * Copyright 2012, 2013 The GalSim developers:
 * https://github.com/GalSim-developers
 *
 * This file is part of GalSim: The modular galaxy image simulation toolkit.
 *
 * GalSim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GalSim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GalSim.  If not, see <http://www.gnu.org/licenses/>
 */
#ifndef __INTEL_COMPILER
#if defined(__GNUC__) && __GNUC__ >= 4 && (__GNUC__ >= 5 || __GNUC_MINOR__ >= 8)
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif
#endif

#include "boost/python.hpp"
#include "boost/python/stl_iterator.hpp"

#include "SBAiry.h"

namespace bp = boost::python;

namespace galsim {

    struct PySBAiry 
    {
        static SBAiry* construct(
            double lam_over_diam, double obscuration, double flux,
            boost::shared_ptr<GSParams> gsparams)
        {
            // Duplicate the GSParams object.  Otherwise, the original gsparams constructed
            // in the python layer might be garbage collected before the LRUCache is cleaned
            // up, which can lead to segmentation faults.  cf. Isue #455.
            if (gsparams.get())
                gsparams.reset(new GSParams(*gsparams));
            return new SBAiry(lam_over_diam, obscuration, flux, gsparams);
        }

        static void wrap() 
        {
            bp::class_<SBAiry,bp::bases<SBProfile> >("SBAiry", bp::no_init)
                .def("__init__",
                     bp::make_constructor(
                         &construct, bp::default_call_policies(),
                         (bp::arg("lam_over_diam"), bp::arg("obscuration")=0., bp::arg("flux")=1.,
                          bp::arg("gsparams")=bp::object())
                ))
                .def(bp::init<const SBAiry &>())
                .def("getLamOverD", &SBAiry::getLamOverD)
                .def("getObscuration", &SBAiry::getObscuration)
                ;
        }
    };

    void pyExportSBAiry() 
    {
        PySBAiry::wrap();
    }

} // namespace galsim
