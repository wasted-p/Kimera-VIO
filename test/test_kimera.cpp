#include <kimera-vio/pipeline/RgbdImuPipeline.h>

int main() {
  using namespace VIO;

  std::string params_folder_path = "../params/Euroc"; // replace with your own
  std::string sensor_folder_path = "../params/Euroc";
  auto vio_params = VioParams(params_folder_path, sensor_folder_path);

  auto pipeline = std::make_shared<RgbdImuPipeline>(vio_params);
  pipeline->spin(); // or pipeline->spinOnce() or pipeline->shutdown()

  return 0;
}
