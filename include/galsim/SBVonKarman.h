/* -*- c++ -*-
 * Copyright (c) 2012-2017 by the GalSim developers team on GitHub
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

#ifndef GalSim_SBVonKarman_H
#define GalSim_SBVonKarman_H
/**
 * @file SBVonKarman.h @brief SBProfile for von Karman turbulence PSF, potentially including
 *                            truncated power spectrum.
 */

#include "SBProfile.h"

namespace galsim {

    namespace sbp {
        // How many VonKarman profiles to save in the cache
        const int max_vonKarman_cache = 100;
    }

    class SBVonKarman : public SBProfile
    {
    public:
        /**
         * @brief Constructor.
         *
         * Note I'm assuming all units are mks.
         *
         * @param[in] lam          Wavelength in m.
         * @param[in] r0           Fried parameter in m (at given wavelength lam).
         * @param[in] L0           Outer scale in m.
         * @param[in] kcrit        Critical Fourier mode scale in radians per meter.
         * @param[in] flux         Flux.
         * @param[in] maxk         If > 0, then force maxk to this value.
         * @param[in] gsparams     GSParams.
         */
        SBVonKarman(double lam, double r0, double L0, double kcrit, double flux, double maxk,
            const GSParamsPtr& gsparams);

        /// @brief Copy constructor
        SBVonKarman(const SBVonKarman& rhs);

        /// @brief Destructor.
        ~SBVonKarman();

        /// Getters
        double getLam() const;
        double getR0() const;
        double getL0() const;
        double getKCrit() const;

        double structureFunction(double) const;

    protected:

        class SBVonKarmanImpl;

    private:
        // op= is undefined
        void operator=(const SBVonKarman& rhs);
    };
}

#endif
