// Copyright (c) 2009-2010 Abhishek, Mohit
// Copyright (c) 2009-2018 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <policy/feerate.h>

#include <tinyformat.h>

const std::string CURRENCY_UNIT = "BRON";

CFeeRate::CFeeRate(const CAmount& nFeePaid, size_t nBytes_)
{
    assert(nBytes_ <= uint64_t(std::numeric_limits<int64_t>::max()));
    int64_t nSize = int64_t(nBytes_);

    if (nSize > 0)
        nBroneesPerK = nFeePaid * 1000 / nSize;
    else
        nBroneesPerK = 0;
}

CAmount CFeeRate::GetFee(size_t nBytes_) const
{
    assert(nBytes_ <= uint64_t(std::numeric_limits<int64_t>::max()));
    int64_t nSize = int64_t(nBytes_);

    CAmount nFee = nBroneesPerK * nSize / 1000;

    if (nFee == 0 && nSize != 0) {
        if (nBroneesPerK > 0)
            nFee = CAmount(1);
        if (nBroneesPerK < 0)
            nFee = CAmount(-1);
    }

    return nFee;
}

std::string CFeeRate::ToString() const
{
    return strprintf("%d.%08d %s/kB", nBroneesPerK / COIN, nBroneesPerK % COIN, CURRENCY_UNIT);
}
