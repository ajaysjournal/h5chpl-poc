#include <stdlib.h>
#include "hdf5.h"
#define DATASETNAME "/myDataSet"

// creates an empty HDF5 file
void __create(const char* fileName) {
  H5Fclose(H5Fcreate(fileName, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT));
}

//Write 1-dimenstion matrix to HDF5
void __writeMatrix(const char* fileName, int64_t* matrix, int64_t length) {

   hid_t       file_id, dataset_id,dataspace_id;
   herr_t      status;
   hsize_t     dims[2];
   dims[0] = 1;
   dims[1] = length;

   /* Open an existing file. */
   file_id = H5Fopen(fileName, H5F_ACC_RDWR, H5P_DEFAULT);

   dataspace_id = H5Screate_simple(2, dims, NULL);

   /* Open an existing dataset. */
   dataset_id = H5Dcreate2(file_id, DATASETNAME, H5T_STD_I32BE, dataspace_id,
                          H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

   /* Write the dataset. */
   status = H5Dwrite(dataset_id, H5T_NATIVE_ULLONG, H5S_ALL, H5S_ALL, H5P_DEFAULT,
                     matrix);

   status = H5Dread(dataset_id, H5T_NATIVE_ULLONG, H5S_ALL, H5S_ALL, H5P_DEFAULT,
                    matrix);

   /* Close the dataset. */
   status = H5Dclose(dataset_id);

   /* Close the file. */
   status = H5Fclose(file_id);
}
