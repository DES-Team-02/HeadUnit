#ifndef EXTERNC
# define EXPORT extern "C" __attribute__((visibility("default"))) __attribute__((used))
#endif

#include "HeadUnitStubImpl.hpp"

std::shared_ptr<HeadUnitStubImpl> headUnitService;

HeadUnitStubImpl::HeadUnitStubImpl(){};
HeadUnitStubImpl::~HeadUnitStubImpl(){};

void registerHeadUnitService()
{
	std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
	headUnitService = std::make_shared<HeadUnitStubImpl>();
	std::string domain = "local";
	std::string instance = "commonapi.HeadUnit";
	std::string connection = "service-HeadUnit";

	HeadUnit::MetaData metadata;
	std::vector<uint8_t> image(0, 0);
	metadata.setAlbumcover(image);
	metadata.setArtist("Not Playing");
	metadata.setTitle("");
	headUnitService->setMetadataAttribute(metadata);
	headUnitService->setLightModeAttribute(true);
	headUnitService->setUnitAttribute("SI");

	while (!runtime->registerService(domain, instance, headUnitService, connection))
	{
		std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << "Successfully Registered Service!" << std::endl;
}

EXPORT
void setLightMode(bool value)
{
	headUnitService->setLightModeAttribute(value);
}

EXPORT
void setUnit(const char* unit)
{
	headUnitService->setUnitAttribute(unit);
}

EXPORT 
void setMetaData(const uint8_t* _image, int length, const char* artist, const char* title)
{
	HeadUnit::MetaData metadata;
	std::vector<uint8_t> image(_image, _image + length);
	metadata.setAlbumcover(image);
	metadata.setArtist(artist);
	metadata.setTitle(title);
	headUnitService->setMetadataAttribute(metadata);
}
