### Stream Decoder: Frame Selector
##### Summary: 
This module is a demonstration of reading the protobuf files out of a .hdf5 file.
It takes a .hdf5 file and can read the dataset with the protobuf file ids and timestamps of the images in the video, the description attribute and all protobuf files.

##### Run: 
To read all protobuf files from a .hdf5 file:

$ ./frameselector HDF5FILE

Or to read one protobuf file at a given index from a .hdf5 file: 

$ ./frameselector HDF5FILE protobuf_file_index
