use h5chpl;
config const  n = 14;
config const  fileName = "Sample.h5";

// some square from 1 to n of the matrix
var oneDimMatrix: [1..n] int;
forall i in {1..n} do
    oneDimMatrix(i) = i*i; //Filling Squares 

// test
var file = new hdf5(fileName);
file.create();
file.writeMatrix(oneDimMatrix,n);
