/* -*- c++ -*-
 * Copyright (c) 2012-2016 by the GalSim developers team on GitHub
 * https://github.com/GalSim-developers
 *
 * This file is part of GalSim: The modular galaxy image simulation toolkit.
 * https://github.com/GalSim-developers/GalSim
 *
 * GalSim is free software: redistribution and use in source and binary forms,
 * with or without modification, are permitted provided that the following
 * conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions, and the disclaimer given in the accompanying LICENSE
 *    file.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions, and the disclaimer given in the documentation
 *    and/or other materials provided with the distribution.
 */

#ifndef GalSim_SBInclinedExponential_H
#define GalSim_SBInclinedExponential_H
/**
 * @file SBInclinedExponential.h @brief SBProfile that implements an inclined exponential profile.
 */

#include "SBProfile.h"

namespace galsim {

    namespace sbp {

        // Constrain range of allowed inclination angles in radians.
        const double minimum_exponential_inclination_rad = 0.;
        const double minimum_exponential_inclination_rad = M_PI/2.;

        // How many profiles to save in the cache
        const int max_inclined_exponential_cache = 100;

    }

    /**
     * @brief Inclined Exponential surface brightness profile.
     *
     * TODO: Fill in
     */
    class SBInclinedExponential : public SBProfile
    {
    public:

        /**
         * @brief Constructor.
         *
         * @param[in] i                 Inclination angle i in radians, where 0 = face-on, pi/2 = edge-on
         * @param[in] scale_radius      Scale radius of the exponential disk.
         * @param[in] scale_height      Scale height of the exponential disk.
         * @param[in] flux              Flux.
         * @param[in] trunc             Outer truncation radius in same physical units as size;
         *                              `trunc = 0.` for no truncation.
         * @param[in] flux_untruncated  If `true`, sets the flux to the untruncated version of the
         *                              Sersic profile with the same index `n`.  Ignored if
         *                              `trunc = 0.`.
         * @param[in] gsparams          GSParams object storing constants that control the accuracy
         *                              of image operations and rendering, if different from the
         *                              default.
         */
    	SBInclinedExponential(double i, double scale_radius, double scale_height, double flux,
                 double trunc, bool flux_untruncated, const GSParamsPtr& gsparams);

        /// @brief Copy constructor.
    	SBInclinedExponential(const SBInclinedExponential& rhs);

        /// @brief Destructor.
        ~SBInclinedExponential();

        /// @brief Returns the inclination angle 'i' of the profile in radians
        double getI() const;

        /// @brief Returns the scale radius r0 of the disk profile
        double getScaleRadius() const;

        /// @brief Returns the scale height r0 of the disk profile
        double getScaleHeight() const;

        /// @brief Returns the truncation radius
        double getTrunc() const;

    protected:

        class SBInclinedExponentialImpl;

    private:

        // op= is undefined
        void operator=(const SBInclinedExponential& rhs);
    };
}

#endif