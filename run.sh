chpl -o demo.good demo.chpl  -I/Users/Ajay/anaconda/include -L/Users/Ajay/anaconda/lib -lhdf5 -lhdf5_hl

./demo.good --n=10 --fileName=Sample.h5

h5dump Sample.h5
