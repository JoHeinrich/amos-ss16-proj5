#### StreamDecoder Software module Documentation


##### FrameSelector
The complete pipeline of reading and decoding images from a .hdf5 file is the following:

> File.hdf5 -> HDFReader -> Imagebuffer -> ProtobufDeserializer -> Image

###### Functions overview
| Function        | Description        | 
| ------------- |-------------  |
| FrameSelector::FrameSelector(std:string file)| This is the constructor. It takes a full path of a file to read from this .hdf5 file. <br><br> @param file The full path of the .hdf5 file |
| void readImage(unsigned int frameIndex)| This functions reads one image at the given index from the .hdf5 file and deserializes this image. <br><br>  @param frameIndex The index of the image  |
| void readAllImages()|This functions reads and deserializes all the images in the given .hdf5 file.  |
