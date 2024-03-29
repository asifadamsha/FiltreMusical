/**
 * Copyright (C) 2016 D Levin (http://www.kfrlib.com)
 * This file is part of KFR
 *
 * KFR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * KFR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with KFR.
 *
 * If GPL is not suitable for your project, you must purchase a commercial license to use KFR.
 * Buying a commercial license is mandatory as soon as you develop commercial activities without
 * disclosing the source code of your own applications.
 * See http://www.kfrlib.com for details.
 */
#pragma once

#include "fir.hpp"

namespace kfr
{

namespace intrinsics
{
template <typename T>
KFR_SINTRIN void fir_lowpass(univector_ref<T> taps, T cutoff, const expression_pointer<T>& window,
                             bool normalize = true)
{
    const T scale = 2.0 * cutoff;
    taps          = bind_expression(fn::sinc(),
                           symmlinspace<T, true>((taps.size() - 1) * cutoff * c_pi<T>, taps.size(), true)) *
           scale * window;

    if (is_odd(taps.size()))
        taps[taps.size() / 2] = scale;

    if (normalize)
    {
        const T invsum = reciprocal(sum(taps));
        taps           = taps * invsum;
    }
}
template <typename T>
KFR_SINTRIN void fir_highpass(univector_ref<T> taps, T cutoff, const expression_pointer<T>& window,
                              bool normalize = true)
{
    const T scale = 2.0 * -cutoff;
    taps          = bind_expression(fn::sinc(),
                           symmlinspace<T, true>((taps.size() - 1) * cutoff * c_pi<T>, taps.size(), true)) *
           scale * window;

    if (is_odd(taps.size()))
        taps[taps.size() / 2] = 1 - 2.0 * cutoff;

    if (normalize)
    {
        const T invsum = reciprocal(sum(taps) + 1);
        taps           = taps * invsum;
    }
}

template <typename T>
KFR_SINTRIN void fir_bandpass(univector_ref<T> taps, T frequency1, T frequency2,
                              const expression_pointer<T>& window, bool normalize = true)
{
    const T scale1 = 2.0 * frequency1;
    const T scale2 = 2.0 * frequency2;
    const T sc     = c_pi<T> * T(taps.size() - 1);
    const T start1 = sc * frequency1;
    const T start2 = sc * frequency2;

    taps = (bind_expression(fn::sinc(), symmlinspace<T, true>(start2, taps.size(), true)) * scale2 -
            bind_expression(fn::sinc(), symmlinspace<T, true>(start1, taps.size(), true)) * scale1) *
           window;

    if (is_odd(taps.size()))
        taps[taps.size() / 2] = 2 * (frequency2 - frequency1);

    if (normalize)
    {
        const T invsum = reciprocal(sum(taps) + 1);
        taps           = taps * invsum;
    }
}

template <typename T>
KFR_SINTRIN void fir_bandstop(univector_ref<T> taps, T frequency1, T frequency2,
                              const expression_pointer<T>& window, bool normalize = true)
{
    const T scale1 = 2.0 * frequency1;
    const T scale2 = 2.0 * frequency2;
    const T sc     = c_pi<T> * T(taps.size() - 1);
    const T start1 = sc * frequency1;
    const T start2 = sc * frequency2;

    taps = (bind_expression(fn::sinc(), symmlinspace<T, true>(start1, taps.size(), true)) * scale1 -
            bind_expression(fn::sinc(), symmlinspace<T, true>(start2, taps.size(), true)) * scale2) *
           window;

    if (is_odd(taps.size()))
        taps[taps.size() / 2] = 1 - 2 * (frequency2 - frequency1);

    if (normalize)
    {
        const T invsum = reciprocal(sum(taps));
        taps           = taps * invsum;
    }
}
}
KFR_I_FN(fir_lowpass)
KFR_I_FN(fir_highpass)
KFR_I_FN(fir_bandpass)
KFR_I_FN(fir_bandstop)

template <typename T, size_t Tag>
CMT_INLINE void fir_lowpass(univector<T, Tag>& taps, identity<T> cutoff, const expression_pointer<T>& window,
                            bool normalize = true)
{
    return intrinsics::fir_lowpass(taps.slice(), cutoff, window, normalize);
}
template <typename T, size_t Tag>
CMT_INLINE void fir_highpass(univector<T, Tag>& taps, identity<T> cutoff, const expression_pointer<T>& window,
                             bool normalize = true)
{
    return intrinsics::fir_highpass(taps.slice(), cutoff, window, normalize);
}
template <typename T, size_t Tag>
CMT_INLINE void fir_bandpass(univector<T, Tag>& taps, identity<T> frequency1, identity<T> frequency2,
                             const expression_pointer<T>& window, bool normalize = true)
{
    return intrinsics::fir_bandpass(taps.slice(), frequency1, frequency2, window, normalize);
}
template <typename T, size_t Tag>
CMT_INLINE void fir_bandstop(univector<T, Tag>& taps, identity<T> frequency1, identity<T> frequency2,
                             const expression_pointer<T>& window, bool normalize = true)
{
    return intrinsics::fir_bandstop(taps.slice(), frequency1, frequency2, window, normalize);
}

template <typename T>
CMT_INLINE void fir_lowpass(const univector_ref<T>& taps, identity<T> cutoff,
                            const expression_pointer<T>& window, bool normalize = true)
{
    return intrinsics::fir_lowpass(taps, cutoff, window, normalize);
}
template <typename T>
CMT_INLINE void fir_highpass(const univector_ref<T>& taps, identity<T> cutoff,
                             const expression_pointer<T>& window, bool normalize = true)
{
    return intrinsics::fir_highpass(taps, cutoff, window, normalize);
}
template <typename T>
CMT_INLINE void fir_bandpass(const univector_ref<T>& taps, identity<T> frequency1, identity<T> frequency2,
                             const expression_pointer<T>& window, bool normalize = true)
{
    return intrinsics::fir_bandpass(taps, frequency1, frequency2, window, normalize);
}
template <typename T>
CMT_INLINE void fir_bandstop(const univector_ref<T>& taps, identity<T> frequency1, identity<T> frequency2,
                             const expression_pointer<T>& window, bool normalize = true)
{
    return intrinsics::fir_bandstop(taps, frequency1, frequency2, window, normalize);
}
}
