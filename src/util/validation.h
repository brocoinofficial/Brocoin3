// Copyright (c) 2009-2010 Abhishek, Mohit
// Copyright (c) 2009-2019 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BROCOIN_UTIL_VALIDATION_H
#define BROCOIN_UTIL_VALIDATION_H

#include <string>

class CValidationState;

/** Convert CValidationState to a human-readable message for logging */
std::string FormatStateMessage(const CValidationState &state);

extern const std::string strMessageMagic;

#endif // BROCOIN_UTIL_VALIDATION_H
