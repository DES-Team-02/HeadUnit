/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V0_COMMONAPI_HEAD_UNIT_SOMEIP_STUB_ADAPTER_HPP_
#define V0_COMMONAPI_HEAD_UNIT_SOMEIP_STUB_ADAPTER_HPP_

#include <v0/commonapi/HeadUnitStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {

template <typename _Stub = ::v0::commonapi::HeadUnitStub, typename... _Stubs>
class HeadUnitSomeIPStubAdapterInternal
    : public virtual HeadUnitStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> HeadUnitSomeIPStubAdapterHelper;

    ~HeadUnitSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        HeadUnitSomeIPStubAdapterHelper::deinit();
    }

    void fireLightModeAttributeChanged(const bool &_value);
    
    void fireUnitAttributeChanged(const std::string &_value);
    
    void fireMediaImageAttributeChanged(const std::vector< uint8_t > &_value);
    
    void fireMediaNameAttributeChanged(const std::string &_value);
    
    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::HeadUnitStub,
        CommonAPI::Version
    > getHeadUnitInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::HeadUnitStub,
        bool
    > getLightModeAttributeStubDispatcher;
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::HeadUnitStub,
        std::string,
        CommonAPI::SomeIP::StringDeployment
    > getUnitAttributeStubDispatcher;
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::HeadUnitStub,
        std::vector< uint8_t >,
        CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >
    > getMediaImageAttributeStubDispatcher;
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::HeadUnitStub,
        std::string,
        CommonAPI::SomeIP::StringDeployment
    > getMediaNameAttributeStubDispatcher;
    
    HeadUnitSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        HeadUnitSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< HeadUnitStub>(_stub)),
        getHeadUnitInterfaceVersionStubDispatcher(&HeadUnitStub::lockInterfaceVersionAttribute, &HeadUnitStub::getInterfaceVersion, false, true),
        getLightModeAttributeStubDispatcher(
            &::v0::commonapi::HeadUnitStub::lockLightModeAttribute,
            &::v0::commonapi::HeadUnitStub::getLightModeAttribute,
            false,
            _stub->hasElement(0))
        ,
        getUnitAttributeStubDispatcher(
            &::v0::commonapi::HeadUnitStub::lockUnitAttribute,
            &::v0::commonapi::HeadUnitStub::getUnitAttribute,
            false,
            _stub->hasElement(1))
        ,
        getMediaImageAttributeStubDispatcher(
            &::v0::commonapi::HeadUnitStub::lockMediaImageAttribute,
            &::v0::commonapi::HeadUnitStub::getMediaImageAttribute,
            false,
            _stub->hasElement(2))
        ,
        getMediaNameAttributeStubDispatcher(
            &::v0::commonapi::HeadUnitStub::lockMediaNameAttribute,
            &::v0::commonapi::HeadUnitStub::getMediaNameAttribute,
            false,
            _stub->hasElement(3))
    {
        HeadUnitSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x1fa5) }, &getLightModeAttributeStubDispatcher );
        HeadUnitSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x2009) }, &getUnitAttributeStubDispatcher );
        HeadUnitSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x206d) }, &getMediaImageAttributeStubDispatcher );
        HeadUnitSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x20d1) }, &getMediaNameAttributeStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>();

        // Provided events/fields
        if (_stub->hasElement(0)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x1fa4)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x13c68), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireLightModeAttributeChanged(std::dynamic_pointer_cast< ::v0::commonapi::HeadUnitStub>(_stub)->getLightModeAttribute(itsClient));
        }

        if (_stub->hasElement(1)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x2008)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x14050), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireUnitAttributeChanged(std::dynamic_pointer_cast< ::v0::commonapi::HeadUnitStub>(_stub)->getUnitAttribute(itsClient));
        }

        if (_stub->hasElement(2)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x206c)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x14438), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireMediaImageAttributeChanged(std::dynamic_pointer_cast< ::v0::commonapi::HeadUnitStub>(_stub)->getMediaImageAttribute(itsClient));
        }

        if (_stub->hasElement(3)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x206c)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x14820), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireMediaNameAttributeChanged(std::dynamic_pointer_cast< ::v0::commonapi::HeadUnitStub>(_stub)->getMediaNameAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireLightModeAttributeChanged(const bool &_value) {
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            bool
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x13c68),
        false,
        _value
    );
}

template <typename _Stub, typename... _Stubs>
void HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireUnitAttributeChanged(const std::string &_value) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deployedValue(_value, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x14050),
        false,
        deployedValue
    );
}

template <typename _Stub, typename... _Stubs>
void HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireMediaImageAttributeChanged(const std::vector< uint8_t > &_value) {
    CommonAPI::Deployable< std::vector< uint8_t >, CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >> deployedValue(_value, static_cast< CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::vector< uint8_t >,
                CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >
            >
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x14438),
        false,
        deployedValue
    );
}

template <typename _Stub, typename... _Stubs>
void HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireMediaNameAttributeChanged(const std::string &_value) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deployedValue(_value, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x14820),
        false,
        deployedValue
    );
}


template <typename _Stub, typename... _Stubs>
void HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {

}

template <typename _Stub, typename... _Stubs>
void HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {

}

template <typename _Stub = ::v0::commonapi::HeadUnitStub, typename... _Stubs>
class HeadUnitSomeIPStubAdapter
    : public HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    HeadUnitSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          HeadUnitSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_Head_Unit_SOMEIP_STUB_ADAPTER_HPP_
