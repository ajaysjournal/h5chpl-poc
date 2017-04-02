// external c source
// todo - try extern {} block
require "HDF5Main.h", "HDF5Main.c";
// External c funnction to create the new HDF5 file using HDF$ source
extern proc __create(fileName:c_string);

//External c funnction to write a 1-dimenstion matrix .
extern proc __writeMatrix(fileName:c_string,  m: [] int,length: int);

class hdf5 {
  // file name
  var name;
  proc create() : void {
    __create(name.c_str());
  }
  proc writeMatrix(m: []int, size: int) {
    __writeMatrix(name.c_str(), m, size);
 }
}
