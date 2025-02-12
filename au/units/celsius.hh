// Copyright 2022 Aurora Operations, Inc.

#pragma once

#include "au/prefix.hh"
#include "au/quantity.hh"
#include "au/quantity_point.hh"
#include "au/units/kelvins.hh"

namespace au {

// DO NOT follow this pattern to define your own units.  This is for library-defined units.
// Instead, follow instructions at (https://aurora-opensource.github.io/au/howto/new-units).
template <typename T>
struct CelsiusLabel {
    static constexpr const char label[] = "degC";
};
template <typename T>
constexpr const char CelsiusLabel<T>::label[];
struct Celsius : Kelvins, CelsiusLabel<void> {
    using CelsiusLabel<void>::label;
    static constexpr auto origin() { return centi(kelvins)(273'15); }
};
constexpr auto celsius_qty = QuantityMaker<Celsius>{};
constexpr auto celsius_pt = QuantityPointMaker<Celsius>{};

[[deprecated(
    "`celsius()` is ambiguous.  Use `celsius_pt()` for _points_, or `celsius_qty()` for "
    "_quantities_")]] constexpr auto celsius = QuantityMaker<Celsius>{};

}  // namespace au
