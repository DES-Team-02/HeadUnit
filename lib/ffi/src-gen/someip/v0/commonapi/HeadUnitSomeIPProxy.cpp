/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v0/commonapi/HeadUnitSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createHeadUnitSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< HeadUnitSomeIPProxy>(_address, _connection);
}

void initializeHeadUnitSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.HeadUnit:v0_1:commonapi.HeadUnit",
        0x1f40, 0x1f41, 0, 1);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.HeadUnit:v0_1",
        &createHeadUnitSomeIPProxy);
}

INITIALIZER(registerHeadUnitSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeHeadUnitSomeIPProxy);
}

HeadUnitSomeIPProxy::HeadUnitSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          lightMode_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x1fa4), CommonAPI::SomeIP::event_id_t(0x13c68), CommonAPI::SomeIP::method_id_t(0x1fa5), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, static_cast< CommonAPI::EmptyDeployment* >(nullptr)),
          unit_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x2008), CommonAPI::SomeIP::event_id_t(0x14050), CommonAPI::SomeIP::method_id_t(0x2009), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)),
          mediaImage_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x206c), CommonAPI::SomeIP::event_id_t(0x14438), CommonAPI::SomeIP::method_id_t(0x206d), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, static_cast< CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >* >(nullptr)),
          mediaName_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x206c), CommonAPI::SomeIP::event_id_t(0x14820), CommonAPI::SomeIP::method_id_t(0x20d1), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr))
{
}

HeadUnitSomeIPProxy::~HeadUnitSomeIPProxy() {
}

HeadUnitSomeIPProxy::LightModeAttribute& HeadUnitSomeIPProxy::getLightModeAttribute() {
    return lightMode_;
}
HeadUnitSomeIPProxy::UnitAttribute& HeadUnitSomeIPProxy::getUnitAttribute() {
    return unit_;
}
HeadUnitSomeIPProxy::MediaImageAttribute& HeadUnitSomeIPProxy::getMediaImageAttribute() {
    return mediaImage_;
}
HeadUnitSomeIPProxy::MediaNameAttribute& HeadUnitSomeIPProxy::getMediaNameAttribute() {
    return mediaName_;
}


void HeadUnitSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 0;
    ownVersionMinor = 1;
}

std::future<void> HeadUnitSomeIPProxy::getCompletionFuture() {
    return CommonAPI::SomeIP::Proxy::getCompletionFuture();
}

} // namespace commonapi
} // namespace v0
