#if (YY_Thunks_Target < __WindowsNT6_2)
#include <windns.h>
#endif

namespace YY::Thunks
{
#if (YY_Thunks_Target < __WindowsNT6_2)

    // Minimum supported client	Windows 8 [desktop apps only]
    // Minimum supported server	Windows Server 2012[desktop apps only]
    __DEFINE_THUNK(
    dnsapi,
    12,
    DNS_STATUS,
    WINAPI,
    DnsQueryEx,
        _In_        PDNS_QUERY_REQUEST _pQueryRequest,
        _Inout_     PDNS_QUERY_RESULT _pQueryResults,
        _Inout_opt_ PDNS_QUERY_CANCEL _pCancelHandle
        )
    {
        if (const auto _pfnDnsQueryEx = try_get_DnsQueryEx())
        {
            return _pfnDnsQueryEx(_pQueryRequest, _pQueryResults, _pCancelHandle);
        }

        return {};
    }
#endif
}
