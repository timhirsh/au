// Copyright 2022 Aurora Operations, Inc.

#pragma once

#include "au/quantity.hh"

namespace au {

// DO NOT follow this pattern to define your own units.  This is for library-defined units.
// Instead, follow instructions at (https://aurora-opensource.github.io/au/howto/new-units).
template <typename T>
struct MolesLabel {
    static constexpr const char label[] = "mol";
};
template <typename T>
constexpr const char MolesLabel<T>::label[];
struct Moles : UnitImpl<AmountOfSubstance>, MolesLabel<void> {
    using MolesLabel<void>::label;
};
constexpr auto mole = SingularNameFor<Moles>{};
constexpr auto moles = QuantityMaker<Moles>{};

}  // namespace au
