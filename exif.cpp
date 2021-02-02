#include <exiv2/image.hpp>
#include <iostream>

int main() {
  std::string exifPath = "/home/nvidia/exiv2/exiv_test/S_27.jpg";

  std::string logTime = "1991:01:05 10:31:25";

  auto v = Exiv2::Value::create(Exiv2::asciiString);
  v->read(logTime);
  Exiv2::ExifKey key("Exif.Photo.DateTimeOriginal");
  Exiv2::ExifData exif0;
  exif0.add(key, v.get());
  auto image1 = Exiv2::ImageFactory::open(exifPath);
  image1->setExifData(exif0);
  image1->writeMetadata();
}
