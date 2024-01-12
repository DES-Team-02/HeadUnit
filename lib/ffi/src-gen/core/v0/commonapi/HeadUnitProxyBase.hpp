/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.14.v202310241605.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_Head_Unit_PROXY_BASE_HPP_
#define V0_COMMONAPI_Head_Unit_PROXY_BASE_HPP_

#include <v0/commonapi/HeadUnit.hpp>



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <vector>

#include <CommonAPI/Attribute.hpp>
#include <CommonAPI/Proxy.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {

class HeadUnitProxyBase
    : virtual public CommonAPI::Proxy {
public:
    typedef CommonAPI::ObservableReadonlyAttribute<bool> LightModeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute<std::string> UnitAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute<std::vector< uint8_t >> MediaImageAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute<std::string> MediaNameAttribute;


    virtual LightModeAttribute& getLightModeAttribute() = 0;
    virtual UnitAttribute& getUnitAttribute() = 0;
    virtual MediaImageAttribute& getMediaImageAttribute() = 0;
    virtual MediaNameAttribute& getMediaNameAttribute() = 0;

    virtual std::future<void> getCompletionFuture() = 0;
};

} // namespace commonapi
} // namespace v0


// Compatibility
namespace v0_1 = v0;

#endif // V0_COMMONAPI_Head_Unit_PROXY_BASE_HPP_