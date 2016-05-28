### Stream Decoder: Frame Selector
##### Summary: 
This module is a demonstration of reading the protobuf files out of a .hdf5 file.
It takes a .hdf5 file and can read the dataset with the image ids and timestamps of the images in the video, the description attribute and all protobuf images.

##### Run: 
To read all protobuf images from a file:

$ ./FrameSelector HDF5FILE

Or to read one protobuf image at a given index from a file: 

$ ./FrameSelector HDF5FILE image_index
