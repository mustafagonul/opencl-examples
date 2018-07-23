#include <iostream>
#ifdef __APPLE__
  #include <OpenCL/cl.hpp>
#else
  #include <CL/cl.hpp>
#endif

int main()
{
  // get all platforms (drivers)
  std::vector<cl::Platform> platforms;
  cl::Platform::get(&platforms);

  if (platforms.size() == 0) {
      std::cout << " No platforms found." << std::endl;
      return 0;
  }

  for (auto& platform : platforms) {
    std::cout << platform.getInfo<CL_PLATFORM_NAME>() << std::endl;
  }

  return 0;
}

  /*
  cl::Platform default_platform = platforms[0];
  std::cout << "Using platform: " << default_platform.getInfo<CL_PLATFORM_NAME>()<<"\n";

  // get default device (CPUs, GPUs) of the default platform
  std::vector<cl::Device> all_devices;
  default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
  if(all_devices.size()==0){
      std::cout<<" No devices found. Check OpenCL installation!\n";
      exit(1);
  }

  // use device[1] because that's a GPU; device[0] is the CPU
  cl::Device default_device=all_devices[1];
  std::cout<< "Using device: "<<default_device.getInfo<CL_DEVICE_NAME>()<<"\n";
  */